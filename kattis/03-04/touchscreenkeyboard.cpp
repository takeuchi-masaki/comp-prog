#include <bits/stdc++.h>
using namespace std;

vector<string> K = {
    "qwertyuiop",
    "asdfghjkl",
    "zxcvbnm"
};
unordered_map<char, pair<int, int>> M;

void solve(){
    string original;
    int n;
    cin >> original >> n;
    vector<pair<int, string>> words(n);
    for(int i = 0; i < n; i++){
        auto& [dist, w] = words[i];
        cin >> w;
        for(int j = 0; j < original.size(); j++){
            auto& [x1, y1] = M[original[j]];
            auto& [x2, y2] = M[w[j]];
            dist += abs(x1 - x2) + abs(y1 - y2);
        }
    }
    sort(words.begin(), words.end());
    for(auto& [dist, word] : words){
        cout << word << ' ' << dist << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    for(int i = 0; i < K.size(); i++){
        for(int j = 0; j < K[i].size(); j++){
            M[K[i][j]] = {i, j};
        }
    }

    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}