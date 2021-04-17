#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    int nums[26] = {};
    for(int i = 0; i < s.size(); i++){
        nums[s[i]-'a']++;
    }
    for(int i = 1; i < n; i++){
        int cnt[26]={};
        cin >> s;
        for(int j = 0; j<s.size(); j++){
            cnt[s[j]-'a']++;
        }
        for(int j = 0; j < 26; j++){
            nums[j]=min(nums[j], cnt[j]);
        }
    }
    string res = "";
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < nums[i]; j++){
            res.push_back((char)(i+'a'));
        }
    }
    cout << res << '\n';
}