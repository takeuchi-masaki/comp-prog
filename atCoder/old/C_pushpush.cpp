#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    deque<int> dq;
    for(auto& i:a) cin >> i;
    bool addFirst = true;
    for(int i = 0; i < n; i++){
        if(addFirst){
            dq.push_front(a[i]);
        } else {
            dq.push_back(a[i]);
        }
        addFirst = !addFirst;
    }
    for(int i = 0; i < n; i++){
        if(!addFirst){
            cout << dq.front() << ' ';
            dq.pop_front();
        } else {
            cout << dq.back() << ' ';
            dq.pop_back();
        } 
    }
}