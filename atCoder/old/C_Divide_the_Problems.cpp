#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int> q;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        q.push(temp);
    }
    for(int i = 0; i < n/2-1; i++){
        q.pop();
    }
    int big = q.top();
    q.pop();
    cout << big - q.top() << endl;
}