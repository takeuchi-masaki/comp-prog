#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> student_total(n);
	for (int i = 0; i < n; i++) {
		for (int day = 0; day < 3; day++) {
			int score;
			cin >> score;
			student_total[i] += score;
		}
	}
	vector<int> students_copy = student_total;
	sort(students_copy.rbegin(), students_copy.rend());
	int top_k_cutoff = students_copy[k - 1];

	for (int i: student_total) {
		if (i + 300 >= top_k_cutoff) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}