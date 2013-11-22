/************************************************************
 *
 *  OTNewcli  -- Open Transactions new command line interface
 *  (including parts like othint, some util libs, and more)
 *
 * 	Written in 2013 by rfree (rfree@gmx.us) and other members of
 * 	open-source community.
 *
 * 	To the extent possible under law, the author(s) have dedicated all
 * 	copyright and related and neighboring rights to this software to
 * 	the public domain worldwide. This software is distributed without
 * 	any warranty.
 *
 * 	You should have received a copy of the CC0 legalcode along with this
 * 	work (COPYING file). If not, see:
 * 	http://creativecommons.org/publicdomain/zero/1.0/
 *
 * 	OTNewcli is developed as a part of OPEN TRANSACTIONS project
 *
 * 	Where applicable (under given jurisdiction's law system),
 * 	we want to give away our code as CC0 (Creative Commons 0);
 * 	However, some parts of code might be not fully ours to licence/decide
 * 	(from point of view of given law system),
 * 	because they are connecting to other work in some ways.
 *
 * 	In any such unclear cases, the general Open Transaction licence as
 * 	published by FellowTraveller on GitHub should be applied if possible
 * 	(because it clarifies how to deal with linking to work like Lucre code,
 * 	OpenSSL code, and so on).
 *
 * 	We also allow this code to be released to Public Domain, but again,
 * 	we do not verify how is that possible in given law system.
 *
 * 	In ANY CASE, we take absolutely NO legal responsibility about
 * 	licensing, sharing, using this code (nor patent nor copyright nor
 * 	any other law related issues that it might have) e.g. in your	country.
 *
 * 	We are not lawyers, and it is up to only You to find out what
 * 	laws apply for your case. Do not use any of this code if you don't
 * 	agree.
 *
 * 	PROJECT GIT REPOSITORY:
 * 	https://github.com/rfree/Open-Transactions/
 *
 ***********************************************************************
 * 	OPEN TRANSACTION RELATED INFORMATIONS: (copy pasted for information)
 ***********************************************************************
 *                    OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 * 	BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  OFFICIAL OPEN TRANSACTIONS PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 **************************************************************/



/**

OT Hints (new CLI - new commandline : auto complete commands, verify, check, etc)

Goal: this project aims to provide auto completion of newCLI OT commands, see [Description_of_auto_completion]
Description: See [Description_of_auto_completion] below
Example: "ot msg send bob a<TAB>" will ask remote OT and auto-complete alice.

Usage:
	./othint --complete-one "ot msg send ali"
	./othint --one "ot msg send ali"
	./othint --complete-shell
	./othint --shell
	./othint --devel # test various things etc

This subproject is separated out of OT, and uses C++11 and few other modern coding style changes.

Rules of language: use C++11, do not use boost (thoug we could copy small part of boost source code if needed,
or headers-only library)

Currently this is developed rapidly as 1 big file, to be splited soon, composed of this parts:
- nExamplesOfConvention - documenation of coding style convention
- nOT::nUtil - various utils for modern (C++11) OT ; ToStr(), OT_CODE_STAMP
- nOT::nNewcli - new command line classes, to parse the command line options, and to execute commands
- nOT::nOTHint - new command line auto-completion. Move here things usable only for auto-completion and nothing else
- nOT::nTests - the testcases for our code
- main() is here

Coding rules:
- testcase driven development
- testcase on almost each compilation, commit often
- secure - use asserts, secure methods, etc. Use static analysis
- fast - optimize for speed overall, and in picked bottlenecks
- scalable - assume usage in massive scripts one day, e.g. 1 million users email server :)
- document all conventions, all code; Entire WG (working group) must know all of them
- flexible - easy to tune, to extend, in object-oriented way

File format of sources: identation with \t char, which we assume is 2 spaces wide. Unicode, UTF-8.

*/

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <iterator>
#include <stdexcept>

// for the super advanced trim ;)
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

#include <string.h>

// detecting and including proper version of readline or it's replacement
#ifndef CFG_USE_READLINE // should we use readline?
	#define CFG_USE_READLINE 1 // default
#endif

#if CFG_USE_READLINE
	#ifdef __unix__
		#ifdef OT_ALLOW_GNU_LIBRARIES
			// #include <readline/readline.h> // GNU Readline
			// #include <readline/history.h>
			// #define LIBRARY_STATUS_READLINE 1
			// #define LIBRARY_STATUS_READLINE_KIND "gnu readline"
			// #define LIBRARY_STATUS_READLINE__S "Included"
		#else
			// #define LIBRARY_STATUS_READLINE 0
			// #define LIBRARY_STATUS_READLINE__S "Disabled, because GNU was disabled at compilation time (readline requires GPL licence)"
		#endif
		#include <editline/readline.h> // apt-get install libedit-dev
		#include <editline/history.h>
		#define LIBRARY_STATUS_READLINE 1
		#define LIBRARY_STATUS_READLINE_KIND "editline"
		#define LIBRARY_STATUS_READLINE__S "Included"
	#else // not unix
		#define LIBRARY_STATUS_READLINE 0
		#define LIBRARY_STATUS_READLINE__S "Disabled because this was not a UNIX compatible compilation (TODO: do support MinGWEditline for windows)"
	#endif // not unix
#else // not use readline
	#define LIBRARY_STATUS_READLINE 0
	#define LIBRARY_STATUS_READLINE__S "Disabled at compile option"
#endif // not use readline

// OTNewcliCmdline

// list of thigs from libraries that we pull into namespace nOT::nNewcli
// we might still need to copy/paste it in few places to make IDEs pick it up correctly
#define OT_COMMON_USING_NAMESPACE_1 \
using std::string; \
using std::vector; \
using std::list; \
using std::set; \
using std::map; \
using std::unique_ptr; \
using std::cin; \
using std::cerr; \
using std::cout; \
using std::cerr; \
using std::endl; \

#define OT_COMMON_USING_NAMESPACE \
	OT_COMMON_USING_NAMESPACE_1 \
	using nOT::nUtil::ToStr;

// Please read and follow this syntax examples:
namespace nExamplesOfConvention {
// Welcome, to the world of C++11 !

int gGlobalVariable; // g - global variable

class cFooBar {
private:
	static int sStaticVariable; // s - static variable

	int mFooBarBaz; // m - variable, member of class

	int Fooberize();
	int DerpTheHerp();

public:
	cFooBar(int x)
	: mFooBarBaz(x)
	{}

	inline int Foo() {
		int abc=42;
		return abc;
	}
};
int cFooBar::sStaticVariable = 0;

// In case of simple parameters, we can skip "m" prefix. In this case:
struct cSimpleParam {
	int x;
	int y;

	cSimpleParam(int x, int y)
	: x(x), y(y)
	{}
};


} // namespace

// #####################################################################
// #####################################################################
// #####################################################################
// Utilities - various utils that are used in OT (but don't have to be related to OT)

extern std::string GetObjectName_global_string; // extern to h
std::string GetObjectName_global_string="(global)"; // definition/initialization
std::string GetObjectName() {	return GetObjectName_global_string; }

#define OT_CODE_STAMP ( ToStr("[") + ToStr(__FILE__) + ToStr(" +") + ToStr(__LINE__) + ToStr(" as ") + ToStr(__FUNCTION__) + (" of ") + ToStr(GetObjectName() + ToStr("]")) )

