#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> map;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        for(int j = temp-1; j <= temp+1; j++){
            if(map.count(j)){
                map[j]++;
            } else {
                map.insert(make_pair(j,1));
            }
        }
    }
    int val = 0;
    // int res = -1;
    for(auto& i : map){
        if(i.second > val){
            val = i.second;
            // res = i.first;
        }
    }
    cout << val << endl;
}