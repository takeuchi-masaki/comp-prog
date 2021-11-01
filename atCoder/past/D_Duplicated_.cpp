#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<bool> a(n);
    int extra = -1;
    for(int i = 0; i < n; i++){
        int number; cin >> number;
        if(a[number-1]){
            extra = number;
        }
        a[number-1] = true;
    }
    int bad = -1;
    if(extra != -1){
        for(int i = 0; i < n; i++){
            if(!a[i]){
                bad = i+1;
            }
        }
    }
    if(extra == -1){
        cout << "Correct\n";
    } else {
        cout << extra << ' ' << bad << '\n';
    }
}