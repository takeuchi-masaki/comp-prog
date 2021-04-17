#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        unordered_map<int,long long> map;
        unordered_set<int> set;
        for(int i = 0; i < n; i++){
            long long temp;
            cin >> temp;
            map.insert(make_pair(i,temp));
        }
        int maxPos = 0;
        for(int i = 0; i < m; i++){
            int temp;
            cin >> temp;
            set.insert(temp);
            maxPos = temp;
        }
        // check special pos count
        // check if at least n special positions clumped exist before nth box
        vector<int> ic(m);
        int initial_count = 0;
        for(int i = 0; i < m; i++){
            if(set.count(i)){
                initial_count++;
            }
            ic[i] = initial_count;
        }
        int res = 0;
        for(int i = n-1; i > 0; i--){
            long long upbound = map.at(i);
            long long lowbound = map.at(i-1);
            int localMax = 0;
            for(int j = lowbound; j <= upbound; j++){
                int posCount = 0;
                while(set.count(j)) {
                    posCount++;
                    j++;
                }
                localMax = max(localMax,posCount);
            }
            localMax += ic[i];
            res = max(res,localMax);
        }
        cout << res << endl;
    }
}