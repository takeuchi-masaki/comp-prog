#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, U, R, D, L;
        cin >> n >> U >> R >> D >> L;
        int uMin = 2 - min(n-U,2);
        int uMax = min(U,2);
        int rMin = 2 - min(n-R,2);
        int rMax = min(R,2);
        int dMin = 2 - min(n-D,2);
        int dMax = min(D,2);
        int lMin = 2 - min(n-L,2);
        int lMax = min(L,2);
        bool possible = false;
        for(int bit = 0; bit < (1<<4); bit++){
            vector<int> c(4);
            for(int i = 0; i < 4; i++){
                if(bit & (1<<i)) c[i] = 1;
            }
            if(c[0]+c[1] >= uMin && c[0]+c[1] <= uMax
            && c[2]+c[1] >= rMin && c[2]+c[1] <= rMax
            && c[2]+c[3] >= dMin && c[2]+c[3] <= dMax
            && c[0]+c[3] >= lMin && c[0]+c[3] <= lMax){
                possible = true;
                break;
            }
        }
        cout << (possible?"YES":"NO") << endl;
    }
}