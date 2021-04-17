#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string one,two;
    cin >> one >> two;
    int len_one = one.length();
    int len_two = two.length();
    int max;
    if(len_one >= len_two){
        max = len_one;
    } else {
        max = len_two;
    }
    bool carry = false;
    string res = "";
    for(int i = 1; i <= max; i++){
        int index_one = len_one - i;
        int index_two = len_two - i;
        int curr = 0;
        if(index_one >= 0){
            curr += (int)one[index_one] - '0';
        }
        if(index_two >= 0){
            curr += (int)two[index_two] - '0';
        }
        if(carry){
            curr++;
            carry = false;
        }
        if(curr >= 10){
            curr-=10;
            carry = true;
        }
        char temp = curr + '0';
        res = temp + res;
    }
    if(carry){
        res = "1" + res;
    }
    cout << res;
}

