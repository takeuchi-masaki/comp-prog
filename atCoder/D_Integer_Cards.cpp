#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int card_count, m; cin >> card_count >> m;
    priority_queue<int> a;
    for(int i = 0; i < card_count; i++){
        int num; cin >> num;
        a.push(num);
    }
    priority_queue<pair<int,int>> operations;
    for(int i = 0; i < m; i++){
        pair<int,int> op;
        cin >> op.second >> op.first;
        operations.push(op);
    }
    
    int count = card_count;
    long long ans = 0;
    while(count > 0){
        if(operations.empty() || operations.top().first < a.top()) {
            ans += a.top();
            a.pop();
            count--;
        } else {
            int add = min(count, operations.top().second);
            count -= add;
            ans += (long long)operations.top().first * add;
            operations.pop();
        }
    }
    cout << ans << '\n';
}