// TODO: move to utils
namespace nOT {
namespace nUtil {

OT_COMMON_USING_NAMESPACE_1;

class cLogger {
};

template <class T>
std::string ToStr(const T & obj) {
	std::ostringstream oss;
	oss << obj;
	return oss.str();
}

template <class T>
void DisplayVector(std::ostream & out, const std::vector<T> &v, const std::string &delim=" ") {
	std::copy( v.begin(), v.end(), std::ostream_iterator<T>(out, delim.c_str()) );
}

template <class T>
void DisplayVectorEndl(std::ostream & out, const std::vector<T> &v, const std::string &delim=" ") {
	DisplayVector(out,v,delim);
	out << std::endl;
}

template <class T>
void DBGDisplayVector(const std::vector<T> &v, const std::string &delim=" ") {
	std::copy( v.begin(), v.end(), std::ostream_iterator<T>(std::cerr, delim.c_str()) );
}

template <class T>
void DBGDisplayVectorEndl(const std::vector<T> &v, const std::string &delim=" ") {
	DBGDisplayVector(v,delim);
	std::cerr << std::endl;
}

bool CheckIfBegins(const std::string & beggining, const std::string & all) {
	if (all.compare(0, beggining.length(), beggining) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

vector<string> WordsThatMatch(const std::string & sofar, const vector<string> & possib) {
	vector<string> ret;
	for ( auto rec : possib) { // check of possibilities
		if (CheckIfBegins(sofar,rec)) ret.push_back(rec); // this record matches
	}
	return ret;
}

char GetLastChar(const std::string & str) { // TODO unicode?
	auto s = str.length();
	if (s==0) throw std::runtime_error("Getting last character of empty string (" + ToStr(s) + ")" + OT_CODE_STAMP);
	return str.at( s - 1);
}

std::string GetLastCharIf(const std::string & str) { // TODO unicode?
	auto s = str.length();
	if (s==0) return ""; // empty string signalizes ther is nothing to be returned
	return std::string( 1 , str.at( s - 1) );
}

// TODO --- Vvvv  and #include
// trim from start
std::string &ltrim_in_place(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// trim from end
std::string &rtrim_in_place(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

/*// trim from both ends
std::string &trim_in_place(std::string &s) {
	return ltrim(rtrim(s));
}*/

std::string rtrim(const std::string &s) {
	string scopy = s;
	rtrim_in_place(scopy);
	return scopy;
}
// TODO ltrim trim

// ASRT - assert. Name like ASSERT() was too long, and ASS() was just... no.
// Use it like this: ASRT( x>y );  with the semicolon at end, a clever trick forces this syntax :)
#define ASRT(x) do { if (!(x)) Assert(false, OT_CODE_STAMP); } while(0)

void Assert(bool result, const std::string &stamp) {
	if (!result) throw std::runtime_error("Assert failed at "+stamp);
}

namespace nOper { // nOT::nUtil::nOper
// cool shortcut operators, like vector + vecotr operator working same as string (appending)
// isolated to namespace because it's unorthodox ide to implement this

using namespace std;

// TODO use && and move?
template <class T>
vector<T> operator+(const vector<T> &a, const vector<T> &b) {
	vector<T> ret = a;
	ret.insert( ret.end() , b.begin(), b.end() );
	return ret;
}

template <class T>
vector<T> & operator+=(vector<T> &a, const vector<T> &b) {
	return a.insert( a.end() , b.begin(), b.end() );
}

} // nOT::nUtil::nOper

} // nUtil
} // nOT

// ====================================================================

// TODO: move to own file
namespace nOT {
namespace nNewcli {

// list of thigs from libraries that we pull into namespace nOT::nNewcli
using std::string;
using std::vector;
using std::list;
using std::set;
using std::map;
using std::unique_ptr;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using nOT::nUtil::ToStr;

/*

[Description_of_auto_completion]

=== Introduction ===

First an advance example of magic of OT hints:
  ot msg send bob al<TAB>
will auto-complete options:
  alice alex alcapone
In this situation, bash autocomplete with othint program
will query the OT server to list your contacts named al...

With respecting your privacy, trying to use remote server only if
data was not cached, and only asking servers that you trust (the --HT option)
that is the default. Start with "ot --H0" to make sure there will be 0 network
activity, no servers will be asked:
  ot --H0 msg send bob a<TAB>
will auto-complete with data that can be given without causing network traffic.

ot_secure:
If it's more convinient, we might provide separate command: "ot_net", "ot_secure"
with other level of discretion in the hinting process as well with say more
confirmations when also EXECUTING a command that will connect to OT server.
  ot_quiet mint spawn bob silve<TAB>
	1. will NOT ask any server about the list of currenies silve... will use cache
		silvergrams silvertest silverbob {showing only cached data, last update 3h ago}
	2. when the command is finished and executed as
	  ot_quiet mint spawn bob silvergrams 1000<ENTER>
	it will ask: "Please confirm do you want to connect NOW to OT server aliased BigTest1,
	with ID=855gusd2dffj2d9uisdfokj233 (unknown/new server), and execute
	mint-spawn command? Type 2 words: 'unknown spawn' to confirm, or 'no'"

Also name alice is in front (instead alphabet sorting) since it was recently/frequently used.

All OT commands will be neatly supported in this way.


=== Commands are in form ===

ot [front1,front2...] topic action [--subact] var1,...  [varM,...] [--optNameN[=[optArgN]]...]

ot <-front options--> <- cCmdname ----------> <---- arguments ------------------------------->
ot                    <- cmd name ----------> <---- vars -----> <-- options ----------------->
ot <--- optional ---> <- mandatory-------------------> <--- optional ------------------------>
ot <-- cmdFrontOpt -> <- cmdPart -----------> <-------------- cmdArgs ----------------------->

Examples:
ot  --H0              msg   send              bob a
ot                    msg   send              bob alice            --attach scan.jpeg
ot                    msg   send              bob alice carol      --attach scan.jpeg
ot                    msg   send              bob alice carol      -v -v -v
ot  --hint-private    msg   send              bob alice carol      -v -v -v
ot  --hint-cached     msg   send              bob alice carol      -v -v -v
ot  --hint-cached     msg   help

Examples of SYNTAX ERRORS:
ot                    msg                     bob  alice # missing subcommand
ot                    msg   send              bob  # requires at least 2 arguments(*)
ot                    msg   send              bob  alice           --date=now --date=0 # date is unique
ot                    msg   send              bob  --hint-cachead=0 # forward command must be in font

(*) possibly such errors will instead allow execution and have the program interactivly ask for missing mandatory vars.

Therefore the syntax is:
[front-options] 2 words of command name, 0..N mandatory variables, 0..M extra variables, any options

	- subaction will be probably not used but leaving such possibility, then it would be 2..3 words

ARGUMENTS:
	- front-options are special options that must appear in front because they change meaning/parsing
		of everything next - particullary, auto-completion options. Read section [front-options] for details

	- Arguments available depend on the command name.

	- Options for command depend on the command name, as well are imported from global.

	- Options can't be placed before variables!

	- Options can be unique or can repeat. Options can have no value/data,
		or can have one.This gives 2*2 = 4 kinds of options: uniq, uniqData,
		repeat, repeatData.

	- Options can be both global and comming from selected action/subaction.

SEE testcases below in functions

#----------------Errors------------------#
msg     # error: incomplete action
msg send     # error: missing required options
msg send <mynym>     # error: missing required options
#----------------Errors------------------#

#------List of all included commands-----#
account			# can display active (default) account
account ls			# list all accounts
account new			# make new account with UI
account new <assetID>			# make new account by giving only <assetID>...
account new <assetID> <accountName>			#... and <accountName>
account refresh			#	refresh database of private accounts' list
account-in ls			# for active account
account-in ls <accountID>			# for specific <accountID>
account-in accept <paymentID>				#	accept this particullar payment
account-in accept --all			# accept all
account-out ls
asset				# can display active (default) asset
asset new 	# change to issue?
asset new <assetName>			# set new asset with given <assetName>
basket new
basket ls
basket exchange
cash send <mynym> <hisnym>
cheque new
contract new
contract get <contractID>
contract sign
market
market ls
mint new
msg			# should show what options do you have with this topic
msg send		# should ask you about nyms ?
msg send <mynym> 		# should take your nym and ask about addressee's name
msg send <mynym> <hisnym> 		# an example of usage
msg send <mynym> <hisnym> --push     		# global option
msg send <mynym> <hisnym> --no-footer     # action option
msg send <mynym> <hisnym> --cc <ccnym>     # action option with value
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2>
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2> --push  	 # example of force send (?) - not sure if it will appear
msg ls			# list all messages
msg mv			# move message to different directory in your mail box
msg rm <index>		# remove message with <index> number
msg rm --all		# remove all messages from mail box
msguard info   # test, imaginary comand "msguard" (microsoft guard) info - shows windows firewall status for OT tcp
msguard start
msguard stop
nym 			# can display active (default) nym
nym ls			# list of all nyms
nym new			# make new nym with UI (it should ask potential user to give the name
nym new <name>			# make new nym by giving name without UI
nym rm <name>			# remove nym with such <name>
nym rm <nymID>		# remove nym with such <nymID>
nym info <nymID>		# show information about such <nymID>
nym edit <nymID>		# allows to edit information about such <nymID>
nym register <nymID> <serverID>			# register this specific <nymID> to specific <serverID> server
nym import		# import saved (somewhere?) nyms
nym export		# export nyms to (outerspace) :) ?
nym check <nymID>			# returns Public Key of this <nymID> nym
nym refresh			# refresh nym's list and its included informations
nym-cred new 			# change credential to trust?
nym-cred revoke
nym-cred show			# show all credential to trust?
receipt?
server			# can display active (default) server
server ls			# as above but all servers are listed
server add		# add new server
server new 	# like newserver
text encode
text decode
voucher new
wallet? status
#------List of all included commands-----#

That's all commands included to OTHint for now.
(?) means that we're not sure if it will appear in main program, those keywords are implemente but commented for now

------------------------------------------------------------------------
older opentxs commands:

acceptall	acceptinbox	acceptinvoices	acceptmoney
acceptpayments	acceptreceipts	accepttransfers	addasset
addserver	addsignature	balance		buyvoucher
cancel		changepw	checknym	clearexpired
clearrecords	confirm		credentials	decode
decrypt		delmail		deloutmail	deposit
discard		editacct	editasset	editnym
editserver	encode		encrypt		exchange
expired		exportcash	exportnym	getboxreceipt
getcontract	getmarkets	getmyoffers	getoffers
importcash	importnym	inbox		issueasset
killoffer	killplan	mail		newacct
newasset	newbasket	newcred		newkey
newnym		newoffer	newserver	outbox
outmail		outpayment	pass_decrypt	pass_encrypt
paydividend	payinvoice	payments	propose
records		refresh		refreshacct	refreshnym
register	revokecred	sendcash	sendcheque
sendinvoice	sendmsg		sendvoucher	showaccounts
showacct	showassets	showbasket	showcred
showincoming	showmarkets	showmint	showmyoffers
shownym		shownyms	showoffers	showoutgoing
showpayment	showpurse	showservers	sign
stat		transfer	trigger		verifyreceipt
verifysig	withdraw	writecheque	writeinvoice
------------------------------------------------------------------------

[front-options] usage is for example:
If you type -HN in front of options, then Hints will use Network (-HN) to autocomplete, typing
ot -HN msg send myuser1 bo<TAB> will e.g. ask OT server(s) (e.g. over internet) about you address book
ot -HT msg send myuser1 bo<TAB> the same but for Trusted servers only (will not accidentially talk to other servers)
ot -H0 .... will make sure you will not ask OT servers, just use data cached
ot -HR .... will force othint to refresh all information from servers. Option useful if you want fresh information from servers in real time. Slow and dagerous for privacy.

The exact planned options are 2 settings: accessing remote and accessing cache.
	--hint-remote=V set's the privacy to level 0..9. 0=never ask remote severs for data needed for
	this autocompletion, 9 freely ask (less secure, because remote server see that we compose a command).
	1=local server (e.g. localhost that was marked as trusted)
	3=trusted servers (e.g. several servers you configure as trusted)
	5=uses network (all servers) but might avoid some really sensive data
	9=you fully ask the server owners and consent to possiblity of them (or their ISP, hosting) learning
	what you are planning to do

	--hint-cached=V set's the usage of cached data. 0=revalidate now all data from server.
	5=normal reasonable use of cache
	8=only cached data, unless we have no choice, 9=only cached data even if it causes an error

--hint-remote=0 implies --hint-cached=9 as we are not allowed to touch remote server at all
--hint-cached=0 implied --hints-remote=0 as we are ordering to touch remote server so we are not working in private mode

--hint-remote=0 --hint-cached=0 is disallowed syntax,
even though some commands that indeed do not need neither cached nor remote data could work,
like "ot --hint-remote=0 --hint-cached=0 msg help"
or "ot --hint-remote=0 --hint-cached=0 msg draft"
but for clarity it will be an error because likelly someone confused the options.
But then, --hint-allow-strange option will allow such syntax, if it appears in front of option causing this
contradiction.
E.g. this is allowed syntax:
ot --hint-allow-strange --hint-remote=0 --hint-cached=0 msg draft

Shortcuts:
--H0 gives hints offline        equals --hint-offline     equals --hint-remote=0 --hint-cached=9
--HL gives hints local          equals --hint-local       equals --hint-remote=1 --hint-cached=5
--HT gives hints trusted        equals --hint-trusted     equals --hint-remote=3 --hint-cached=5
--HN gives hints from network   equals --hint-net         equals --hint-remote=5 --hint-cached=5
--HR is forced net reload       equals --hint-reload      equals --hint-remote=9 --hint-cached=0
--HV gives VPNed network        equals --hint-vpn         equals --vpn-all-net --hint-remote=9 --hint-cached=5

VPN:
option --vpn-all-net will force hint autocompletion (and also the actuall commands, unless later
canceled with other options) to use only VPN or similar secure networking. Details will be
configured, it could be e.g. a VPN network, or possibly other secured (private) network facility.
It is guarnateed that if such secure network fails to work, then no network will be touched
and program will not leak any activity to open network (LAN, Internet, etc)
--HV might be most comfortable and yet quite secure option, usable e.g. from hotels.

VPN forced:
Global configuration option could force to always use VPN (append --vpn-all-net)
then use "ot --HN" will not auto-complete on <TAB> but show:
  {can not use --HN because your configuration disabled it, please try --HV}
and if executed as full command, will also refuse to work, with explanation.

Please remember that VPNs or even more advanced solutions are not that secure, and that
ot hint sends anyway lots of data of intended action, with timing correlation, to the OT server
in --HV case.
VPN only hides your IP a bit.
Full caching with --H0 or --HL is most secure, there is no home like localhost :)

*/


// more rich information about a nym
class cNyminfo {
	public:
		cNyminfo(std::string name);

		operator const std::string&() const;

	public:
		string mName;
		int mScore;
};

cNyminfo::cNyminfo(std::string name)
: mName(name), mScore(0)
{ }

cNyminfo::operator const string&() const {
	return mName;
}


class cCmdname { // holds (2)-part name of command like "msg","send"
	// represents name of one command, including the (1)-2-3 components e.g. msg,send or msg,export,msg
	// "msg send"
	// "msg list"
	// "msg export msg"
	// "msg export all"
	// "msg" (not a valid command, will be used with null_function, is just to provide global options to inherit)

	protected:
		const string mTopic;
		const string mAction;
		const string mSubaction;

	public:
		cCmdname(const string &topic, const string &action, const string &subaction);
};

cCmdname::cCmdname(const string &topic, const string &action, const string &subaction)
:mTopic(topic), mAction(action), mSubaction(subaction)
{
}


/*
Build:
Tree of max options:
[msg] ---------> { --unicode }
[msg send] ----> (2) + (3) + {--now,--later,--sign,--red} , msg_send_complete()

msg_send_complete() {
	if (stage==arg) { if (arg_pos==1) get_my_nyms();    if (arg_pos==2) get_your_nyms(); }
	else if (stage==extra) { ... }
	else if (stage==option) {
		foreach (opt) ..
			if (--now) delete --later;
			if (uniq) delete this_option;
		} // existing options eliminate possibilities
		if (half_world) finish_option( remaining_options );
		else show_other_options();
	}
}
*/


/*
class argument_info {
	// class says what kind of argument is this i.e. that argument is "mynym" and it have to be string or integer or only boolean
	// and provide class!!! for auto complete

	string mName; // "mynym" "hisnym" (even those arguments which have specific order, so they don't have "name", will have, for example for generating help text

	// other mName will be for eg. "cc"  for option --cc which remain name

};
*/

/*
typedef string argument_data ; // for now...

class cCmdoptions {

		// required arguments
		vector< argument_info > // here should be { ("msg","send")  ,  ("msg","send","body") ect. same as in cCmdname::returnStandard

		map< argument_info , vector< argument_data > > // here will be map
}

class cCmdlineInfo {
	public:
	protected:
		vector<cCmdname> mPossible; // store here possible command names
		map<cCmdname , details_of_command> mPossibleDetails;
};
*/



} // namespace nNewcli
} // namespace nOT
// ########################################################################
// ########################################################################
// ########################################################################


namespace nOT {
namespace nTests {

OT_COMMON_USING_NAMESPACE

using namespace nOT::nUtil;

struct cTestCaseCfg {
	std::ostream &ossErr;
	bool debugActive;

	cTestCaseCfg(std::ostream &ossErr, bool debugActive)
	: ossErr(ossErr) , debugActive(debugActive)
	{ }
};

bool testcase_run_all_tests();

int main_start(int argc, char **argv); // some tests will execute the main... e.g. against errors in args parsing TODO move to namespace

bool testcase_complete_1(const std::string &sofar); // TODO ... testcase or really used???
bool testcase_complete_1_wrapper(); // TODO ... testcase or really used???

typedef bool ( * tTestCaseFunction )(const cTestCaseCfg &) ;
// ^- tTestCaseFunction is a function:  bool ....(const cTestCaseCfg &)

} // nTests
} // nOT

// TODO: move to own file
namespace nOT {
namespace nOTHint {

// list of thigs from libraries that we pull into namespace nOT::nNewcli
using std::string;
using std::vector;
using std::list;
using std::set;
using std::map;
using std::unique_ptr;
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

using namespace nOT::nUtil;
using namespace nOT::nUtil::nOper; // vector + vector and other shortcut operators. It's appen, as in strings! :)

// Data for hinting, e.g. cached or local information.
class cHintData {
	public:
		vector<nNewcli::cNyminfo> mNymsMy;
		vector<string> mNymsMy_str; // TODO optimize/share memory? or convert on usage

		bool mNymsMy_loaded;

		cHintData();

		const vector<string> getNymsMy();
};

cHintData::cHintData()
: mNymsMy_loaded(false)
{
}


const vector<string> cHintData::getNymsMy() {
	if (!mNymsMy_loaded) {
		try {
			mNymsMy_loaded=0; // to mark that we start to delete data/data is inconsistent
			mNymsMy.clear();
			mNymsMy_str.clear();

			ifstream plik("nyms.txt");
			long int sum=0, count=0;
			while (plik.good() && (!plik.eof())) {
				string name;  double score;
				plik >> name >> score;
				nNewcli::cNyminfo nym(name);
				nym.mScore=score;
				mNymsMy.push_back( nym );
				sum+=score; ++count;
			}
			double avg = sum/double(count);

			for (auto nym_info: mNymsMy ) {
				if (nym_info.mScore > avg/2) {
					//cerr << nym_info.mScore << " vs " << avg/2 << endl;
					mNymsMy_str.push_back( nym_info );
				}
			}
		}
		catch(...) { }
		mNymsMy_loaded = true;
	}
	return mNymsMy_str;
}






// ====================================================================

// The Manager to access OT-hint (autocompletion) functionality
class cHintManager {

	public:
		cHintManager();

		vector<string> AutoComplete(const string &sofar_str) const; // the main function to auto-complete. The command line after "ot ", e.g. "msg send al"
		vector<string> AutoCompleteEntire(const string &sofar_str) const; // the same, but takes entire command line including "ot ", e.g. "ot msg send al"

	protected:
		vector<string> BuildTreeOfCommandlines(const string &sofar_str, bool show_all) const; // return command lines tree that is possible from this place
		unique_ptr<cHintData> mHintData;
};

cHintManager::cHintManager()
: mHintData(new cHintData)
{ }

vector<string> cHintManager::AutoCompleteEntire(const string &sofar_str) const {
	const std::string cut_begining="ot"; // minimal begining
	const int cut_begining_size = cut_begining.size();
	if (sofar_str.length() < cut_begining_size) return WordsThatMatch(sofar_str, vector<string>{ cut_begining }); // too short, force completio to "ot"

	std::string ot = sofar_str.substr(0,cut_begining_size); // separate out the part that is know to has correct size and should be "ot"
	if (ot!=cut_begining) return vector<string>{}; // nothing matches, not command ot...

	// TODO optimize, avoid copy?
	std::string line = sofar_str;
	line.erase(0, cut_begining_size);

	return AutoComplete(line);
}

vector<string> cHintManager::AutoComplete(const string &sofar_str) const { // the main function to auto-complete
	// cerr << "COMPLETE for sofar=[" << sofar_str << "]." << endl;
	auto possible = BuildTreeOfCommandlines(sofar_str,false);
//	DBGDisplayVectorEndl(possible);
	return possible;
}

vector<string> cHintManager::BuildTreeOfCommandlines(const string &sofar_str, bool show_all) const {
/*
	nOT::nNewcli::cNew newcli;
	newcli.assign(sofar_str);
	newcli.parse();

}
*/
	bool dbg = false;
	std::istringstream iss(sofar_str);
	vector<string> sofar { std::istream_iterator<string>{iss}, std::istream_iterator<string>{} };
	// ^-- fine for now, but later needs to take into account "..." and slashes etc... use boost option? -- yes? TODO test

	// exactly 2 elements, with "" for missing elements
	decltype(sofar) cmdPart;
	decltype(sofar) cmdArgs;
	if (sofar.size()<2) {
		cmdPart = sofar;
	}
	else {
		cmdPart.insert( cmdPart.begin(), sofar.begin(), sofar.begin()+2 );
		cmdArgs.insert( cmdArgs.begin(), sofar.begin()+2, sofar.end() );
	}
	while (cmdPart.size()<2) cmdPart.push_back("");
	if (dbg) DBGDisplayVectorEndl(cmdPart,",");

	if (GetLastCharIf(sofar_str)==" ") {
		if( sofar.size()>=1 ) { // if there is any last-word element:
			sofar.at( sofar.size()-1 )+=" "; // append the last space - to the last word so that we know it was ended.
		}
	}

	const vector<string> cmdFrontOpt = {"--H0","--HL","--HT","--HV","--hint-remote","--hint-cached","--vpn-all-net"};
	const vector<string> all_topics = {"msg","msguard","nym"};

	const string topic  =  cmdPart.at(0) ;
	const string action =  cmdPart.at(1) ;

	int full_words=0;
	int started_words=0;

	bool last_word_pending=false;
	size_t nr=0;
	for (auto rec : sofar) {
		if (rec!="") started_words++;
		if (last_word_pending) { full_words++; last_word_pending=0; }
		if (GetLastCharIf(rec)==" ") full_words++; else last_word_pending=1; // we ended this part, without a space, so we have a chance to count it
		// still as finished word if there is a word after this one
		++nr;
	}
	string current_word="";
	if (full_words < started_words) current_word = sofar.at(full_words);
	if (dbg) { cerr << "full_words=" << full_words << " started_words="<<started_words
		<< " topic="<<topic << " action="<<action
		<< " current_word="<<current_word << endl;
	}

	// TODO produce the object of parsed commandline by the way of parsing current sofar string
	// (and return - via referenced argument)

	// * possib variable - short for "possibilities"

	// TODO support discarding forward-opion flags
	// ...

	// === at 1st (non-front-option) word (topic) ===

	if (full_words<1) { // at 1st word (topic) -> show all level 1 cmdnames

		return WordsThatMatch(  current_word  ,  vector<string>{"account", "account-in", "account-out", "asset", "basket", "cash", "cheque", "contract", "market", "mint", "msg", "msguard", "nym", "nym-cred", /*"receipt"??,*/ "server", "text", "voucher"/*, "wallet"??*/} + cmdFrontOpt  ) ;
		//commented procedures are those which we ain't sure if they will appear - definitions below
	}

	// === at 2nd (non-forward-option) word (action) ===

	if (topic=="account") {
		if (full_words<2) { // we work on word2 - the action:
			return WordsThatMatch(  current_word  ,  vector<string>{"new", "refresh", "ls", "[BLANK]"} ) ;
		}
		if (full_words<3) { // we work on word3 - var1
			if (action=="new") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<assetID>"} ) ;
			}
		}
		if (full_words<4) { // we work on word4 - var2; this one have to get "assetID" variable from otlib
			if (cmdArgs.at(0)=="<assetID>") {
	     	return WordsThatMatch(  current_word  ,  vector<string>{"<accountname>"} ) ;
			}
		}
	}

	if (topic=="account-in") {
		if (full_words<2) { // we work on word2 - the action:
			return WordsThatMatch(  current_word  ,  vector<string>{"accept", "ls"} ) ;
		}
		if (full_words<3) { // we work on word3 - var1
			if (action=="accept") {
				return WordsThatMatch(  current_word  ,  vector<string>{"--all", "<paymentID>"} ) ;
			}
			if (action=="ls") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<accountID>"} ) ;
			}
		}
	}

	if (topic=="account-out") {
		return WordsThatMatch(  current_word  ,  vector<string>{"ls"} ) ;
	}

	if (topic=="asset") {
		if (full_words<2) { // we work on word2 - the action:
			return WordsThatMatch(  current_word  ,  vector<string>{"new", "[BLANK]"} ) ;
		}
		if (full_words<3) { // we work on word3 - var1
			if (action=="new") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<assetID>"} ) ;
			}
		}
	}

	if (topic=="basket") {
		return WordsThatMatch(  current_word  ,  vector<string>{"exchange", "ls","new" } ) ;
	}

	if (topic=="cash") {
		if (full_words<2) { // we work on word2 - the action:
			return WordsThatMatch(  current_word  ,  vector<string>{"send"} ) ;
		}
		if (full_words<3) {
			if (action=="send") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<mynym>"} ); //TODO Suitable changes to this part - propably after merging with otlib
			}
		}
		if (full_words<4) { // we work on word3 - var1
			if (cmdArgs.at(0)=="send") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<hisnym>"} ); //TODO Suitable changes to this part - propably after merging with otlib
			}
		}
	}

