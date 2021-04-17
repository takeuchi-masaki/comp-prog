#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<int> q;
        unordered_set<int> set(n); 
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            q.push(temp);
            p[i] = temp;
            set.insert(temp);
        }
        deque<int> dq;
        for(int i = n-1; i >= 0; i--){
            while(!set.count(q.top())){
                q.pop();
            }
            int target = q.top();
            q.pop();
            int cnt = 0;
            while(i >= 0 && p[i] != target){
                i--;
                ++cnt;
            }
            int iCopy = i;
            for(int j = iCopy; j < iCopy + cnt; j++){
                dq.push_back(p[j]);
                set.erase(p[j]);
            }
        }
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
}