#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> red(vector<pair<int,int>>);

void printvp(vector<pair<int,int>>& vp){
    for(auto& [val, depth] : vp){
        cout << val << ' ' << depth << ", ";
    }
    cout << '\n';
}


vector<pair<int,int>> inputLine(){
    string line;
    getline(std::cin, line);

    vector<pair<int,int>> ret;
    int depth = 0;
    bool tooDeep = false;
    for(int i = 0; i < line.size(); i++){
        if(line[i] >= '0' && line[i] <= '9'){
            ret.push_back(make_pair(line[i] - '0', depth));
        } else {
            if(line[i] == '[' && ++depth > 4) {
                tooDeep = true;
            } else if(line[i] == ']') depth--;
        }
    }
    if(tooDeep) return red(ret);
    return ret;
}


vector<pair<int,int>> red(vector<pair<int,int>> prev){
    // printvp(prev);
    
    vector<pair<int,int>> next;
    bool skip = true;
    while(skip){
        skip = false;
        next.clear();
        for(int i = 0; i < prev.size(); i++){
            if(skip){
                next.push_back(prev[i]);
                continue;
            }
            auto& [val, depth] = prev[i];
            if(depth > 4){
                skip = true;
                if(i - 1 >= 0){
                    next.back().first += val;
                }
                pair<int,int> p{0, depth - 1};
                next.push_back(p);
                i++;
                if(i + 1 >= prev.size()){
                    next.push_back(p);
                } else {
                    auto& [val2, depth2] = prev[i + 1];
                    next.push_back(make_pair(val2 + prev[i].first, depth2));
                    i++;
                }
            } else if(val > 9){
                skip = true;
                next.push_back(make_pair((val / 2), depth + 1));
                next.push_back(make_pair((val + 1) / 2, depth + 1));
            } else {
                next.push_back(prev[i]);
            }
        }
        prev = move(next);
    }
    
    // printvp(prev);
    return prev;
}


vector<pair<int,int>> combine(vector<pair<int,int>>& v1, vector<pair<int,int>>& v2){
    vector<pair<int,int>> ret;
    bool needReduce = false;
    for(auto& [val, depth] : v1){
        ret.push_back(make_pair(val, depth + 1));
        if(val > 9 || depth + 1 > 4) needReduce = true;
    }
    for(auto& [val, depth] : v2){
        ret.push_back(make_pair(val, depth + 1));
        if(val > 9 || depth + 1 > 4) needReduce = true;
    }
    
    if(needReduce) return red(ret);
    return ret;
}


int magnitude(vector<pair<int,int>> prev){
    while(prev.size() > 2){
        vector<pair<int,int>> next;
        for(int i = 0; i < prev.size(); i++){
            if(i + 1 < prev.size() && prev[i].second == prev[i + 1].second){
                int mag = prev[i].first * 3 + prev[i + 1].first * 2;
                int depth = prev[i].second - 1;
                next.push_back(make_pair(mag, depth));
                i++;
            } else {
                next.push_back(prev[i]);
            }
        }
        prev = move(next);
    }
    
    return prev[0].first * 3 + prev[1].first * 2;
}


int main(){
    freopen("in2.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<pair<int,int>> prev{inputLine()};
    while(!cin.eof()){
        vector<pair<int,int>> next{inputLine()};
        prev = combine(prev, next);
    }
    printvp(prev);
    cout << magnitude(prev) << '\n';
}