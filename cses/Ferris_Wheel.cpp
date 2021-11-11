#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int children_count, maxWeight; cin >> children_count >> maxWeight;
    deque<int> children;
    for(int i = 0; i < children_count; i++){
        int child; cin >> child;
        children.push_back(child);
    }
    sort(children.begin(), children.end());
    int ans = 0;
    while(!children.empty()){
        ans++;
        if(children.size() == 1) break;
        if(children.back() + children.front() > maxWeight){
            children.pop_back();
        } else {
            children.pop_back();
            children.pop_front();
        }
    }
    cout << ans << '\n';
}