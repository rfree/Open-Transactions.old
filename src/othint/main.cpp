
/**

OT Hints (new CLI - new commandline : auto complete commands, verify, check, etc)

Goal: this project aims to provide auto completion of newCLI OT commands, see [Description_of_auto_completion]

This subproject is separated out of OT, and uses C++11 and few other modern coding style changes.

Rules of language: use C++11, do not use boost (thougl we could copy small part of boost source code if needed,
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

// OTNewcliCmdline

// list of thigs from libraries that we pull into namespace nOT::nNewcli
// we might still need to copy/paste it in few places to make IDEs pick it up correctly
#define OT_COMMON_USING_NAMESPACE \
using std::string; \
using std::vector; \
using std::list; \
using std::set; \
using std::map; \
using std::unique_ptr; \
using std::cin; \
using std::cout; \
using std::endl; \
using nOT::nUtil::ToStr; 


// Please read and follow this syntax examples:
namespace nExamplesOfConvention { 
// Welcome, to the world of C++11 !

class cFooBar {
	int m_fooBarBaz;

	int Fooberize();
	int DerpTheHerp();
	inline int Foo() {
		int abc=42;
		return abc;
	}
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

template <class T>
std::string ToStr(const T & obj) {
	std::ostringstream oss;
	oss << obj;
	return oss.str();
}

}
}

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
using std::cout;
using std::endl;
using nOT::nUtil::ToStr;

/*

[Description_of_auto_completion]

Commands are in form:
topic, action, [--subaction] var1 var2 ... [argN1] [argN2] [--optionNameN[=][optionArgN]] 
<- cCmdname ---------------> <-------------------- arguments ------------------------->
<- cCmdname ---------------> <-- var ----> <--- extra ---> <-- option ---------------->

So, 2..3 words of command name, 0..N mandatory variables, 0..N extra variables, any options

Arguments available depend on the command name.

Options for command depend on the command name, as well are imported from global.

Options can be unique or can repeat. Options can have no value/data, or can have one.
This gives 2*2 = 4 kinds of options: uniq, uniqData, repeat, repeatData 
Options can be both global and comming from selected action/subaction.

subaction will be probably not used but leaving such possibility to be flexible

SEE testcases below in functions

msg     # error: incomplete action
msg send     # error: missing required options
msg send <mynym>     # error: missing required options
msg send <mynym> <hisnym>
msg send --headers <mynym> <hisnym>
msg send --body <mynym> <hisnym>
msg send --body <mynym> <hisnym>
msg send --body <mynym> <hisnym> --push     # global option
msg send --body <mynym> <hisnym> --no-footer     # action option
msg send --body <mynym> <hisnym> --cc <ccnym>     # action option with value
msg send --body <mynym> <hisnym> --cc <ccnym> --cc <ccnym2>
msg send --body <mynym> <hisnym> --cc <ccnym> --cc <ccnym2>
msg send --body <mynym> <hisnym> --cc <ccnym> --cc <ccnym2> --push
msg send <mynym> <hisnym> --cc <ccnym> --cc <ccnym2> --push
msg ls
msg list
msg mv
msg move
msg rm
msg del
msg delete
nym 
nym ls
nym list
nym new
nym del
nym delete
msguard info   # test, imaginary comand "msguard" (microsoft guard) info - shows windows firewall status for OT tcp
 
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
using std::cout;
using std::endl;
using nOT::nUtil::ToStr;

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
	std::istringstream iss(sofar_str);
	vector<string> sofar { std::istream_iterator<string>{iss}, std::istream_iterator<string>{} };
	// ^-- fine for now, but later needs to take into account "..." and slashes etc... use boost option?

	std::copy( sofar.begin() , sofar.end() ,  std::ostream_iterator<string>(std::cout, ", ") );

	auto namepart = sofar; // exactly 3 elements, with "" for missing elements
	// TODO split - limit to 3 on copy ^
	while (namepart.size()<3) namepart.push_back("");


	if (namepart.at(0)=="msg") {

		if (namepart.at(1)=="") {
			return vector<string>(1,"complete-1");
		} // msg ""

		else if (namepart.at(1)=="send") {

		} // msg send

		else if (namepart.at(1)=="del") {
		} // msg del

	} // msg

	else if (namepart.at(0)=="nym") {

	} // nym 

	else {
	}

/*
		// to be used in "main" to get list of possible command names:
		static vector<cCmdname> GetDefaultCommands() {
			v.push_back( cCmdlineInfo("msg","send") );
			v.push_back( cCmdlineInfo("msg","send","body") );
			v.push_back( cCmdlineInfo("msg","send","headers") );
			v.push_back( cCmdlineInfo("msg","list") );
			return v;
		}
		*/
	throw std::runtime_error("Unable to handle following completion: sofar_str='" + ToStr(sofar_str) + "' in " + OT_CODE_STAMP);
}

}; // namespace nOTHint
}; // namespace nOT
// ########################################################################
// ########################################################################
// ########################################################################

namespace nOT {
namespace nTests {

OT_COMMON_USING_NAMESPACE;

bool testcase_namespace_pollution();
bool testcase_cxx11_memory();
bool testcase_complete_1();

} // nTests
} // nOT



// ====================================================================
int main() {
	nOT::nTests::testcase_complete_1();
	nOT::nTests::testcase_namespace_pollution();
	nOT::nTests::testcase_cxx11_memory();

	// return 42; // nope. in C++, the exit code returns YOU
}
// ====================================================================

// #####################################################################
// #####################################################################
// #####################################################################

namespace nOT {
namespace nTests {


OT_COMMON_USING_NAMESPACE; // <========= NAMESPACE inclusion

bool testcase_complete_1() {
	map<string , vector<string> > const cases {
		 { "msg", { "uard", " send", " ls", " mv", " rm" } }
		,{ "msg ", { "send", "ls", "mv", "rm" } }
		,{ "msgruard", { " info" } }
		,{ "msg send", { "uard", " send", " ls", " mv", " rm" } }
		,{ "nym" , { " ls", " new" , " rm"} }
	};

	nOT::nOTHint::cHint hint; 
	hint.AutoComplete("msg send");

	bool ok = 1;

	return ok;
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

	struct cObj {
			cObj() { cout<<"new"<<endl; }
			~cObj() { cout<<"delete"<<endl; }
	};

	unique_ptr<cObj> A( new cObj );

	return true;
}


} // nTest
} // nOT