	if (topic=="cheque") {
		return WordsThatMatch(  current_word  ,  vector<string>{"new"} ) ;
	}

	if (topic=="contract") {
		if (full_words<2) { // we work on word2 - the action:
			return WordsThatMatch(  current_word  ,  vector<string>{"get", "new", "sign"} ) ;
		}
		if (full_words<3) {
			if (action=="get") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<contractID>"} ); //TODO Suitable changes to this part - propably after merging with otlib
			}
		}
	}

	if (topic=="market") {
		return WordsThatMatch(  current_word  ,  vector<string>{"ls", "[BLANK]"} ) ;
	}

	if (topic=="mint") {
		return WordsThatMatch(  current_word  ,  vector<string>{"new"} ) ;
	}

	if (topic=="msg") {
		if (full_words<2) { // we work on word2 - the action:
			return WordsThatMatch(  current_word  , vector<string>{"send","ls","rm","mv"} );
		}
		if (full_words<3) { // we work on word3 - var1
			if (action=="send") {
				return WordsThatMatch(  current_word  ,  mHintData->getNymsMy() ); //TODO otlib
			}
			if (action=="mv") {
				return WordsThatMatch(  current_word  ,  vector<string>{"Where-to?"} ); // in mail box... will there be other directories?
			}
			if (action=="rm") {
				return WordsThatMatch(  current_word  ,  vector<string>{"--all", "index"} );
			}
		}
		if (full_words<4) { // we work on word3 - var1
			if (cmdArgs.at(0)=="<mynym>") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<hisnym>"} ); //TODO otlib
			}
		}
		if (full_words<5) { // we work on word4 - var2
			if (cmdArgs.at(1)=="<hisnym>") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<ccoptional>"} ); //TODO otlib
			}
		}
	}

	if (topic=="msguard") { // testing!
		if (full_words<2) { // we work on word2 - the action:
			return WordsThatMatch(  current_word  , vector<string>{"info","start","stop"} ); // <-- TODO
		}
		if (full_words<3) { // we work on word3 - var1
			if (action=="start") {
				return WordsThatMatch(  current_word  ,  vector<string>{"eth0","eth1","eth2","usb1","usb2"} );
			}
		}
	}

	if (topic=="nym") {
		if (full_words<2) { // we work on word2 - the action:
			return WordsThatMatch(  current_word  ,  vector<string>{"check", "edit", "export", "import", "info", "ls", "new", "refresh", "register", "rm", "[BLANK]"} ) ;
		}
		if (full_words<3) { // we work on word3 - var1
			if (action=="new") {
				return WordsThatMatch(  current_word  ,  vector<string>{"name", "[BLANK]"} ); //TODO Suitable changes to this part - propably after merging with otlib
			}
			if (action=="rm") {
				return WordsThatMatch(  current_word  ,  vector<string>{"name", "<nymID>"} );//TODO Suitable changes to this part - propably after merging with otlib
			}
			if (action=="info") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<nymID>"} );//TODO Suitable changes to this part - propably after merging with otlib
			}
			if (action=="edit") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<nymID>"} );//TODO Suitable changes to this part - propably after merging with otlib
			}
			if (action=="register") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<nymID>", "<serverID>"} );//TODO Suitable changes to this part - propably after merging with otlib same problem like with "msg send" how to implement this one?
			}
			if (action=="check") {
				return WordsThatMatch(  current_word  ,  vector<string>{"<nymID>"} );//TODO Suitable changes to this part - propably after merging with otlib same problem like with "msg send" how to implement this one?
			}
		}
	}

	if (topic=="nym-cred") {
		return WordsThatMatch(  current_word  ,  vector<string>{"new", "revoke" , "show"} ) ;
	}

	/*if (topic=="receipt") {
		return WordsThatMatch(  current_word  ,  vector<string>{"[BLANK]"} ) ;
	}*/

	if (topic=="server") {
		return WordsThatMatch(  current_word  ,  vector<string>{"ls", "new", "add", "[BLANK]" } ) ;
	}

	if (topic=="text") {
		return WordsThatMatch(  current_word  ,  vector<string>{"encode", "decode" } ) ; //coding method needed
	}

	if (topic=="voucher") {
		return WordsThatMatch(  current_word  ,  vector<string>{"new"} ) ;
	}

	/*if (topic=="wallet") {
		return WordsThatMatch(  current_word  ,  vector<string>{"status"} ) ;
	}*/

	if (topic=="server") {
		return WordsThatMatch(  current_word  ,  vector<string>{"ls", "new", "add", "[BLANK]" } ) ;
	}

	if (topic=="text") {
		return WordsThatMatch(  current_word  ,  vector<string>{"encode", "decode" } ) ;
	}

	if (topic=="voucher") {
		return WordsThatMatch(  current_word  ,  vector<string>{"new"} ) ;
	}

	/*if (topic=="wallet") {
		return WordsThatMatch(  current_word  ,  vector<string>{"status"} ) ;
	}*/

	return vector<string>(0,"");
	//throw std::runtime_error("Unable to handle following completion: sofar_str='" + ToStr(sofar_str) + "' in " + OT_CODE_STAMP);
}

