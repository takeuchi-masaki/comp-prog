#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,k;
    cin >> a >> b >> k;
    unordered_set<int> set;
    for(int i = a; i < a+k && i<=b; i++){
        set.insert(i);
        cout << i << '\n';
    }
    for(int i = b-k+1; i>=a && i<=b; i++){
        if(set.count(i)) continue;
        cout << i << '\n';
    }
}