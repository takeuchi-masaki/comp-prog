#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i:a)cin >> i;
    int res = 0;
    for(int i : a){
        int count = 0;
        while(i>1){
            if(i&1){
                break;
            }
            i>>=1;
            count++;
        }
        res += count;
    }
    cout << res << endl;
}