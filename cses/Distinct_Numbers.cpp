#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    set<int> s;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        s.emplace(num);
    }
    cout << s.size() << '\n';
}