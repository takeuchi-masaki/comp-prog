#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n+1);
    for(int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        a[temp]++;
    }
    for(int i = 1; i <= n; i++){
        cout << (k-(q-a[i])>0?"Yes":"No") << endl;
    }
}