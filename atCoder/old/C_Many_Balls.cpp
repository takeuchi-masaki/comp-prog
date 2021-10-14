#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long target;
    cin >> target;
    
    // go backwards from target number
    // if odd, -1
    // if even, divide by 2
    deque<char> ans;
    while(target!=0){
        if(target&1){
            target--;
            ans.push_front('A');
        } else {
            target/=2;
            ans.push_front('B');
        }
    }
    for(char c : ans){
        cout << c;
    }
    cout << endl;
}