#include <bits/stdc++.h>
using namespace std;

void find7777Sum(vector<int> & a){
    set<int> s;
    for(int i:a){
        if(s.count(7777-i)){
            cout << "Yes\n";
            return;
        }
        s.emplace(i);
    }
    cout << "No\n";
}

void findDuplicate(vector<int> & a){
    set<int> s;
    for(int i : a){
        if(s.count(i)){
            cout << "Contains duplicate\n";
            return;
        }
        s.insert(i);
    }
    cout << "Unique\n";
}

void findMode(vector<int> & a){
    map<int,int> m;
    for(int i:a) m[i]++;
    int mode = 0, currNum;
    for(pair<int,int> p:m){
        if(p.second > mode){
            currNum = p.first;
            mode = p.second;
        }
    }
    if(mode > a.size() / 2){
        cout << currNum << '\n';
        return;
    }
    cout << "-1\n";
}

void findMedian(vector<int> & a){
    sort(a.begin(), a.end());
    if(a.size()&1){
        cout << a[a.size()/2] << '\n';
    } else {
        cout << a[a.size()/2 - 1] << ' ' << a[a.size()/2] << '\n';
    }
}

void printRange(vector<int> & a){
    sort(a.begin(), a.end());
    int start = lower_bound(a.begin(), a.end(), 100) - a.begin();
    for(int i = start; i < a.size(); i++){
        if(a[i] > 999) break;
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for(int & i : a) cin >> i;
    switch(t){
        case 1:
            find7777Sum(a);
            break;
        case 2: 
            findDuplicate(a);
            break;
        case 3: 
            findMode(a);
            break;
        case 4: 
            findMedian(a);
            break;
        case 5: 
            printRange(a);
            break;
    }
}