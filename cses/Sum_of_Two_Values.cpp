#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, target; cin >> n >> target;
    map<int,int> m;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        if(m.count(target - val)){
            cout << m[target - val] + 1 << ' ' << i + 1 << '\n';
            return 0;
        }
        m[val] = i;
    }
    cout << "IMPOSSIBLE\n";
}