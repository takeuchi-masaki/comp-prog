#include <ctime>
#include <fstream>
#include <random>
using namespace std;

int main() {
	srand(time(0));
	const int T = 1e6;
	ofstream fout { "out.txt" };
	fout << fixed << setprecision(2);
	const int DECK_COSMOS = 2;
	for (int decksize = 15; decksize <= 25; decksize++) {
		fout << decksize << " cards in deck: ";
		int success = 0;
		for (int trial = 0; trial < T; trial++) {
			bool ok = false;
			int total = decksize;
			for (int i = 0; i < 5; i++) {
				if (rand() % total < DECK_COSMOS) {
					ok = true;
					break;
				}
				total--;
			}
			success += ok;
		}
		fout << (long double)success * 100 / T << "%\n";
	}
}