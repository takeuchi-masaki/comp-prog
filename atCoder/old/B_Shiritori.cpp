#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    int n;
    cin >> n;
    string prev;
    unordered_set<string> set;
    cin >> prev;
    set.insert(prev);
    bool ok = true;
    for(int i = 1; i < n; i++){
        string curr;
        cin >> curr;
        if(curr[0]!=prev[prev.length()-1]){
            ok = false;
            break;
        } else {
            if(set.count(curr)){
                ok = false;
                break;
            } else {
                set.insert(curr);
                prev = curr;
            }
        }
    }
    cout << (ok?"Yes":"No") << endl;
}