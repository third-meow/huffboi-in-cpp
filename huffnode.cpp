#include "huffnode.h"
#include <string>
using namespace std;


//set this nodes value
void Node::setVal(char newVal) {
	_val = newVal;
}

//get this nodes value
char Node::getVal() {
	return _val;
}

//calculate freq from childrens freqs
void Node::autoFreqCalc() {
	freq = 0;
	freq = freq + right->freq;
	freq = freq + left->freq;
}

//print code-value pair, send recusivly to children nodes
void Node::smartPrint(string code) {
	//if node has value
	if (_val) {
		cout << code << " " <<  _val << endl;
	}

	//if node has right side child
	if (right) {
		string rCode = code + "1";
		right->smartPrint(rCode);
	}

	//if node has left side child
	if (left) {
		string lCode = code + "0";
		left-> smartPrint(lCode);
	}
}


