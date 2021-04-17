#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    unordered_map<int,int> map(n);
    int num = 0;
    while(m--){
        int s, c;
        cin >> s >> c;
        if(map.find(s) == map.end()){
            map.insert(make_pair(s,c));
        } else {
            if(map.at(s) != c){
                num = -1;
                break;
            }
        }
    }
    if(num == 0){
        if(n!=1 && map.find(1) != map.end() && map.at(1)==0) {
            num = -1;
        } else {
            if(map.find(1) == map.end()){
                int ins = 1;
                if(n == 1){
                    ins = 0;
                }
                map.insert(make_pair(1,ins));
            }
            int mult = 1;
            for(int i = 1; i < n; i++){
                mult*=10;
            }
            num+=map.at(1)*mult;
            for(int i = 2; i <= n; i++){
                mult/=10;
                if(map.find(i) != map.end()){
                    num+=mult*map.at(i);
                }
            }
        }
    }
    cout << num;
}

