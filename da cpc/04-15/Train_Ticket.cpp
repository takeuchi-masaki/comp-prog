#include <bits/stdc++.h>
using namespace std;

void solve(){
    string abcd;
    cin >> abcd;
    vector<int> nums(4);
    for(int i = 0; i < 4; i++){
        nums[i] = abcd[i] - '0';
    }
    for(int add1 = 0; add1 <= 1; add1++){
        for(int add2 = 0; add2 <= 1; add2++){
            for(int add3 = 0; add3 <= 1; add3++){
                int curr = nums[0];
                if(add1){
                    curr += nums[1];
                } else {
                    curr -= nums[1];
                }
                if(add2){
                    curr += nums[2];
                } else {
                    curr -= nums[2];
                }
                if(add3){
                    curr += nums[3];
                } else {
                    curr -= nums[3];
                }
                if(curr == 7){
                    cout << nums[0];
                    cout << (add1 ? "+" : "-");
                    cout << nums[1];
                    cout << (add2 ? "+" : "-");
                    cout << nums[2];
                    cout << (add3 ? "+" : "-");
                    cout << nums[3] << "=7\n";
                    return;
                }
            }
        }
    }
    exit(1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}