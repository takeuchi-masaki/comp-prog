#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    // left black
    // right black
    long long sum = 0;
    int bCount = 0;
    for(char c: s){
        if(c == 'B'){
            bCount++;
        } else {
            sum+=bCount;
        }
    }
    cout << sum << endl;
}