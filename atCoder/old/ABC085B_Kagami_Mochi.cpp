#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        s.emplace(num);
    }
    cout << s.size() << endl;
}