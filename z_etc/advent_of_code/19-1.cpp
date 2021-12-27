#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a(20);
    for(int i = 19; i >= 0; i--) a[19 - i] = i;
    for(int i : a){
        cout << i << ' ';
    }
    cout << '\n';
    sort(a.begin(), a.end());
    for(int i : a) cout << i << ' ';
    cout << '\n';

    
}