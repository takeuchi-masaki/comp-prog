#include <ctime>
#include <fstream>
#include <random>
using namespace std;

int main() {
	srand(time(0));
	const int T = 1e6;
	ofstream fout { "out.txt" };
	fout << fixed << setprecision(2);
	for (int pp = 4; pp < 10; pp++) {
		fout << pp << " pp:\n";
		for (int conditions = 1; conditions <= 4; conditions++) {
			int success = 0;
			for (int trial = 0; trial < T; trial++) {
				int remain = conditions;
				int total = 10;
				for (int i = 0; i < pp; i++) {
					if (rand() % total < remain) {
						remain--;
					}
					total--;
				}
				success += (remain == 0);
			}
			fout << conditions << " Conditions: " << (long double)success * 100 / T << "%\n";
		}
	}
}