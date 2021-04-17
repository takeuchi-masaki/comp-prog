#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i:a) cin >> i;
    int factor2 = 0;
    int factor4 = 0;
    int other = 0;
    for(int i:a){
        if(i%4==0){
            factor4++;
        } else if(i%2==0){
            factor2++;
        } else {
            other++;
        }
    }
    bool ok = factor4>=other;
    ok |= (factor2 == 0 && other == factor4+1);
    cout << (ok?"Yes":"No");
}