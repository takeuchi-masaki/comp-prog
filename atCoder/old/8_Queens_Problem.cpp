#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printGrid(vector<vector<bool>>& res){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(res[i][j]){ cout << 'Q'; }
            else { cout << '.'; }
        }
        cout << '\n';
    }
}

bool bad_diag(vector<vector<bool>>& cantUse, int i, int j){
    int iCopy = i, jCopy = j;
    while(i>0 && j>0){
        i--,j--;
    }
    while(i<8 && j<8){
        if(cantUse[i][j]) {
            // if( i!=iCopy || j != jCopy){
                return true;
            // }
        }
        i++,j++;
    }
    i = iCopy, j = jCopy;
    while(i>0 && j<7){
        i--,j++;
    }
    while(i<8 && j>=0){
        if(cantUse[i][j]) {
            // if( i != iCopy || j != jCopy){
                return true;
            // }
        }
        i++,j--;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> useX(8,-1);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        useX[x]=y;
    }
    vector<int> perm(8); // permutation
    for(int i = 0; i < 8; i++){ perm[i]=i; }
    do{
        bool ok = true;
        for(int i = 0; i < 8; i++){
            if(useX[i]==-1) continue;
            if(useX[i]!=perm[i]){ ok = false; break; }
        }
        if(!ok) continue;
        vector<vector<bool>> grid(8,vector<bool>(8,false));
        for(int i = 0; i < 8; i++){
            if(bad_diag(grid,i,perm[i])){ ok = false; break; }
            grid[i][perm[i]]=true;
        }
        if(!ok) continue;
        printGrid(grid);
        return 0;
    } while(next_permutation(perm.begin(),perm.end()));
    return 0;
}