class cInteractiveShell {
	public:
		cInteractiveShell();
		void run();
		void runReadline();
		void runEditline();

	protected:
		bool dbg;
};

cInteractiveShell::cInteractiveShell()
:dbg(false)
{ }


void cInteractiveShell::run() {
	while(1) {
		std::string line;
		cout << "\n\nCommand: Press ENTER to show auto-completion for the command. Type q or quit (and press ENTER) to quit." << endl;
		cout << "commandline-part> " << std::flush;
		getline(cin,line);
		if (line == "q") break;
		if (line == "quit") break;
		std::string cmdline;
		cmdline = "ot " + line;
		cout << "Auto-complete for '" << cmdline << "': " << endl;
		nOT::nTests::testcase_complete_1(cmdline);
	}
}

extern bool my_rl_wrapper_debug; // external

bool my_rl_wrapper_debug; // external

// [null-trem-cstr] definition: as defined by readline, the format of null-term-cstr is:
// dynamic array, null terminated, of dynamic c-strings.
// caller is responsible for deallocation of the pointed strings data (using free) as well as the array itself
// (using free).
// it can be NULL for 0 element array
// exmple:
// NULL - empty array
// { strdup("foo") , NULL } - 1 record array
// { strdup("foo") , strdup("bar", NULL } - 2 record array

