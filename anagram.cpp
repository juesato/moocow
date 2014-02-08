#include <iostream>
#include <vector>
using namespace std;

vector<string> anagrams;

void anag(string match, vector<string> diction) {
	int matchcts[30];
	for (int i = 0; i < 30; i++) matchcts[i] = 0;
	for (int i = 0; i < match.length(); i++) matchcts[match[i] - 'a']++;
	for (int i = 0; i < diction.size(); i++) {
		int compcts[30];
		for (int j = 0; j < 30; j++) compcts[j] = 0;
		word = diction[i];
		if (word.length() <= match.length()) {
			for (int j = 0; j < word.length(); j++) {
				compcts[word[j] - 'a']++;
				if (compcts[word[j] - 'a'] > matchcts[word[j] - 'a'] ) break;
			}
		}
		for (int j = 0; j <= 30; j++) {
			if (j == 30) anagrams.push_back(word);
			if (compcts[j] > matchcts[j]) break;
		}
	}
}