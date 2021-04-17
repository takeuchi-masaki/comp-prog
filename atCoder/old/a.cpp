#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<int,int> map;

int main(){
    vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    for(int i = 0; i < (int)a.size(); i++){
        map[a[i]]++;
    }
    sort(a.begin(),a.end(),[](int a, int b){
        if(map[a] == map[b]){
            return a < b;
        } else {
            return map[a] < map[b];
        }
    });
    for(int i : a){
        cout << i << endl;
    }
}