// return all completions, in [null-term-cstr] format (we allocate, caller deallocates this memory)
static char** completionReadlineWrapper( const char * sofar , int start,  int end) {
	// code moved/merged with completionReadlineWrapper1
	// char** matches = (char **)NULL;
	return NULL;

	/*
	typedef char *p_char;
	char **cmd = (char**)malloc(sizeof(p_char) * (completions_size + 1));
	decltype(completions_size) pos = 0;
	for (auto rec : completions) {
		if (dbg) cerr << " to pos=" << pos << " [ " << rec << " ] "  <<endl;
		cmd[pos] = strdup( rec.c_str() );
		++pos;
	}
	cmd[completions_size] = NULL; // to the last element. array is up to completions_size+1 indeed.
	return cmd;
	*/
}

void * xmalloc (int size)
{
	void *buf;

	buf = malloc (size);
	if (!buf) {
			fprintf (stderr, "Error: Out of memory. Exiting.'n");
			exit (1);
	}
	return buf;
}

char * dupstr (char* s) {
	char *r;

	r = (char*) xmalloc ((strlen (s) + 1));
	strcpy (r, s);
	return (r);
}

// When readline will call us to complete "ot m" then our function will be called with number=0,
// then it should cache possibilities of endings "msg" "mint" "msguard", and return 0th (first) one.
// Next it will be called with other number (probably 1,2,3..) and return N-th possibility.
// Function is non-reentrant also in the meaing that it can not be called in interlace, e.g.
// ("ot m",0) then ("ot m",1) then ("ot x",0) and suddenly back to ("ot x",2) without reinitialization
// (done with number=0) is an error (at least currently, in future we might cache various completion
// arrays, or recalculate on change)
static char* completionReadlineWrapper1(const char *sofar , int number) {
	bool dbg = my_rl_wrapper_debug;
	if (dbg) cerr << "\nsofar="<<sofar<<" number="<<number<<" rl_line_buffer="<<rl_line_buffer<<endl;
	string line;
	//cerr << endl << "completionReadlineWrapper1 call" << endl;
	if (rl_line_buffer) line = rl_line_buffer;
	line = line.substr(0, rl_point); // Complete from cursor position
	nOT::nOTHint::cHintManager hint;
	vector <string> completions = hint.AutoCompleteEntire(line); // <--
	// TODO cache the result! across number=...
	auto completions_size = completions.size();
	if (dbg) DBGDisplayVectorEndl(completions);
	if (dbg) cerr << "completions_size=" << completions_size << endl;
	if (! completions_size) return NULL; // <--- RET

	if (number==completions_size) return NULL;
	return strdup( completions.at(number).c_str() ); // caller must free() this memory
}


