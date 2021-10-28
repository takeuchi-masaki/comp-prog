/*
ID: themasa1
TASK: combo
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("combo.in");
ofstream fout ("combo.out");

struct combi{
    int one, two, three;
    combi(int i, int j, int k){
        one = i;
        two = j;
        three = k;
    }
    bool eq(combi& c){
        if(one == c.one 
        && two == c.two
        && three == c.three){
            return true;
        }
        return false;
    }
};

int main() {
    int n;
    fin >> n;
    int combination[2][3];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            fin >> combination[i][j];
            // fout << combination[i][j] << ' ';
        }
        // fout << endl;
    }
    vector< vector<int> > possible(3, vector<int>());
    for(int i = 0; i < 3; i++){
        int comb = combination[0][i];
        for(int j = -2; j <= 2; j++){
            int num = comb+j;
            while(num > n) num-=n;
            while(num<=0) num+=n;
            possible[i].push_back(num);
            // fout << num << ' ';
        }
        // fout << endl;
    }
    // fout << endl;
    vector< vector<int> > possible2(3, vector<int>());
    for(int i = 0; i < 3; i++){
        int comb = combination[1][i];
        for(int j = -2; j <= 2; j++){
            int num = comb+j;
            while(num > n) num-=n;
            while(num<=0) num+=n;
            possible2[i].push_back(num);
            // fout << num << ' ';
        }
        // fout << endl;
    }
    // fout << endl;

    vector<combi> res;
    for(int i = 0; i < possible[0].size(); i++){
        int one = possible[0][i];
        for(int j = 0; j < possible[1].size(); j++){
            int two = possible[1][j];
            for(int k = 0; k < possible[2].size(); k++){
                int three = possible[2][k];
                combi add = combi(one, two, three);
                bool ok = true;
                for(combi c:res){
                    if(add.eq(c)) {
                        ok = false;
                        break;
                    }
                }
                if(ok) res.push_back(add);
                // fout << one << ' ' << two << ' ' << three << endl;
            }
        }
    }
    // fout << res.size() << '\n';
    for(int i = 0; i < possible2[0].size(); i++){
        int one = possible2[0][i];
        for(int j = 0; j < possible2[1].size(); j++){
            int two = possible2[1][j];
            for(int k = 0; k < possible2[2].size(); k++){
                int three = possible2[2][k];
                combi add = combi(one, two, three);
                bool ok = true;
                for(combi c : res){
                    if(add.eq(c)) {
                        // fout << one << ' ' << c.one << endl
                        //     << two << ' ' << c.two << endl
                        //     << three << ' ' << c.three << endl << endl;
                        ok = false;
                        break;
                    }
                }
                if(ok) res.push_back(add);
            }
        }
    }
    // for(combi c:res){
    //     fout << c.one << ','
    //         << c.two << ','
    //         << c.three << endl;
    // }
    fout << res.size() << '\n';
    return 0;
}