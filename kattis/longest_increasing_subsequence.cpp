#include <bits/stdc++.h>
using namespace std;

/*
    0 1 0 3 2 3
    0
    0 1
    0 1
    0 1 3
    0 1 2
    0 1 2 3
*/

/*
    [4,10,4,3,8,9]
    4
    4 10
    4 10
    3 10
    3 8
    3 8 9
*/

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1) return n;
    vector<int> min_at_len;
    min_at_len.push_back(nums[0]);
    for(int i = 1; i < n; i++){
        int m = min_at_len.size();
        if(nums[i] > min_at_len[m-1]){
            min_at_len.push_back(nums[i]);
            continue;
        }

        // TODO: log n optimization
        for(int j = 0; j < m; j++){
            if(nums[i] <= min_at_len[j]){
                min_at_len[j] = nums[i];
                break;
            }
        }
    }
    return min_at_len.size();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a;
    int num;
    while (cin >> num){
        a.push_back(num);
    }
    // for(int i:a) cout << i << ' ';
    // cout << '\n';
    cout << lengthOfLIS(a) << endl;
}