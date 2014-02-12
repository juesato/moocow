#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0, _##i = (n); i < _##i; ++i)

int cts[15];
int cts2[15];

int main() {
	int a, b;
	cin >> b >> a;
	
	int ca = a;
	int bas = 1;
	int dif = 0;
	if (a > 0) cts[0]--;
	while (ca > 0) {
		int mx = ca%10;
		dif += mx * bas;
		ca /= 10;
		rep(i, 10) {
			cts[i] += (a - a%(bas*10)) / 10;
			// cout << "CHECK ";
			// cout << (a - a%bas) / 10;
			// cout << cts[i] << " " ;
			
		}
		// cout << "INCREMENT ALL BY " << (a - a%bas*10) / 10 << endl;
		rep(i,mx) cts[i] += bas;
		cts[mx] += (dif - mx*bas + 1);
		bas *= 10;
		// cout << "CA " << ca;
	}
	b--;
	int cb = b;
	bas = 1;
	dif = 0;
	if (b > 0) cts2[0]--;
	while (cb > 0) {
		int mx = cb%10;
		dif += mx * bas;
		cb /= 10;
		rep(i, 10) {
			cts2[i] += (b - b%(bas*10)) / 10;
			// cout << "CHECK ";
			// cout << (a - a%bas) / 10;
			// cout << cts[i] << " " ;
			
		}
		// cout << "INCREMENT ALL BY " << (a - a%bas*10) / 10 << endl;
		rep(i,mx) cts2[i] += bas;
		cts2[mx] += (dif - mx*bas + 1);
		bas *= 10;
		// cout << "CA " << ca;
	}
	
	// rep(i, 9) {
	// 	cout << cts[i] << " ";
	// }
	// cout << cts[9];
	// cout << endl;
	// rep(i, 10) cout << cts2[i] << " ";
	rep(i, 9) cout << (cts[i] - cts2[i]) << " ";
	cout << cts[9] - cts2[9];
}