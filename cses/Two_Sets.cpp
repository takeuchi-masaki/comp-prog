#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long curr1 = 0, curr2 = 0;
    vector<int> l1, l2;
    int n; cin >> n;
    for(int i = n; i > 0; i--){
        if(curr1 <= curr2){
            curr1 += i;
            l1.push_back(i);
        } else {
            curr2 += i;
            l2.push_back(i);
        }
    }
    if(curr1 != curr2){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    reverse(l1.begin(), l1.end());
    reverse(l2.begin(), l2.end());
    cout << l1.size() << '\n';
    for(int i:l1) cout << i << ' ';
    cout << '\n';
    cout << l2.size() << '\n';
    for(int i:l2) cout << i << ' ';
    cout << '\n';
}