// http://www.delorie.com/gnu/docs/readline/rlman_28.html
void cInteractiveShell::runReadline() {
	char *buf = NULL;
	my_rl_wrapper_debug = dbg;
	// rl_attempted_completion_function = completionReadlineWrapper;
	// rl_completion_entry_function = completionReadlineWrapper1;
	rl_bind_key('\t',rl_complete);
	while((buf = readline("commandline-part> "))!=NULL) { // <--- readline()
		std::string word;
		if (buf) word=buf; // if not-null buf, then assign
		if (buf) { free(buf); buf=NULL; }
		// do NOT use buf variable below.

		if (dbg) cout << "Word was: " << word << endl;
		std::string cmd;
		if (rl_line_buffer) cmd = rl_line_buffer; // save the full command into string
		if (dbg) cout << "Command was: " << cmd << endl;

		if (cmd=="quit") break;
		if (cmd=="q") break;

		if (cmd.length()) {
			add_history(cmd.c_str()); // TODO (leaks memory...) but why
		}
		cout << "Command was: " << cmd << endl;

		cout << "Auto completion for (" << cmd << ") is: ";
		nOT::nTests::testcase_complete_1(cmd);
		cout << endl;

		// ... TODO run it
	}
	if (buf) { free(buf); buf=NULL; }
	clear_history(); // http://cnswww.cns.cwru.edu/php/chet/readline/history.html#IDX11
}

