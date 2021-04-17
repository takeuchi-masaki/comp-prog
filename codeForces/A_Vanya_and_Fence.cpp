#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, h; cin >> n >> h;
    int res = 0;
    for(int i = 0; i < n; i++){
        int curr; cin >> curr;
        if(curr>h){
            res+=2;
        } else {
            res++;
        }
    }
    cout << res << '\n';
}