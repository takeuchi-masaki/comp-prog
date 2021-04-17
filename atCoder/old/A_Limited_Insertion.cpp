#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> b(n);
    for(int& i:b)cin>>i;
    for(int i = 0; i < n; i++){
        if(b[i]>(i+1)){
            cout << "-1\n";
            return 0;
        }
    }
    
    vector<bool> use(n,false);
    deque<int> res;
    while(true){
        int cnt = n-res.size();
        bool end = true;
        for(int i = n-1; i >= 0; i--){
            if(use[i]) continue;
            else end = false;
            if(b[i]==cnt) {
                res.push_front(cnt);
                use[i]=true;
                break;
            }
            cnt--;
        }
        if(end) break;
    }

    for(int i:res){
        cout << i << '\n';
    }
}