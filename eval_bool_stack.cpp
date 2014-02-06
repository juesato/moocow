#include <iostream>
#include <stack>
using namespace std;

bool eval(string str) { 
	stack<char> opers;
	stack<bool> bits;
	int paren = 0;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0' || str[i] == '1') bits.push((bool)(str[i] - '0'));
		else {
			opers.push(str[i]);
			if (str[i] == '(') {
				paren++;
			}
			if (str[i] == ')') {
				paren--;
				opers.pop();
				bool val = bits.top(); bits.pop();
				while (opers.top() != '(') {
					bool prev = bits.top(); bits.pop();
					if (opers.top() == '|') val = val || prev;
					else val = val && prev;
					opers.pop();
				}
				opers.pop();
				bits.push(val);
			}
		}
		
		if (!paren) {
			while (bits.size() > 1) {
				bool a = bits.top(); bits.pop();
				bool b = bits.top(); bits.pop();
				if (opers.top() == '|') bits.push(a || b);
				else bits.push(a && b);
				opers.pop();
			}
		} 
	}
	return bits.top();
}

int main() {
	string str;
	while (cin >> str) {
		cout << eval(str) << endl;
	}
	return 0;
}