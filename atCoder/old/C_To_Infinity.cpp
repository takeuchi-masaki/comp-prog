#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    long long k;
    cin >> s >> k;
    long long count = 0;
    for(int i = 0; i < s.length(); i++){
        int num = (int)s[i]-(int)'0';
        long long add = 1;
        count+=add;
        if(num!=1){
            count = k;
        }
        if(count == k) {
            cout << num << endl;
            return 0;
        }
    }
}