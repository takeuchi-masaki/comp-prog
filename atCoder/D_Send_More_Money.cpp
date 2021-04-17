#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

void bad(){
    cout << "UNSOLVABLE\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    int n[3] = { (int)s[0].size(), (int)s[1].size(), (int)s[2].size() };
    if(n[2] < n[0] || n[2] < n[1]) {
        bad();
        return 0;
    }
    unordered_map<char,int> chars;
    int char_cnt = 0;
    for(int cnt = 0; cnt < 3; cnt++){
        int sz = n[cnt];
        for(int i = 0; i < sz; i++){
            char c = s[cnt][i];
            if(chars.count(c)) continue;
            if(char_cnt > 10) {
                bad();
                return 0;
            }
            chars.insert( make_pair(c, char_cnt++) );
        }
    }
    
    vector<char> key(10);
    for(int i = 0; i < 10; i++){
        key[i]= i+'0';
    }

    vector<string> res(3);
    do{
        bool ok = true;
        for(int i = 0; i < 3; i++){
            if( key[ chars[ s[i][0] ] ] == '0' ){
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        for(int i = 0; i < 3; i++){
            res[i].clear();
        }

        for(int cnt = 0; cnt < 3; cnt++){
            for(int i = 0; i < n[cnt]; i++){
                char c = s[cnt][i];
                res[cnt].push_back( key[ chars[c] ] );
            }
        }
        long long a = stoll(res[0]), b = stoll(res[1]), c = stoll(res[2]);
        if(a + b == c) {
            cout << a << '\n' 
                 << b << '\n' 
                 << c << '\n';
            return 0;
        }
    } while(next_permutation(key.begin(),key.end()));

    bad();
    return 0;
}