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
	./othint --complete-shell

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

template <class T>
std::string ToStr(const T & obj) {
	std::ostringstream oss;
	oss << obj;
	return oss.str();
}

template <class T>
void DisplayVector(const std::vector<T> &v, const std::string &delim=" ") {
	std::copy( v.begin(), v.end(), std::ostream_iterator<T>(std::cerr, delim.c_str()) );
}

template <class T>
void DisplayVectorEndl(const std::vector<T> &v, const std::string &delim=" ") {
	DisplayVector(v,delim);
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
In this situatin, bash autocomplete with othint program
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
	it will ask: "Please confirm do you want to NOW connect to OT server aliased BigTest1, 
	with ID=855gusd2dffj2d9uisdfokj233 (unknown/new server), and execute 
	mint-spawn command? Type 2 words: 'unknown spawn' to confirm, or 'no'"

Also name alice is in front (instead alphabet sorting) since it was recentyl/frequently used.

All OT commands will be neatly supported in this way. 


=== Commands are in form ===

ot [front1,front2...] topic action [--subact] var1,...  [varM,...] [--optNameN[=[optArgN]]...]

ot <-front options--> <- cCmdname ----------> <---- arguments ------------------------------->
ot                    <- cCmdname ----------> <---- vars -----> <-- options ----------------->
ot <--- optional ---> <- mandatory-------------------> <--- optional ------------------------>

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
	- front-options are speciall options that must appear in front because they change meaning/parsing
		of everything next - particullary, auto-completion options. Read section [front-options] for details

	- Arguments available depend on the command name.

	- Options for command depend on the command name, as well are imported from global.

	- Options can't be placed before variables!

	- Options can be unique or can repeat. Options can have no value/data,
		or can have one.This gives 2*2 = 4 kinds of options: uniq, uniqData,
		repeat, repeatData.
		
	- Options can be both global and comming from selected action/subaction.

SEE testcases below in functions

msg     # error: incomplete action
msg send     # error: missing required options
msg send <mynym>     # error: missing required options
msg send <mynym> <hisnym>
msg send <mynym> <hisnym>
msg send <mynym> <hisnym>


msg send <mynym> <hisnym>
msg send <mynym> <hisnym> --push     # global option
msg send <mynym> <hisnym> --no-footer     # action option
msg send <mynym> <hisnym> --cc <ccnym>     # action option with value
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2>
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2>
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2> --push
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2> --push
msg ls
msg mv
msg rm <index>
nym 		# can display active (default) nym
nym ls
nym new
nym new <name>
nym rm <name>
nym rm <nymID>
nym info <nymID>
nym edit <nymID>
nym register <nymID>
nym import
asset
account
market
basket
voucher
cheque
server
mint
contract
cash
msguard info   # test, imaginary comand "msguard" (microsoft guard) info - shows windows firewall status for OT tcp
msguard start
msguard stop

------------------------------------------------------------------------
opentxs commands:

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
	// klasa mowi jaki to argument  np ze to argument  "mynym" i ze ma byc stringiem albo ze ma byc integerem albo ze to tylko boolean
	// oraz dostarcza klasa !!! do auto complete jakas
	
	string mName; // "mynym" "hisnym" (nawet te argumenty, ktore maja okreslona kolejnosc wiec niby nie maja nazwy, beda jak mialy dla jasnosci i np generowania tekstu help"

	// inne mName to bedzie np "cc"  dla opcji --cc ktora juz wymaga nazwy

};
*/

