#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    unordered_map<string,int> m1, m2;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        m1[s]++;
    }
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        m2[s]++;
    }
    int cnt = 0;
    for(auto p:m1){
        if(m2.count(p.first)){
            cnt+=min(p.second, m2[p.first]);
        }
    }
    cout << cnt << endl;
}