#include <bits/stdc++.h>
using namespace std;

struct City{
    int cityNum, pref, year;
    string ID;
};

bool compCityNum(const City & c1, const City & c2){
    return c1.cityNum < c2.cityNum;
}

bool compCityYear(const City & c1, const City & c2){
    return c1.year < c2.year;
}

string padZeros(string s){
    int diff = 6 - s.size();
    string add = "";
    for(int i = 0; i < diff; i++){
        add.push_back('0');
    }
    return add + s;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> city_count(n + 1);
    vector<City> cities;
    for(int i = 1; i <= m; i++){
        int pref, year; cin >> pref >> year;
        cities.push_back({i, pref, year});
    }

    sort(cities.begin(), cities.end(), compCityYear);
    for(City & c : cities){
        // cout << c.cityNum << ' ' << c.pref << ' ' << c.year << '\n';
        c.ID = padZeros(to_string(c.pref)) 
                + padZeros(to_string(++city_count[c.pref]));
    }

    sort(cities.begin(), cities.end(), compCityNum);
    for(City c : cities){
        cout << c.ID << '\n';
    }
}