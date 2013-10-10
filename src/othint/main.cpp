

// OTNewcliCmdline

namespace nOT {
namespace nNewcli {

/*

Commands have: topic, action, [--subaction] [arg1] [arg2] .. [argN] [--optionNameN [optionArgN]] 
options can be both global and comming from selected action/subaction
subaction will be probably not used but leaving such possibility to be flexible

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

 
*/

class cCmdname { // represents name of one command, including the 2-3 components e.g. msg,send or msg,export,msg
	// "msg" (not a valid command, will be used with null_function, is just to provide global options to inherit)
	// "msg send"
	// "msg list"
	// "msg export msg"
	// "msg export all"

	public:
		const string mTopic;
		const string mAction;
		const string mSubaction;

		cCmdline(string topic,act,sub="" ... ) ....

		// to be used in "main" to get list of possible command names:
		static vecotr<cCmdname> returnStandard() {
			... v
			v.push_back( cCmdlineInfo("msg","send") );
			v.push_back( cCmdlineInfo("msg","send","body") );
			v.push_back( cCmdlineInfo("msg","send","headers") );
			v.push_back( cCmdlineInfo("msg","list") );
			return v;
		}
};


class argument_info {
	// klasa mowi jaki to argument  np ze to argument  "mynym" i ze ma byc stringiem albo ze ma byc integerem albo ze to tylko boolean 
	// oraz dostarcza klasa !!! do auto complete jakas
	
	string mName; // "mynym" "hisnym" (nawet te argumenty, ktore maja okreslona kolejnosc wiec niby nie maja nazwy, beda jak mialy dla jasnosci i np generowania tekstu help"

	// inne mName to bedzie np "cc"  dla opcji --cc ktora juz wymaga nazwy

};

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


} // namespace nNewcli

} // namespace nOT


namespace nOTHint {
}; // namespace nOTHint


int main() {


	
}

