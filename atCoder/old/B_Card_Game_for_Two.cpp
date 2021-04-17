#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int> q;
    for(int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    long long sumA = 0, sumB = 0;
    int count = 0;
    while(!q.empty()){
        if((count&1)==0){
            sumA+=q.top();
        } else {
            sumB+=q.top();
        }
        q.pop();
        count++;
    }
    cout << sumA-sumB << endl;
}