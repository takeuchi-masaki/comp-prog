/*
ID: themasa1
TASK: namenum
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;
set<string> name_dict;

set<char> possible(int num){
    set<char> ret;
    char add;
    switch(num){
        case 2:
            add = 'A';
            break;
        case 3:
            add = 'D';
            break;
        case 4:
            add = 'G';
            break;
        case 5:
            add = 'J';
            break;
        case 6:
            add = 'M';
            break;
        case 7:
            ret.insert('P');
            ret.insert('R');
            ret.insert('S');
            break;
        case 8:
            add = 'T';
            break;
        case 9:
            add = 'W';
            break;
    }
    if(num!=7){
        for(char c = add; c < add+3; c++){
            ret.insert(c);
        }
    }
    return ret;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict ("dict.txt");
    while(!dict.eof()){
        string name; dict >> name;
        name_dict.insert(name);
    }
    dict.close();
    string serialNum; fin >> serialNum;
    int n = serialNum.size();
    for(int i = 0; i < n; i++){
        int num = serialNum[i]-'0';
        set<char> chars = possible(num);
        vector<string> remove;
        for(string name:name_dict){
            if(chars.count(name[i])) continue;
            remove.push_back(name);
        }
        for(string name:remove){
            name_dict.erase(name);
        }
    }
    vector<string> remove;
    for(string name:name_dict){
        if(name.size()>n) remove.push_back(name);
    }
    for(string name:remove){
        name_dict.erase(name);
    }
    if(name_dict.empty()){
        fout << "NONE\n";
        return 0;
    }
    for(string name:name_dict){
        if(name.size()>n) break;
        fout << name << '\n';
    }
    return 0;
}