#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        q.push(temp);
    }
    int count = 0;
    while(!q.empty()){
        if(x-q.top()>=0){
            x-=q.top();
            q.pop();
            if(q.empty() && x != 0) break;
            count++;
        } else {
            break;
        }
    }
    cout << count << endl;
}