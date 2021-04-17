#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    deque<int> a;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        a.push_back(temp);
    }
    while(!a.empty()){
        cout << a.front() << " ";
        a.pop_front();
        if(!a.empty()){
            cout << a.back() << " ";
            a.pop_back();
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}