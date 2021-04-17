#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto& i:p) cin >> i;
    int currMin = 1E9, res = 0;
    for(int i:p){
        if(i<=currMin){
            res++;
            currMin = i;
        }
    }
    cout << res << endl;
}