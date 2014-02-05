#include <iostream>
#include <string>
using namespace std;

bool eval(string str) {
	string stak;
	if (str.length() == 1) return (bool) (str[0] - '0');
	
	bool fir3 = 0;
	if (str[1] == '&' && (str[2] == '0' || str[2] == '1')) {
		bool fi = (bool) (str[0] - '0');
		bool se = (bool) (str[2] - '0');
		stak += (char) ('0' + (fi && se));
		fir3 = 1;
	}
	if (str[1] == '|' && (str[2] == '0' || str[2] == '1')) {
		bool fi = (bool) (str[0] - '0');
		bool se = (bool) (str[2] - '0');
		stak += (char) ('0' + (fi || se));
		fir3 = 1;
	}
	
	int paren = 0;
	int paren_beg = -1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			paren++;
			if (paren == 1) paren_beg = i;
		}
		if (str[i] == ')') {
			paren--;
			if (!paren && paren_beg != -1) {
				stak += (char) ('0' + eval(str.substr(paren_beg + 1, i-paren_beg-1)));
			}
			continue;
		}
		if (paren == 0 && (i > 2 || !fir3)) {
			stak += str[i];
		}
	}
	// cout << str << " EVALUATES TO " << stak << endl;
	return eval(stak);
}

int main() {
	string str;
	while (cin >> str) {
		cout << eval(str) << endl;
	}
	return 0;
}