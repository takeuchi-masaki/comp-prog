#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    int c = 1;
    while(getline(cin, s)){
        stringstream ss(s);
        vector<int> a;
        int num; ss>>num;
        while(ss>>num){
            a.push_back(num);
        }
        int min = *min_element(a.begin(), a.end());
        int max = *max_element(a.begin(), a.end());
        int range = max-min;
        cout << "Case " << c++ << ": ";
        cout << min << ' ' << max << ' ' << range << '\n';
    }
}