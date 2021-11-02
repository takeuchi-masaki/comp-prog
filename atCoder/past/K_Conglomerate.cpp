#include <bits/stdc++.h>
using namespace std;



void dfs(int currMember, vector<vector<int>> & subordinates, vector<int> & euler_tour){
    euler_tour.push_back(currMember);
    for(int direct_junior : subordinates[currMember]){
        dfs(direct_junior, subordinates, euler_tour);
        euler_tour.push_back(currMember);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;

    vector< vector<int> > subordinates(n);
    int bigBoss;
    for(int i = 0; i < n; i++){
        int boss;
        cin >> boss;
        if(boss == -1){
            bigBoss = i;
            continue;
        }
        subordinates[boss-1].push_back(i);
    }
    
    vector<int> euler_tour;
    dfs(bigBoss, subordinates, euler_tour);

    /*
        1 2 3 4 5 6 7
          1 1 2 2 3 3

            1
        2       3
    4     5   6   7        
    */
    for(int i : euler_tour){
        cout << i+1 << ' ';
    }
    // int q; cin >> q;
    // for(int i = 0; i < q; i++){
    //     int a, b; cin >> a >> b;
        
    // }
}