#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i:a) cin >> i;
    int res = 1;
    int state = 0;
    for(int i = 1; i < n; i++){
        int currState;
        if(a[i]==a[i-1]){
            currState = 0;
        } else if(a[i]>a[i-1]){
            currState = 1;
        } else {
            currState = -1;
        }
        if(currState == 0){
            currState = state;
        }
        if(state == 0){
            state = currState;
        } else {
            if(state != currState){
                ++res;
                state = 0;
            }
        }
    }
    cout << res << endl;
}