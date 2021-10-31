#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int prev; cin >> prev;
    for(int i = 1; i < n; i++){
        int a; cin >> a;
        if(a == prev){
            cout << "stay\n";
        } else if(a < prev){
            cout << "down " << prev-a << '\n';
        } else {
            cout << "up " << a-prev << '\n';
        }
        prev = a;
    }
}