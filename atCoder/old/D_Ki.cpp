#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adjacent;
vector<long long> count;

void add_dfs(int p, int parent){
    for(int i:adjacent[p]){
        if(i==parent){
            continue;
        }
        count[i]+=count[p];
        add_dfs(i,p);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    adjacent = vector<vector<int>> (n+1,vector<int>());
    count = vector<long long> (n+1);
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    for(int i = 0; i < q; i++){
        int p,x;
        cin >> p >> x;
        count[p]+=x;
    }
    add_dfs(1,0);
    for(int i=1; i <=n; i++){
        cout << count[i] << " ";
    }
    cout << '\n';
}