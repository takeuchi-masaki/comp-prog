/*
ID: themasa1
TASK: gift1
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np;
    fin >> np;
    unordered_map<string, int> balance;
    vector<string> order;
    for(int i = 0; i < np; i++){
        string name; fin >> name;
        balance.insert(make_pair(name,0));
        order.push_back(name);
    }
    for(int i = 0; i < np; i++){
        string name; fin >> name;
        int money, ng; 
        fin >> money >> ng;
        if(ng == 0) continue;
        int give = money/ng;
        int rem = money%ng;
        balance[name] += rem-money;
        for(int j = 0; j < ng; j++){
            string recip; 
            fin >> recip;
            balance[recip] += give;
        }
    }
    for(int i = 0; i < np; i++){
        fout << order[i] << " " << balance[order[i]] << '\n';
    }
    return 0;
}