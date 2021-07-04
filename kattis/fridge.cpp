#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> nums(10, 0);
    nums[0]++;
    for(int i = 0; i < n; i++){
        nums[s[i]-'0']++;
    }
    int curr = -1, currMin = 1005;
    for(int i = 9; i >= 0; i--){
        if(nums[i]<=currMin){
            currMin = nums[i];
            curr = i;
        }
    }
    string ans = "";
    if(curr == 0){
        ans = "1";
    } else {
        currMin++;
    }
    for(int i = 0; i < currMin; i++){
        ans.push_back(curr+'0');
    }
    cout << ans << endl;
}