#include <iostream>

using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii

char board[10][10];
pii dirs[4] = {pii(1,0), pii(1,1), pii(-1,1), pii(0,1)}

bool valid(int i, int j) {
	return (i >= 2 && i < 5 && j >= 2 && j < 5);
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[2+i][2+j]
		}
	}
	for (int i = 2; i < 5; i++) {
		for (int j = 2; j < 5; j++) {
			for (int k = 0; k < 4; k++) {
				int xs = 0, os = 0;
				pii dir = dirs[k];
				for (int z = 0; z < 3; z++) {
					if (valid(i + z*dir.fi, j + z*dir.se)) {
						if (board[i + z*dir.fi][j + z*dir.se] == 'x') xs++;
						else if (board[i + z*dir.fi][j + z*dir.se] == 'o') os++;
					}
				}
				if (xs == 2 && os == 0) return 1;
			}
		}
	}
	return 0;
}