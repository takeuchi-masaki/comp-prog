#include <bits/stdc++.h>
using namespace std;

string pad(string & pin){
    int diff = 3 - pin.size();
    string zero = "";
    while(diff--){
        zero.push_back('0');
    }
    return zero + pin;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int count = 0;
    for(int pin = 0; pin < 1000; pin++){
        string new_pin = to_string(pin);
        new_pin = pad(new_pin);
        int pinIdx = 0;
        for(int i = 0; i < n && pinIdx < 3; i++){
            if(s[i] == new_pin[pinIdx]) pinIdx++;
        }
        if(pinIdx == 3) count++;
    }
    cout << count << '\n';
}