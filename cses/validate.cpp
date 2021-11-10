#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("test_output.txt","r",stdin); 
    freopen("out.txt","w",stdout);
    vector<long long> ans;
    long long ll;
    while(cin >> ll){
        ans.push_back(ll);
    }
    freopen("user_output.txt", "r", stdin);
    int inc = 0;
    while (cin >> ll){
        if(ans[inc] != ll){
            cout << inc << " bad\n";
        }
        inc++;
    }
}