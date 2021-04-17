#include <bits/stdc++.h>
using namespace std;

// int rec(int target, vector<int> v, ){

// }

// const int prices[6] = {100,101,102,103,104,105};

int main(){
    int target;
    cin >> target;
    int rem = target%100;
    int count = rem/5;
    rem%=5;
    bool ok;
    if(rem != 0){
        count++;
    }
    ok = count*100 <= target;
    cout << (ok?1:0) << endl;
}