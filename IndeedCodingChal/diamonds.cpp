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

int dp[2][310]; // left or right, then row
int gra[310][310]; // row, then column
int bor[2][310]; //left and right bounds
bool occ[310];

int main() {
	freopen("diamonds.txt","r",stdin); freopen("diamondsout.txt","w",stdout);

	int t; cin >> t;
	rep(z,t) {
		rep(i,310) {
			dp[0][i] = 0;
			dp[1][i] = 0;
			bor[0][i] = 0;
			bor[1][i] = 0;
			occ[i] = 0;
		}
		rep(i,310) {
			rep(j,310) gra[i][j] = 0;
		}
		int n, m;
		cin >> n >> m;
		rep(i, n) {
			rep(j, m) {
				char tmp; cin >> tmp;
				if (tmp == '.') gra[i][j] = 0;
				else gra[i][j] = 1;
			}
		}
		int left = INF;
		int right = -1;
		//initialize row 1
		rep(j, m) {
			if (gra[0][j] == 1) {
				left = min(left, j);
				right = max(right, j);
			}
		}
		if (right == -1) {
			dp[0][0] = 0;
			dp[1][0] = 0;
			bor[0][0] = m-1;
			bor[1][0] = m-1;
			occ[0] = 0;
		}
		else {
			bor[0][0] = left;
			bor[1][0] = right;
			dp[0][0] = m-1-left;
			dp[1][0] = dp[0][0] + (right - left);
			occ[0] = 1;
		}
		// cout << "ROW0 " << dp[0][0] << " " << dp[1][0] << endl;
		// cout << "BOR " << bor[0][0] << " " << bor[1][0] << endl;
		// cout << "OCC " << occ[0] << endl;

		//end initializing
		for (int i = 1; i < n; i++) {
			right = -1;
			left = INF;
			rep(j,m) {
				if (gra[i][j] == 1) {
					left = min(left, j);
					right = max(right, j);
				}
			}
			if (right == -1) {
				left = bor[0][i-1];
				right = bor[1][i-1];
				occ[i] = 0;
			}
			else {
				occ[i] = 1;
			}
			bor[0][i] = left; 
			bor[1][i] = right;
			//end dumb stuff
			if (occ[i]) {
				dp[0][i] = 1+(bor[1][i] - bor[0][i]) + min(abs(bor[0][i-1]-bor[1][i]) + dp[0][i-1], abs(bor[1][i-1]-bor[1][i]) + dp[1][i-1]); 
				//move right, then either move up left or up right
				dp[1][i] = 1+(bor[1][i] - bor[0][i]) + min(abs(bor[0][i-1]-bor[0][i]) + dp[0][i-1], abs(bor[1][i-1]-bor[0][i]) + dp[1][i-1]);
			}
			else{
				dp[0][i] = 1+dp[0][i-1];
				dp[1][i] = 1+dp[1][i-1];
			}
			// cout << "ROW" << i << " " << dp[0][i] << " " << dp[1][i] << endl;
			// cout << "BOR " << bor[0][i] << " " << bor[1][i] << endl;
		}
		int ans = min(bor[0][n-1] + dp[0][n-1], bor[1][n-1] + dp[1][n-1]);
		cout << ans << '\n';
	}
}