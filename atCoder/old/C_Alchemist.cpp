#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        q.push(temp);
    }
    double max = q.top();
    q.pop();
    for(int i = 1; i < n; i++){
        max = (max+q.top())/2;
        q.pop();
    }
    cout << setprecision(10) << max;
}