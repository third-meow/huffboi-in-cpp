#include <string>
using namespace std;

class Node {
	public:
		void autoFreqCalc();
		void smartPrint(string code);
		void setVal(char newVal);
		char getVal();

		Node* right = NULL;
		Node* left = NULL;
		int freq;
	private:
		char _val = 0;
};
