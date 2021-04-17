#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    priority_queue<int> heap;
    while(t--){
        int num;
        cin >> num;
        heap.push(num);
    }
    int cost = 0;
    while(!heap.empty()){
        cost += heap.top();
        heap.pop();
        if(heap.empty()) break;
        cost += heap.top();
        heap.pop();
        if(heap.empty()) break;
        heap.pop();
    }
    cout << cost;
}

