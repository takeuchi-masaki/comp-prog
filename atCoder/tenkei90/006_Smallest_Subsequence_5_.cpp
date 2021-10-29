#include <bits/stdc++.h>
using namespace std;

class Letter{
    public:
    char c;
    int idx;
    Letter(char c, int idx){
        this->c = c;
        this->idx = idx;
    }
};

class custom_compare{
    public:
    bool operator() (Letter & l1, Letter & l2){
        if(l1.c == l2.c){
            return l1.idx > l2.idx;
        } else {
            return l1.c > l2.c;
        }
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    priority_queue<Letter, vector<Letter>, custom_compare> pq;
    int i = 0;
    for(; i < n-k+1; i++){
        pq.push(Letter(s[i], i));
        // cout << s[i];
    }
    // cout << '\n';
    string ans = "";
    ans.push_back(pq.top().c);
    int idxMax = pq.top().idx;
    pq.pop();
    k--;
    while(k){
        pq.push(Letter(s[i], i));
        // cout << s[i];
        i++;
        while(pq.top().idx < idxMax){
            pq.pop();
        }
        ans.push_back(pq.top().c);
        idxMax = pq.top().idx;
        pq.pop();
        k--;
    }
    // cout << '\n';
    cout << ans << '\n';
}