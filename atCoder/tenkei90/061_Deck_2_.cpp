#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    vector<int> front_backwards, back;
    for(int i = 0; i < q; i++){
        int t, x; cin >> t >> x;
        if(t == 1){
            front_backwards.push_back(x);
        } else if(t == 2){
            back.push_back(x);
        } else if(t == 3){
            x--;
            int n = front_backwards.size();;
            if(x < n){
                cout << front_backwards[n-1-x] << '\n';
            } else {
                cout << back[x-n] << '\n';
            }
        }
    }
}