#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector< pair<int,int> > stores(n);
    for(int i = 0; i < n; i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        stores[i]=make_pair(temp1,temp2);
    }
    sort(stores.begin(),stores.end());
    long long rem = m, currStore = 0, cost = 0;
    while(rem > 0){
        pair<int,int> nextStore = stores[currStore++];
        cost+=min((long long)nextStore.second,rem)*nextStore.first;
        rem-=min((long long)nextStore.second,rem);
    }
    cout << cost << endl;
}