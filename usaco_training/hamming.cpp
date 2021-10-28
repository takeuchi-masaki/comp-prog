/*
ID: themasa1
TASK: hamming
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
int n, b, d;

int convertBinary(string num){
    int mult = 1, val = 0;
    while(num.size()){
        char c = num.back();
        num.pop_back();
        if(c == '1') val += mult;
        mult*=2;
    }
    return val;
}

string convertDecimal(int n){
    string bin = "";
    while(n){
        if(n&1) bin.push_back('1');
        else bin.push_back('0');
        n>>=1;
    }
    while(bin.size() < b){
        bin.push_back('0');
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

bool hammingDistance(string s1, string s2){
    int dist = 0;
    for(int i = 0; i < b; i++){
        if(s1[i] != s2[i]) dist++;
        if(dist >= d) return true;
    }
    return false;
}

int main() {
    freopen("hamming.in","r",stdin); freopen("hamming.out","w",stdout);
    // n count
    // b bitlen
    // d hamming distance
    cin >> n >> b >> d;
    vector<string> ans;
    ans.push_back(convertDecimal(0));
    n--;
    for(int bit = 1; bit < (1<<b); bit++){
        string num = convertDecimal(bit);
        bool ok = true;
        for(int i = 0; ok && i < ans.size(); i++){
            if(!hammingDistance(num, ans[i])) ok = false;
        }
        if(ok) {
            ans.push_back(num);
            if(--n == 0) break;
        }
    }

    for(int i = 0; i < ans.size(); i++){
        if((i+1)%10 == 0 || i == ans.size()-1){
            cout << convertBinary(ans[i]) << '\n';
        } else {
            cout << convertBinary(ans[i]) << ' ';
        }
    }
    return 0;
}