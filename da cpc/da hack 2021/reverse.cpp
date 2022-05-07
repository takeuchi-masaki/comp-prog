#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    vector<int> s(10);
    iota(s.begin(), s.end(), 0);
    for(int i : s) cout << i << ' ';
    cout << endl;
    copy(s.rbegin(), s.rend(), s);
    for(int i : s) cout << i << ' ';
}