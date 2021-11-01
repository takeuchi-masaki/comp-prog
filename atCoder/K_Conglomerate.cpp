#include <bits/stdc++.h>
using namespace std;

/*
    1 -> 2 -> 3 -> 4 -> 5 -> 6
    
*/

void dfs(int currMember, vector<int> & higher, vector<vector<int>> & subordinates, vector<vector<bool>> & junior){
    for(int direct_junior : subordinates[currMember]){
        for(int high : higher){
            junior[direct_junior][high] = true;
        }
        higher.push_back(direct_junior);
        dfs(direct_junior, higher, subordinates, junior);
        higher.pop_back();
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

    // for(int i = 0; i < n; i++){
    //     for(int sub:subordinates[i]){
    //         cout << sub << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<vector<bool>> junior(n, vector<bool>(n, false));
    vector<int> higher;
    higher.push_back(bigBoss);
    dfs(bigBoss, higher, subordinates, junior);

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        if(junior[a-1][b-1]){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}