#include "huffnode.h"


void Node::setVal(char newVal) {
	_val = newVal;
}

void Node::autoFreqCalc() {
	freq = 0;
	freq = freq + right->freq;
	freq = freq + left->freq;
}

int Node::getVal() {
	return _val;
}
