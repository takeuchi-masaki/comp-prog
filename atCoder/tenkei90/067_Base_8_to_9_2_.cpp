#include <bits/stdc++.h>
using namespace std;

long long base8toDec(string n){
    // cout << n << endl;
    long long mult = 1, ans = 0;
    for(int i = n.size()-1; i>=0; i--){
        ans += mult*(n[i]-'0');
        mult *= 8;
    }
    // cout << ans << endl;
    return ans;
}

string decToBase9(long long num){
    string ans = "";
    // cout << num << endl;
    if(num == 0) ans.push_back('0');
    while(num>0){
        ans.push_back(num%9 + '0');
        num/=9;
    }
    // cout << ans << endl;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string n;
    int k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        long long num = base8toDec(n);
        n = decToBase9(num);
        for(char & c:n){
            if(c == '8'){
                c = '5';
            }
        }
    }
    cout << n << endl;
}