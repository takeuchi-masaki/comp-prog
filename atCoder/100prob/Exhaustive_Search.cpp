#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    vector<bool> valid(2005);
    valid[0] = true;
    for(int i : a){
        vector<bool> nextValid = valid;
        for(int j = 0; j + i < 2005; j++){
            if(valid[j]) nextValid[j + i] = true;
        }
        valid = move(nextValid);
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int target; cin >> target;
        cout << (valid[target] ? "yes\n" : "no\n");
    }
}