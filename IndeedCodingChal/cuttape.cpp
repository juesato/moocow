#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define fi first
#define se second
#define rep(i, n) for (int i = 0, _##i = (n); i < _##i; ++i)
#define pb push_back

int main() {
	freopen("cuttape.txt","r",stdin); freopen("cutout.txt","w",stdout);
	int t; cin >> t;
	rep(z, t) {
		string s;
		int ans = 0;
		long long n;
		cin >> n >> s;
		long long bas = 1;
		long long tot = 0;
		rep(i, s.length()) {
			if (tot < n) {
				tot *= 2;
				if (s[i] == '1') tot++;
			}
			else {
				ans++;
				tot = 0;
				if (s[i] == '1') tot++;
			}
			if (tot >= n) {
				ans++;
				tot = 0;
			}
		}
		// for (int i = s.length()-1; i >= 0; i--) {
		// 	if (tot < n) {
		// 		if (s[i] == '1') {
		// 			tot += bas;
		// 		}
		// 		bas *= 2;
		// 	}
		// 	else {
		// 		tot = 0;
		// 		bas = 1;
		// 		ans++;
		// 	}
		// }
		cout << ans << '\n';
	}
}