#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    // unordered_map<int,int> index;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        // index.insert(make_pair(a[i],i));
    }
    unordered_map<int, vector< vector<int> > > map;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int sum = a[i]+a[j];
            if(map.count(sum)){
                vector< vector<int> > check = map[sum];
                for( vector<int> p:check){
                    if(p[2] == i || p[2] == j || p[3] == i || p[3] == j){
                        // continue;
                    } else {
                        cout << "YES\n";
                        cout << i+1 << " " << j+1 << " " << p[2]+1 << " " << p[3]+1 << endl;
                        return 0;
                    }
                }
                vector<int> add = {a[i],a[j],i,j};
                check.push_back(add);
                map.insert(make_pair(sum,check));
            } else {
                vector< vector<int> > check;
                vector<int> add = {a[i],a[j],i,j};
                check.push_back(add);
                map.insert(make_pair(sum,check));
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}