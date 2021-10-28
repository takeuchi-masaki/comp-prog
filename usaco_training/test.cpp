#include <bits/stdc++.h>
using namespace std;

const int len = 8;

string to_binary(int n){
    string bin = "";
    while(n){
        if(n&1) bin.push_back('1');
        else bin.push_back('0');
        n>>=1;
    }
    while(bin.size() < len){
        bin.push_back('0');
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    while(cin >> n){
        cout << to_binary(n) << '\n';
    }
}