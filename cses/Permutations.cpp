#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int curr = 2;
    vector<int> ans;
    while(curr <= n){
        ans.push_back(curr);
        curr+=2;
    }
    curr = 1;
    while(curr <= n){
        ans.push_back(curr);
        curr+=2;
    }
    int prev = -1;
    bool output = true;
    for(int i:ans){
        if(abs(i - prev) == 1){
            output = false;
        }
        prev = i;
    }
    if(output){
        for(int i:ans){
            cout << i << ' ';
        }
        cout << endl;
    } else {
        cout << "NO SOLUTION\n";
    }
}