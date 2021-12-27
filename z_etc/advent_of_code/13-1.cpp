#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    set<pair<int,int>> s;
    string line;
    getline(cin, line);
    do{
        int comma = line.find(',');
        string num_str1 = line.substr(0, comma);
        string num_str2 = line.substr(comma + 1);
        int num1 = stoi(num_str1);
        int num2 = stoi(num_str2);
        s.insert({num1, num2});
        getline(cin, line);
    } while(line != "");

    vector<pair<int,bool>> folds;
    while(getline(cin, line)){
        char xy = line[11];
        string foldNum_str = line.substr(13);
        int foldVal = stoi(foldNum_str);
        pair<int,bool> nextFold{
            foldVal,
            (xy == 'x')
        };
        folds.push_back(nextFold);
    }

    auto& [val, isX] = folds.front();
    set<pair<int,int>> newSet;
    for(auto& [x, y] : s){
        pair<int,int> newPair = {x, y};
        if(isX && x >= val){
            newPair.first = val - (x - val);
        } else if(!isX && y >= val){
            newPair.second = val - (y - val);
        }
        newSet.insert(newPair);
    }

    cout << newSet.size();
}