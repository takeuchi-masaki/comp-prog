#include <bits/stdc++.h>
using namespace std;

class Player{
    public:
    int wins, id;
    Player(int w, int i){
        wins = w;
        id = i;
    }
    Player(){}
    bool operator< (const Player& p2){
        if(this->wins == p2.wins){
            return this->id < p2.id;
        } else {
            return this->wins > p2.wins;
        }
    }
};

// class Compare{
//     public:
//     bool operator() (Player p1, Player p2){
//         if(p1.wins == p2.wins){
//             return p1.id < p2.id;
//         } else {
//             return p1.wins > p2.wins;
//         }
//     }
// };

vector< vector<char> >choice;

int p1Win(Player p1, Player p2, int round){
    char p1choice = choice[p1.id][round], 
         p2choice = choice[p2.id][round];
    // cout << p1.id+1 << ' ' << p1choice << ' ' << p2.id+1 << ' ' << p2choice << endl;
    if(p1choice == p2choice) return -1;
    switch(p1choice){
        case 'G':
            if(p2choice == 'C') return 1;
            if(p2choice == 'P') return 0;
        case 'C':
            if(p2choice == 'G') return 0;
            if(p2choice == 'P') return 1;
        case 'P':
            if(p2choice == 'G') return 1;
            if(p2choice == 'C') return 0;
    }
    return true;
}

void printAll(vector<Player> ranking){
    for(Player p:ranking){
        cout << p.id+1 << ' ' << p.wins << '\n';
    }
    cout << endl;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    choice = vector< vector<char> >(2*n, vector<char>(m));
    for(int i = 0; i < 2*n; i++){
        for(int j = 0; j < m; j++){
            cin >> choice[i][j];
        }
    }
    
    vector<Player> ranking;
    for(int i = 0; i < 2*n; i++){
        ranking.push_back(Player(0, i));
    }
    sort(ranking.begin(), ranking.end());
    for(int r = 0; r < m; r++){
        for(int k = 1; k <= n; k++){
            Player p1 = ranking[2*k-2];
            Player p2 = ranking[2*k-1];
            int winner = p1Win(p1, p2, r);
            if( winner==1 ) p1.wins++;
            else if( winner==0 ) p2.wins++;
            ranking[2*k-2] = p1, ranking[2*k-1] = p2;
        }
        sort(ranking.begin(), ranking.end());
        // printAll(ranking);
    }
    for(Player p:ranking) cout << p.id+1 << endl;
}