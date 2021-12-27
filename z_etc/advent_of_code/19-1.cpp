#include <bits/stdc++.h>
using namespace std;

struct coordinate{
    int x, y, z;
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in2.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<vector<coordinate>> scan_beacons;

    string line;
    getline(cin, line);
    scan_beacons.push_back(vector<coordinate>());
    while(cin >> line){
        while(line[1] != '-'){
            int comma1 = line.find(',');
            int comma2 = line.find(',', comma1 + 1);
            string x_str = line.substr(0, comma1);
            string y_str = line.substr(comma1 + 1, comma2 - comma1 - 1);
            string z_str = line.substr(comma2 + 1);
            // cout << x_str << ' ' << y_str << ' ' << z_str << '\n';
            coordinate next = {
                stoi(x_str),
                stoi(y_str),
                stoi(z_str)
            };
            scan_beacons.back().push_back(next);
            if(cin.eof()) break;
            cin >> line;
        }
        // cout << '\n';
        if(cin.eof()) break;
        getline(cin, line);
        scan_beacons.push_back(vector<coordinate>());
    }

    // for(auto v : scan_beacons){
    //     for(auto& [x, y, z] : v){
    //         cout << x << ' ' << y << ' ' << z << '\n';
    //     }
    //     cout << '\n';
    // }


}