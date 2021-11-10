#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, p, m; cin >> n >> p >> m;
    map<string, int> players;
    for(int i = 0; i < n; i++){
        string name; cin >> name;
        players[name] = 0;
    }
    bool noWinner = true;
    for(int i = 0; i < m; i++){
        string name;
        int score;
        cin >> name >> score;
        players[name] += score;
        if(players[name] >= p && players[name]-score < p){
            noWinner = false;
            cout << name << " wins!\n";
        }
    }
    
    cout << players.begin()->first  << ' ' << players.begin()->second << '\n';
    cout << players.rbegin()->first << ' ' << players.rbegin()->second << '\n';

    if(noWinner){
        cout << "No winner!\n";
    }
}