char ** completion (const char* text, int start, int end __attribute__((__unused__))){
	char **matches;
	matches = (char **)NULL;
	matches = rl_completion_matches (text, completionReadlineWrapper1);
	return (matches);
}

void cInteractiveShell::runEditline() {
	char *buf = NULL;
	my_rl_wrapper_debug = dbg;
	rl_attempted_completion_function = completion;
	rl_bind_key('\t',rl_complete);
	while((buf = readline("commandline-part> "))!=NULL) { // <--- readline()
		std::string word;
		if (buf) word=buf; // if not-null buf, then assign
		if (buf) { free(buf); buf=NULL; }
		// do NOT use buf variable below.

		if (dbg) cout << "Word was: " << word << endl;
		std::string cmd;
		if (rl_line_buffer) cmd = rl_line_buffer; // save the full command into string
		cmd = cmd.substr(0, cmd.length()-1); // remove \n
		if (dbg) cout << "Command was: " << cmd << endl;
		if (cmd=="quit") break;
		if (cmd=="q") break;

		if (cmd.length()) {
			add_history(cmd.c_str()); // TODO (leaks memory...) but why
		}
		cout << "Command was: " << cmd << endl;

		cout << "Auto completion for (" << cmd << ") is: ";
		nOT::nTests::testcase_complete_1(cmd);
		cout << endl;

		// ... TODO run it
	}
	if (buf) { free(buf); buf=NULL; }
	clear_history(); // http://cnswww.cns.cwru.edu/php/chet/readline/history.html#IDX11
}

}; // namespace nOTHint
}; // namespace nOT
// ########################################################################
// ########################################################################
// ########################################################################

std::string gVar1; // to keep program input argument for testcase_complete_1
// ====================================================================


int main(int argc, char **argv) {
	try {
		nOT::nTests::testcase_run_all_tests();
	}
	catch(const std::exception &e) {
		std::cerr << "\n*** The testcases code thrown an exception: " << e.what() << std::endl;
	}
	catch(...) {
		std::cerr << "\n*** The testcases code thrown an UNKNOWN exception!" << std::endl;
	}

	int ret = nOT::nTests::main_start(argc, argv);
	return ret;
}

// int pole(const int r) { 	r=3; }


int nOT::nTests::main_start(int argc, char **argv) {
	vector<string> args;
	if (! (argc>=1)) {
		throw std::runtime_error("Main program called with 0 arguments (not even program name).");
	}
	args.reserve(argc-1); for (int i=1; i<argc; ++i) args.push_back(argv[i]); // from 1 - skip program name

	size_t nr=0;
	for(auto arg: args) {
		if (arg=="--complete-shell") {
			nOT::nOTHint::cInteractiveShell shell;
			shell.runEditline();
		}
		else if (arg=="--complete-one") {
			string v;  bool ok=1;  try { v=args.at(nr+1); } catch(...) { ok=0; }
			if (ok) {
				nOT::nTests::testcase_complete_1(v);
			} else { cerr<<"Missing variables for command line argument '"<<arg<<"'"<<endl; }
		}

		++nr;
	}

/*
	if (argc>1) {
		std::string arg1 = argv[1];

		if (arg1=="--complete-shell") {
		} // SHELL
		else if (arg1=="--complete-one") {
			if (argc>2) {
				gVar1 = argv[2];
				nOT::nTests::testcase_complete_1_wrapper();
				//std::cout << gVar1 << std::endl;
			} // COMPLETE with it's var1
			else { std::cerr<<"No string provided for completion."<<std::endl; return 1; }
		} // COMPLETE
	} else {
		std::cerr<<"No arguments given."<<std::endl; return 1;
	}
*/
	return 0;
}
// ====================================================================

// #####################################################################
// #####################################################################
// #####################################################################

