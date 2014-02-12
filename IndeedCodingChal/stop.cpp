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
	freopen("stop.txt","r",stdin); freopen("stopout.txt","w",stdout);
	int ctr = 0;
	int t; cin >> t;
	rep(z, t) {
		int n; cin >> n;
		int ctr = 0;
		while (n != 1) {
			if (n%2 == 0) {
				n /= 2;
			}
			else {
				n = n*3 + 1;
			}
			ctr++;
		}
		cout << ctr << '\n';
	}
	return 0;
}