#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s1, s2;
    while(true){
        cin >> s1 >> s2;
        if(s1 == "0" && s2 == "0") break;
        int n = max(s1.size(), s2.size())+1;
        vector<int> num1(n), num2(n);
        int index = 0;
        n = s1.size()-1;
        while(true){
            if(n == -1) break;
            num1[index++] = s1[n--]-'0';
            // cout << num1[index-1];
        }
        // cout << endl;
        n = s2.size()-1, index = 0;
        while(true){
            if(n == -1) break;
            num2[index++] = s2[n--]-'0';
            // cout << num2[index-1];
        }
        n = max(s1.size(), s2.size());
        int ans = 0, carry = 0;
        for(int i = 0; i < n; i++){
            int sum = num1[i] + num2[i] + carry;
            // cout << num1[i] << ' ' << num2[i] << ' ' << carry << '\n';
            if(sum > 9){
                carry = sum/10;
                ans++;
            } else {
                carry = 0;
            }
        }
        if(ans){
            cout << ans << " carry operation";
            cout << ( ans>1 ?"s.\n":".\n");
        } else {
            cout << "No carry operation.\n";
        }
    }
}