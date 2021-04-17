#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    for(auto& i:l){
        cin >> i;
    }
    sort(l.begin(),l.end());
    long long res = 0;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            if(l[j]!=l[i]) {
                for(int k = j+1; k < n; k++){
                    if(l[k]!=l[j] && l[k]!=l[i]) {
                        if(l[i]+l[j]>l[k]
                        && l[j]+l[k]>l[i]
                        && l[i]+l[k]>l[j]){
                            res++;
                        }
                    }
                }
            }
            
        }
    }
    cout << res << endl;
}