#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> food(m);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int num;
            cin >> num;
            food[num-1]++;
        }
    }
    int res = 0;
    for(int i:food){
        if(i==n) res++;
    }
    cout << res << endl;
}