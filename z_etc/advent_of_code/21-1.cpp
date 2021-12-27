#include <bits/stdc++.h>
using namespace std;

const int sides = 100;

int roll(int& dice){
    int ret = dice + 1;
    dice = (dice + 1) % sides;
    return ret;
}

int roll3times(int& dice){
    int ret = 0;
    for(int i = 0; i < 3; i++){
        ret += roll(dice);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    int p1_pos, p2_pos;
    string line;
    getline(cin, line);
    p1_pos = line.back() - '1';
    getline(cin, line);
    p2_pos = line.back() - '1';

    int p1score = 0, p2score = 0, roll_cnt = 0, dice = 0;
    bool currP1 = true;
    while(p1score < 1000 && p2score < 1000){
        int currRoll = roll3times(dice);
        roll_cnt += 3;
        if(currP1){
            p1_pos = (p1_pos + currRoll) % 10;
            p1score += p1_pos + 1;
        } else {
            p2_pos = (p2_pos + currRoll) % 10;
            p2score += p2_pos + 1;
        }
        currP1 = !currP1;
    }
    cout << p1score << ' ' << p2score << ' ' << roll_cnt << '\n';
    cout << min(p1score, p2score) * (long long)roll_cnt << '\n';
}