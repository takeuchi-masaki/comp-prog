#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, r, b;
	cin >> n >> r >> b;

    int groups = b + 1;
    int max_len = (r + groups - 1) / groups;
    int avg_len = r / groups;

    while((r != b * avg_len) && r > 0 && b > 0){
        for(int i = 0; i < max_len; i++){
            cout << "R";
        }
        cout << "B";
        r -= max_len;
        b--;
    }
    while(r > b && r > 0 && b > 0){
        for(int j = 0; j < avg_len; j++){
            cout << "R";
        }
        cout << "B";
        r -= avg_len;
        b--;
    }
    if(r == b){
        for(int i = 0; i < b; i++){
            cout << "RB";
        }
        cout << "\n";
        return;
    }
    if(b == 0){
        assert(r <= max_len);
        for(int i = 0; i < r; i++){
            cout << "R";
        }
        cout << "\n";
        return;
    }
    assert(false);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}