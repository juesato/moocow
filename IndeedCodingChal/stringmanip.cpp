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

#define INF 9999999

int cur[510], need[510], cop[510]; //int repres, cop is a copy to cycle need

int main() {
	freopen("strman.txt","r",stdin); freopen("strmanout.txt","w",stdout);

	int t; cin >> t;
	rep(z,t) {
		rep(i, 510) {
			cur[i] = 0;
			need[i] = 0;
			cop[i] = 0;
		}
		int ans = INF;
		string s1, s2;
		cin >> s1 >> s2;
		int len = s2.length();
		rep(i,len) {
			cur[i] = s1[i] - 'a';
		}
		rep(i,len) {
			need[i] = s2[i] -'a';
		}
		
		// rep(i, s1.length()) cout << cur[i];
		// cout << "WAS CUR" << endl;
		// rep(i, s2.length()) cout << need[i];
		// cout << "WAS NEED" << endl;
		rep(i, len) {
			int tmp = 0;
			rep(j, s2.length()) {
				tmp += min(abs(need[j] - cur[j]), 26 - abs(need[j] - cur[j]));
				// cout << "TMP IS " << tmp << endl;
			}
			//rotate array
			rep(j, s2.length()-1) cop[j+1] = need[j];
			cop[0] = need[s2.length()-1];
			rep(j, s2.length()) need[j] = cop[j];
			
			// rep(j, s2.length()) cout << need[j];
			// cout << endl;
			
			int score = min(i, len-i) + tmp;
			ans = min(score, ans);
		}
		cout << ans << '\n';
	}
}