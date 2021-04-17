#include <bits/stdc++.h>
using namespace std;
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    // n towns
    // m roads
    // road ai is road from town Ai to town Bi, takes Ci min
    // valid walk - goes through one or more roads and returns to the town it starts at
    // if yes, find minimum time for walk
    unordered_map<pair<int, int>,int,HASH> map;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(map.find(make_pair(a,b)) == map.end()){
            map.insert(make_pair(make_pair(a,b),c));
        } else {
            if(map[make_pair(a,b)] < c){
                map.emplace(make_pair(a,b),c);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        unordered_set<pair<int,int>,HASH> set;
        

    }
}

