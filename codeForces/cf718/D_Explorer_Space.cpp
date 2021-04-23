#include <bits/stdc++.h>
using namespace std;

struct Edge {
    pair<int,int> pos;
    int weights[4];
    Edge(pair<int,int> position, int allweights[4]){
        pos = position;
        
    }
};

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    if(k&1) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << -1 << ' ';
            }
            cout << '\n';
        }
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            int temp; cin >> temp;
            
        }
    }
    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            int temp; cin >> temp;
            
        }
        
    }


}