/*
typedef string argument_data ; // na razie...

class cCmdoptions {

		// required arguments
		vector< argument_info > // ty ma być { ("msg","send")  ,  ("msg","send","body") itd tak jak w cCmdname::returnStandard

		map< argument_info , vector< argument_data > > // tu bedzie mapa, ktora np dla
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

bool testcase_namespace_pollution();
bool testcase_cxx11_memory();
bool testcase_complete_1(const std::string &sofar);
bool testcase_complete_1_wrapper();

bool testcase_run_all_tests();

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

class cHint {
	public:

		vector<string> AutoComplete(const string &sofar_str) const; // the main function to auto-complete

	protected:
		vector<string> BuildTreeOfCommandlines(const string &sofar_str, bool show_all) const; // return command lines tree that is possible from this place
};

vector<string> cHint::AutoComplete(const string &sofar_str) const { // the main function to auto-complete
	auto possible = BuildTreeOfCommandlines(sofar_str,false);
	return possible;
}

vector<string> cHint::BuildTreeOfCommandlines(const string &sofar_str, bool show_all) const {
	bool dbg = true;

	std::istringstream iss(sofar_str);
	vector<string> sofar { std::istream_iterator<string>{iss}, std::istream_iterator<string>{} };
	// ^-- fine for now, but later needs to take into account "..." and slashes etc... use boost option? -- yes? TODO test
	
	if (GetLastCharIf(sofar_str)==" ") {
		ASRT( sofar.size()>=1 );
		sofar.at( sofar.size()-1 )+=" "; // append the last space - to the last word so that we know it was ended
	}
	
	// exactly 2 elements, with "" for missing elements
	decltype(sofar) namepart( sofar.begin(), sofar.end() ); 
	while (namepart.size()<2) namepart.push_back("");
	if (dbg) DisplayVectorEndl(namepart,",");

	const vector<string> forward_options = {"--HO","--HL","--HT","--HV","--hint-remote","--hint-cached","--vpn-all-net"};
	const vector<string> all_topics = {"msg","msguard","nym"};

	const string topic  = rtrim( namepart.at(0) );
	const string action = rtrim( namepart.at(1) );

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
	
	// === at 1st (non-forward-option) word (topic) ===

	if (full_words<1) { // at 1st word (topic) -> show all level 1 cmdnames
		return WordsThatMatch(  current_word  ,  vector<string>{"msg","msguard","nym"} + forward_options  ) ;
	}
	
	// === at 2nd (non-forward-option) word (action) ===
	if (topic=="msg") {
		return WordsThatMatch(  current_word  , vector<string>{"send","ls","rm","mv"} );
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
		return WordsThatMatch(  current_word  ,  vector<string>{"aaa1","aaa2","ab"} ) ;
	}

	return vector<string>(1,"ERROR");
	//throw std::runtime_error("Unable to handle following completion: sofar_str='" + ToStr(sofar_str) + "' in " + OT_CODE_STAMP);
}


class cInteractiveShell {
	public:
		void run();
};

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


}; // namespace nOTHint
}; // namespace nOT
// ########################################################################
// ########################################################################
// ########################################################################

std::string gVar1; // to keep program input argument for testcase_complete_1
// ====================================================================
int main(int argc, char* argv[]) {
	nOT::nTests::testcase_run_all_tests();

	if (argc>=1) {
		std::string arg1 = argv[1];
		if (arg1=="--complete-shell") {
			nOT::nOTHint::cInteractiveShell shell;
			shell.run();
		} // SHELL
		else if (arg1=="--complete-one") {
			if (argc>=2) {
				gVar1 = argv[2];
				nOT::nTests::testcase_complete_1_wrapper();
			} // COMPLETE with it's var1
			else { std::cerr<<"No string provided for completion."<<std::endl; return 1; }
		} // COMPLETE
	} else {
		std::cerr<<"No arguments given."<<std::endl; return 1; 
	}

	// return 42; // nope. in C++, the exit code returns YOU
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

	nOT::nOTHint::cHint hint;

	string line(sofar);
	line.erase (0,3); // need to erase 'ot' word from intput string // TODO erase it before, length of argv[0] could differ, e.g. "ot_secure"
	// TODO verify length (avoid underflow)
	
	vector<string> out = hint.AutoComplete(line);
	nOT::nUtil::DisplayVector(out);
	
	
	bool ok = 1;

	return ok;
}

bool testcase_complete_1_wrapper(){
	return nOT::nTests::testcase_complete_1(gVar1);
}

// ==================================================================
// ==================================================================
bool testcase_namespace_pollution() {
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

bool testcase_cxx11_memory() {
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

bool testcase_run_all_tests() { // Can only run bool(*)(void) functions (to run more types casting is needed)
	long int number_errors = 0; // long :o
	
	vector<bool (*)(void)> vectorOfFunctions;
	vector<bool (*)(void)>::iterator it;
	// creating vector of pointers to test functions
	vectorOfFunctions.push_back(&testcase_namespace_pollution);
	vectorOfFunctions.push_back(&testcase_cxx11_memory);
	
	bool result = true;
	for(it = vectorOfFunctions.begin(); it != vectorOfFunctions.end(); ++it) { // Calling all test functions
		result = (*it)();
		if(result == false)
			number_errors++;
	}
	if (number_errors == 0){
		//cout << "All tests completed successfully." << endl;
	}
	else{
		//cout << "Some tests were not completed." << endl;
	}
	// testcase_complete_1(); // quiet.
	
	return true;
}

} // nTests
} // nOT
