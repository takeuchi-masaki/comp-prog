#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0));
	ofstream fout { "out.txt" };
	fout << fixed << setprecision(2);
	vector<int> total_for_pp(10);
	vector<vector<int>> condition(10, vector<int>(4));
	const int mx = 1024;
	for (int bit = 1; bit < mx - 1; bit++) {
		int pp = __builtin_popcount(bit);
		assert(pp < 10);
		total_for_pp[pp]++;
		if (bit & 1) {
			condition[pp][0]++;
			if ((bit >> 1) & 1) {
				condition[pp][1]++;
				if ((bit >> 2) & 1) {
					condition[pp][2]++;
					if ((bit >> 3) & 1) {
						condition[pp][3]++;
					}
				}
			}
		}
	}
	for (int pp = 1; pp < 10; pp++) {
		fout << pp << " pp:\n";
		for (int conds = 0; conds < 4; conds++) {
			fout << conds + 1 << " conditions: " << (long double)condition[pp][conds] * 100 / total_for_pp[pp] << "%\n";
		}
	}
}