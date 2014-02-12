#include <iostream>
#include <stack>
using namespace std;

stack<int> ans;

int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << "0";
		return 0;
	}
	int sign = 1;
	int bas = 1;
	while (n != 0) {
		if (n%(bas*2) != 0) {
			ans.push(1);
			n -= (sign * bas);
		}
		else ans.push(0);
		// cout << "N IS" << n << endl;
		sign *= -1;
		bas *= 2;
	}
	while (ans.size()) {
		cout << ans.top();
		ans.pop();
	}
	return 0;
}