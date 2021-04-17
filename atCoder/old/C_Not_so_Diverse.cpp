#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    unordered_map<int,int> map;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(map.count(temp) == 0){
            map.insert(make_pair(temp,1));
        } else {
            map[temp]++;
        }
    }
    vector<int> count(map.size());
    int index = 0;
    for(auto i : map){
        count[index++] = i.second;
    }
    sort(count.begin(),count.end());
    int res = 0;
    if(map.size()-k<0){
        res = 0;
    } else {
        int nec = map.size()-k;
        index = 0;
        while(nec>0){
            nec--;
            res+=count[index++];
        }
    }
    cout << res << endl;
}