#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    deque<int> dq;
    int minNum; cin >> minNum;
    dq.push_back(minNum);
    for(int i = 1; i < n; i++){
        int next; cin >> next;
        if(next < minNum){
            dq.push_front(next);
            minNum = next;
        } else {
            dq.push_back(next);
        }
    }
    while(!dq.empty()){
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}