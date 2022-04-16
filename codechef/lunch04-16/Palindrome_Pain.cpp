#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
    if(((x&1) && (y&1)) || (x == 1) || (y == 1)){
        cout << "-1\n";
        return;
    }
    string a {}, b {};
    for(int i = 0; i < x/2; i++){
        a.push_back('a');
    }
    for(int i = 0; i < y/2; i++){
        b.push_back('b');
    }
    for(int i = 0; i < x/2; i++){
        b.push_back('a');
    }
    for(int i = 0; i < y/2; i++){
        a.push_back('b');
    }

    cout << a;
	if(x&1){
        cout << 'a';
    } else if(y&1){
        cout << 'b';
    }
    reverse(a.begin(), a.end());
    cout << a << '\n';

    cout << b;
	if(x&1){
        cout << 'a';
    } else if(y&1){
        cout << 'b';
    }
    reverse(b.begin(), b.end());
    cout << b << '\n';
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