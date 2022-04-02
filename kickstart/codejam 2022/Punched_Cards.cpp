#include <bits/stdc++.h>
using namespace std;

void print_plus_minus(int col){
    cout << "+";
    for(int i = 0; i < col; i++){
        cout << "-+";
    }
    cout << "\n";
}

void print_bar_dot(int col){
    cout << "|";
    for(int i = 0; i < col; i++){
        cout << ".|";
    }
    cout << "\n";
}

void solve(){
    int r, c; cin >> r >> c;
    cout << "..";
    print_plus_minus(c - 1);
    cout << "..";
    print_bar_dot(c - 1);
    for(int i = 0; i < r - 1; i++){
        print_plus_minus(c);
        print_bar_dot(c);
    }
    print_plus_minus(c);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ":\n";
        solve();
    }
}