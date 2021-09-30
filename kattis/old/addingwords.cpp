#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unordered_map<string, int> def_string;
    unordered_map<int, string> def_num;
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        string func;
        ss >> func;
        if(func[0] == 'd'){
            string str;
            int num;
            ss >> str >> num;
            def_string[str] = num;
            def_num[num] = str;
        } else if(func[1] == 'l'){
            def_string.clear();
            def_num.clear();
        } else {
            cout << line.substr(5) << ' ';
            string input;
            ss >> input;
            bool unknown = !def_string.count(input);
            int curr;
            if(!unknown) curr = def_string[input];
            bool add = true;
            while(!unknown){
                ss >> input;
                if(input == "=") break;
                if(input == "+") { 
                    add = true; 
                    continue;
                } else if(input == "-") {
                    add = false;
                    continue;
                }
                if(!def_string.count(input)){
                    unknown = true;
                } else {
                    if(add) {
                        curr+=def_string[input];
                    } else {
                        curr-=def_string[input];
                    }
                }
            }
            if(unknown || !def_num.count(curr)) {
                cout << "unknown\n";
            } else {
                cout << def_num[curr] << '\n';
            }
        }
    }
    return 0;
}