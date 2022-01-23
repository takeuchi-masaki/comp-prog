#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    
    stack<int> st;
    int ans = 0;
    for(int i : a){
        while(!st.empty() && st.top() < i){
            st.pop();
            ans++;
        }
        if(!st.empty()) ans++;
        st.push(i);
    }
    cout << ans << '\n';
}