namespace nOT {
namespace nTests {


OT_COMMON_USING_NAMESPACE; // <========= NAMESPACE inclusion

bool testcase_complete_1(const string &sofar) {
	map<string , vector<string> > const cases {
		 { "m", { "msg", "msguard" } }
		,{ "ms", { "msg", "msguard" } }
		,{ "msg", { "msg", "msguard" } }
		,{ "msg ", { "send", "ls", "mv", "rm" } }
		,{ "msg s", { "send" } }
		,{ "msg se", { "send" } }
		,{ "msg sen", { "send" } }
		,{ "msg send", { "send" } }
		,{ "msg send ", { "mynym1", "mynym2" } }
		,{ "msg send m", { "mynym1", "mynym2" } }
		,{ "msg send my", { "mynym1", "mynym2" } }
		,{ "msg send myn", { "mynym1", "mynym2" } }
		,{ "msg send myny", { "mynym1", "mynym2" } }
		,{ "msg send mynym", { "mynym1", "mynym2" } }
		,{ "msg send mynym1", { "mynym1" } }
		,{ "msg send mynym1 ", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym1 h", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym1 hi", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym1 his", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym1 hisn", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym1 hisny", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym1 hisnym", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym1 hisnym1", { "hisnym1" } }
		,{ "msg send mynym1 hisnym2", { "hisnym2" } }
		,{ "msg send mynym2", { "mynym2" } }
		,{ "msg send mynym2 ", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym2 h", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym2 hi", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym2 his", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym2 hisn", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym2 hisny", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym2 hisnym", { "hisnym1", "hisnym2" } }
		,{ "msg send mynym2 hisnym1", { "hisnym1" } }
		,{ "msg send mynym2 hisnym2", { "hisnym2" } }
		,{ "msg l", { "ls" } }
		,{ "msg ls", { "ls" } }
		,{ "msg m", { "mv" } }
		,{ "msg mv", { "mv" } }
		,{ "msg mv ", { "msgid1", "msgid2" } }
		,{ "msg mv m", { "msgid1", "msgid2" } }
		,{ "msg mv ms", { "msgid1", "msgid2" } }
		,{ "msg mv msg", { "msgid1", "msgid2" } }
		,{ "msg mv msgi", { "msgid1", "msgid2" } }
		,{ "msg mv msgid", { "msgid1", "msgid2" } }
		,{ "msg mv msgid1", { "msgid1" } }
		,{ "msg mv msgid2", { "msgid2" } }
		,{ "msg r", { "rm" } }
		,{ "msg rm", { "rm" } }
		,{ "msg rm ", { "msgid1", "msgid2" } }
		,{ "msg rm m", { "msgid1", "msgid2" } }
		,{ "msg rm ms", { "msgid1", "msgid2" } }
		,{ "msg rm msg", { "msgid1", "msgid2" } }
		,{ "msg rm msgi", { "msgid1", "msgid2" } }
		,{ "msg rm msgid", { "msgid1", "msgid2" } }
		,{ "msg rm msgid1", { "msgid1" } }
		,{ "msg rm msgid2", { "msgid2" } }
		,{ "msgu", { "msguard" } }
		,{ "msgua", { "msguard" } }
		,{ "msguar", { "msguard" } }
		,{ "msguard", { "msguard" } }
		,{ "msguard ", { "info", "start", "stop" } }
		,{ "msguard i", { "info" } }
		,{ "msguard in", { "info" } }
		,{ "msguard inf", { "info" } }
		,{ "msguard info", { "info" } }
		,{ "msguard s", { "start", "stop" } }
		,{ "msguard st", { "start", "stop" } }
		,{ "msguard sta", { "start" } }
		,{ "msguard star", { "start" } }
		,{ "msguard start", { "start" } }
		,{ "msguard sto", { "stop" } }
		,{ "msguard stop", { "stop" } }
		,{ "n" , { "nym"} }
		,{ "ny" , { "nym"} }
		,{ "nym" , { "nym"} }
		,{ "nym " , { "ls", "new" , "rm"} }
		,{ "nym l" , { "ls" } }
		,{ "nym ls" , { "ls" } }
		,{ "nym n" , { "new" } }
		,{ "nym ne" , { "new" } }
		,{ "nym new" , { "new" } }
		,{ "nym r" , { "rm"} }
		,{ "nym rm" , { "rm"} }
	};

	nOT::nOTHint::cHintManager hint;

	string line(sofar);
	line.erase (0,3); // need to erase 'ot' word from intput string // TODO erase it before, length of argv[0] could differ, e.g. "ot_secure"
	// TODO verify length (avoid underflow)

	vector<string> out = hint.AutoComplete(line);
	nOT::nUtil::DisplayVector(std::cout, out); // testcase


	bool ok = 1;

	return ok;
}

bool testcase_complete_1_wrapper(){
	return nOT::nTests::testcase_complete_1(gVar1);
}

// ==================================================================
// ==================================================================
bool testcase_namespace_pollution(const cTestCaseCfg &testCfg) {
	class a {
	};

	using namespace nOT::nOTHint;

	#ifdef __unittest_mustfail_compile1
	{
		// using std::string; // without this
		string s; // <-- must be a compile error
	}
	#endif
	{
		using std::string;
		string s; // <-- must work
	}

	return true;
}

bool testcase_cxx11_memory(const cTestCaseCfg &testCfg) {
	using namespace nOT::nNewcli;
	using namespace nOT::nOTHint;

	// TODO capture output and verify expected output

	struct cObj {
			cObj() { /*cout<<"new"<<endl;*/ }
			~cObj() { /*cout<<"delete"<<endl;*/ }
	};

	unique_ptr<cObj> A( new cObj );

	return true;
}

bool testcase_fail1(const cTestCaseCfg &testCfg) {
	testCfg.ossErr<<"This special testcase will always FAIL, on purpose of testing the testcases framework."<<endl;
	return false;
}


bool helper_testcase_run_main_with_arguments(const cTestCaseCfg &testCfg , vector<string> tab ) {
	int argc = tab.size(); // <--
	typedef char * char_p;
	char_p * argv  = new char_p[argc]; // C++ style new[]

	cerr << "Testing " << __FUNCTION__ << " with " << argc << " argument(s): ";
	size_t nr=0;
	for(auto rec:tab) {
		argv[nr] = strdup(rec.c_str()); // C style strdup/free
		++nr;
		cerr << "'" << rec << "' ";
	}
	cerr << endl;

	bool ok=true;
	try {
		main_start(argc, argv); // ... ok? TODO
	}
	catch(const std::exception &e) {
		ok=false;
		cerr << "\n *** in " << __FUNCTION__ << " catched exception: " << e.what() << endl;
	}
	for (int i=0; i<argc; ++i) { free( argv[i] ); argv[i]=NULL; } // free!
	delete []argv; argv=nullptr;
	return ok;
}

bool testcase_run_main_args(const cTestCaseCfg &testCfg) {
	bool ok=true;
	const string programName="othint";

	if (!	helper_testcase_run_main_with_arguments(testCfg, vector<string>{programName,"--complete-one", "ot msg sen"} ) ) ok=false;
	if (!	helper_testcase_run_main_with_arguments(testCfg, vector<string>{programName,"--complete-one"} ) ) ok=false;
	if (!	helper_testcase_run_main_with_arguments(testCfg, vector<string>{programName} ) ) ok=false;
	if (!	helper_testcase_run_main_with_arguments(testCfg, vector<string>{} ) ) ok=false;

	return ok;
}

bool testcase_run_all_tests() { // Can only run bool(*)(void) functions (to run more types casting is needed)
	long int number_errors = 0; // long :o

	cTestCaseCfg testCfg(cerr, true);

	struct cTestCaseNamed {
		cTestCaseNamed( tTestCaseFunction func  , const string &name)
		:mFunc(func), mName(name) // XXX
		{
		}

		tTestCaseFunction mFunc;
		string mName;
	};
	vector<cTestCaseNamed> vectorOfFunctions;

	// [stringification], [macro-semicolon-trick]
	#define xstr(s) str(s)
	#define str(s) #s
	#define AddFunction(XXX) do {   vectorOfFunctions.push_back( cTestCaseNamed( & XXX , str(XXX) ) );   } while(0)
	AddFunction(testcase_namespace_pollution);
	AddFunction(testcase_cxx11_memory);
	AddFunction(testcase_run_main_args);
	AddFunction(testcase_fail1); // only for testing of this test code
	#undef AddFunction
	#undef xstr
	#undef str

	std::ostringstream failure_details;

	int nr=0;
	for(auto it = vectorOfFunctions.begin(); it != vectorOfFunctions.end(); ++it) { // Calling all test functions
		const cTestCaseNamed &test = *it;
		bool result = (   test.mFunc   )( testCfg ); // <--- run the test with config testCfg
		if (result == false) {
			number_errors++;
			std::ostringstream msgOss; msgOss << "test #" << nr << " " << test.mName  <<  " failed!";
			string msg = msgOss.str();
			cerr << " *** " << msg << endl;
			failure_details << " " << msg << " ";
		}
		++nr;
	}

	if (number_errors == 0) {
		//cout << "All tests completed successfully." << endl;
	}
	else {
		cerr << "*** Some tests were not completed! (" << failure_details.str() << ")" << endl;
	}

	return number_errors==0;
}

} // nTests
} // nOT
