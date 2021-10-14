#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    map<string, int> m;
    map<int, string> m2;
    while( cin >> s ){
        if(s == "clear"){
            m.clear();
            m2.clear();
            continue;
        } 
        if(s == "def"){
            string name; int num;
            cin >> name >> num;
            if( m.find(name) != m.end() ){
                m2.erase( m[name] );
                m.erase(name);
            }
                m.insert(make_pair(name, num));
                m2.insert(make_pair(num, name));
        } else {
            getline(cin, s);
            s = s.substr(1);
            istringstream ss(s);
            bool unknown = false;
            string start;
            ss >> start;
            int curr;
            if(m.find(start) == m.end()){
                unknown = true;
            }
            else curr = m[start];
            // cout << curr << endl;
            while( !unknown ){
                string op, name;
                ss >> op;
                if(op == "="){
                    break;
                }
                ss >> name;
                if(m.find(name) == m.end()) {
                    unknown = true;
                    break;
                }
                if(op == "+"){
                    curr += m[name];
                } else {
                    curr -= m[name];
                }
                // cout << curr << endl;
            }
            cout << s << " ";
            if( !unknown && m2.find(curr) != m2.end() ) cout << m2[curr] << "\n";
            else cout << "unknown\n";
        }
    }
}