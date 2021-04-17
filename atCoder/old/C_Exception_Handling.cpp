#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i:a) cin >> i;
    int max1=0, max2=0;
    for(auto& i:a){
        if(i>max1){
            max2=max1;
            max1=i;
        } else if(i>max2) {
            max2=i;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i]==max1){
            cout << max2 << endl;
        } else {
            cout << max1 << endl;
        }
    }
}