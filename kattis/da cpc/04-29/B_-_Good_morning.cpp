#include <bits/stdc++.h>
using namespace std;

void solve(){
    int hour1, hour2, min1, min2;
    cin >> hour1 >> hour2 >> min1 >> min2;
    if(hour1 < hour2){
        cout << "Takahashi\n";
    } else if(hour2 < hour1){
        cout << "Aoki\n";
    } else {
        if(min1 <= min2){
            cout << "Takahashi\n";
        } else {
            cout << "Aoki\n";
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    solve();
}