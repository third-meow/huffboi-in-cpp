#include <bits/stdc++.h>
#include <vector>
#include "huffnode.cpp"

using namespace std;

struct sort_nodes_key {
    inline bool operator() (const Node* n1, const Node* n2)
    {
        return (n1->freq > n2->freq);
    }
};

int main(int argc, char* argv[]){
	//get message for encoding
	cout << "Enter message for encoding" << endl;
	string text;
	cin >> text;
	//put message in vector
	vector<char> msg(text.begin(), text.end());

	//record the individual chars and their frequency
	vector<char> msg_chars;
	vector<int> msg_freqs;

	//for all of the recorded chars
	for (int i = 0; i < msg.size(); ++i) {
		//look for char in msg_data
		bool found = false;
		for (int j = 0; j < msg_chars.size(); ++j) {
			//if found, set found flag and increment freq in msg_data
			if (msg[i] == msg_chars[j]) {
				found = true;
				msg_freqs[j]++;
				break;
			}
		}

		//if not found, add char to msg_data with freq of 1
		if (found == false) {
			msg_chars.push_back(msg[i]);
			msg_freqs.push_back(1);
		}
	}

	//convert char-freq pairs to Node objects
	vector<Node*> msg_nodes;
	for (int i = 0; i < msg_chars.size(); ++i) {
		Node temp;
		temp.setVal(msg_chars[i]);
		temp.freq = msg_freqs[i];
		msg_nodes.push_back(&temp);
	}

	for (int i = 0; i < msg_nodes.size(); ++i) {
		char val = msg_nodes[i]->getVal();
		cout << val << endl;
	}



/*	//build nodes into tree
	while (msg_nodes.size() > 1) {
		//sort nodes
		sort(msg_nodes.begin(), msg_nodes.end(), sort_nodes_key());
		Node temp;
		temp.right=msg_nodes.back(); 
		msg_nodes.pop_back();
		temp.left=msg_nodes.back(); 
		msg_nodes.pop_back();

		temp.autoFreqCalc();
		msg_nodes.push_back(&temp);
	}*/



	return 0;
}
