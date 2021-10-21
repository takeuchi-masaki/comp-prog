#include <bits/stdc++.h>
using namespace std;

bool checkMia(int roll1, int roll2){
    if(roll1 == 1 && roll2 == 2) return true;
    if(roll2 == 1 && roll1 == 2) return true;
    return false;
}

bool checkDoubles(int roll1, int roll2){
    return roll1 == roll2;
}

int highNum(int roll1, int roll2){
    if(roll1 > roll2){
        return roll1*10 + roll2;
    }
    return roll2*10 + roll1;
}

void win(bool p1Win){
    cout << (p1Win?"Player 1 wins.\n":"Player 2 wins.\n");
}

void tie(){
    cout << "Tie.\n";
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int s0, s1, r0, r1;
    while(true){
        cin >> s0 >> s1 >> r0 >> r1;
        if(s0 == 0) break;

        bool ok1, ok2;
        ok1 = checkMia(s0, s1), ok2 = checkMia(r0, r1);
        if(ok1 || ok2){
            if(ok1 != ok2){
                win(ok1);
                continue;
            }
            tie();
            continue;
        }
        
        ok1 = checkDoubles(s0, s1), ok2 = checkDoubles(r0, r1);
        if(ok1 || ok2){
            if(ok1 != ok2){
                win(ok1);
                continue;
            }
            if(s0 == r0) {
                tie();
                continue;
            }
            win(s0 > r0);
            continue;
        }
        
        int high1 = highNum(s0, s1), high2 = highNum(r0, r1);
        if(high1 == high2) {
            tie();
            continue;
        }
        win(high1 > high2);
    }
}