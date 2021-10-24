#include <bits/stdc++.h>
using namespace std;

void solve(){
    int candidates; cin >> candidates;
    vector<int> votes(candidates);
    for(int i = 0; i < candidates; i++){
        cin >> votes[i];
    }
    int maxVotes = 0, winner = -1;
    for(int i = 0; i < candidates; i++){
        if(votes[i] > maxVotes){
            winner = i+1;
            maxVotes = votes[i];
        } else if(votes[i] == maxVotes){
            winner = -1;
        }
    }
    if(winner == -1) {
        cout << "no winner\n";
        return;
    }
    int voteTotal = 0;
    for(int i:votes){
        voteTotal += i;
    }
    if(maxVotes*2 > voteTotal){
        cout << "majority winner ";
    } else {
        cout << "minority winner ";
    }
    cout << winner << '\n';
}

int main(){
    // test cases
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}