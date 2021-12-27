#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> reduce(vector<pair<int,int>>& v);

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
    if(tooDeep) return reduce(ret);
    return ret;
}


vector<pair<int,int>> reduce(vector<pair<int,int>>& v){
    printvp(v);
    
    vector<pair<int,int>> ret;
    for(int i = 0; i < v.size(); i++){
        auto& [val, depth] = v[i];
        if(val > 9){
            ret.push_back(make_pair((val / 2), depth + 1));
            ret.push_back(make_pair((val + 1) / 2, depth + 1));
        } else if(depth > 4){
            pair<int,int> p{0, depth - 1};
            if(i > 0) p.first = val + v[i - 1].first;
            ret.back() = p;
            // if(i + 1 < v.size()){
            //     p = {0, depth - 1};
            //     auto& [val2, depth2] = 
            //     if(i + 2 < v.size()){
            //         // p.first = 
            //     }
            // }
        } else {
            ret.push_back(v[i]);
        }
    }

    printvp(ret);
    return ret;
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
    
    if(needReduce) return reduce(ret);
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