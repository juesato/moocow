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

int avail[3], prefs[3];

int main() {
	freopen("shirts.txt","r",stdin); freopen("shirtsout.txt","w",stdout);

	int t; cin >> t;
	rep(z, t) {
		rep(i, 3) {
			avail[i] = 0;
			prefs[i] = 0;
		}
		string av, pr;
		cin >> av >> pr;
		rep(i, av.length()) {
			if (av[i] == 'S') avail[0]++;
			else if (av[i] == 'M') avail[1]++;
			else avail[2]++;
		}
		rep(i, pr.length()) {
			if (pr[i] == 'S') prefs[0]++;
			else if (pr[i] == 'M') prefs[1]++;
			else prefs[2]++;
		}
		bool ans = true;
		avail[2] -= prefs[2];
		// cout << avail[2] << " " << avail[1] << endl;
		if (avail[2] < 0) ans = false;
		avail[1] += avail[2];
		avail[1] -= prefs[1];
		if (avail[1] < 0) ans = false;
		// cout << avail[1] << endl;
		avail[0] += avail[1];
		avail[0] -= prefs[0];
		if (avail[0] < 0) ans = false;
		// cout << avail[0] << endl;
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}