#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int a[4]={};
    a[0] = s[0]-'0';
    a[1] = s[1]-'0';
    a[2] = s[2]-'0';
    a[3] = s[3]-'0';
    for(int bit = 0; bit < 1<<3; bit++){
        int sum = a[0];
        bool add[3];
        for(int i = 0; i < 3 ; i++){
            if(bit&(1<<i)){
                sum+=a[i+1];
                add[i] = true;
            } else {
                sum-=a[i+1];
                add[i] = false;
            }
        }
        if(sum == 7){
            cout << a[0];
            for(int i = 1; i < 4; i++){
                cout << (add[i-1]?"+":"-") << a[i];
            }
            cout << "=7" << endl;
            return 0;
        }
    }
}