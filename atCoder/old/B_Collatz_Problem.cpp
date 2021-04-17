#include <bits/stdc++.h>
using namespace std;
int f(int n){
    if(n&1){
        return 3*n+1;
    } else {
        return n/2;
    }
}

int main(){
    int s;
    cin >> s;
    unordered_set<int> set;
    set.insert(s);
    // vector<int> a(s+1);
    int prev = s;
    for(int i = 2; i <= 1000000; i++){
        prev = f(prev);
        // cout << prev << endl;
        if(set.count(prev)){
            cout << i;
            break;
        } else {
            set.insert(prev);
        }
    }
}