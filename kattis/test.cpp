#include <bits/stdc++.h>
using namespace std;

struct Node{
    int index, weight;
    bool operator< (const Node& n2) const {
        if(this->weight == n2.weight) return this->index < n2.index;
        return this->weight < n2.weight;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    set<Node> s;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            s.insert({i, j});
        }
    }
    for(Node n : s){
        cout << n.index << ' ' << n.weight << '\n';
    }
}