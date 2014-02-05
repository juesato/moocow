//longest common subsequence

#include <iostream>
#include <string>
using namespace std;

int dp[1000][1000];

int LongCommonSubseq(string str1, string str2) {
	int l1 = str1.length();
	int l2 = str2.length();
	for (int i = 0; i < l1; i++) { //these 2 for loops just initialize borders
		if (str1[l1-i-1] == str2[l2-1]) dp[l1-1-i][l2-1] = 1;
		else dp[l1-1-i][l2-1] = dp[l1-i][l2-1];
	}
	for (int i = 0; i < l2; i++) {
		if (str2[l2-1-i] == str1[l1-1]) dp[l1-1][l2-1-i] = 1;
		else dp[l1-1][l2-1-i] = dp[l1-1][l2-i];
	}
	for (int i = l1-2; i >= 0; i--) {
		for (int j = l2-2; j >= 0; j--) {
			if (str1[i] == str2[j]) {
				dp[i][j] = 1 + dp[i+1][j+1];
			} else {
				dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
			}
		}
	}
	return dp[0][0];
}

void PrintLCS(string str1, string str2) {
	int p1 = 0;
	for (int p = 0; p < str2.length(); p++) {
		if (dp[p1][p] > dp[p1][p+1]) {
			cout << str2[p];
			while (str1[p1] != str2[p]) p1++;
		}
	}
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << LongCommonSubseq(s1, s2) << endl;
	PrintLCS(s1, s2);
}