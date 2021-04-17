#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long sum = 0;
        bool ok = true;
        vector<int> input(n);
        for(int i = 0; i < n; i++){
            cin >> input[i];
        }
        int nec = 0;
        for(int i = 0; i < n; i++){
            sum+=input[i];
            nec+=i;
            if(sum < nec) ok = false;
        }
        cout << (ok?"YES":"NO") << endl;
    }
}