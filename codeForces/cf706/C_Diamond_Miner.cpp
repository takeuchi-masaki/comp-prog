#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int t;
    cin >> t;
    cout << setprecision(15);
    while(t--){
        int n;
        cin >> n;
        vector<int> my(n),dx(n); // miner x, y pos , diamond x,y pos
        int mCnt = 0,dCnt=0;
        for(int i = 0; i < 2*n; i++){
            int tempX, tempY;
            cin >> tempX >> tempY;
            if(tempX==0){
                my[mCnt++]=abs(tempY);
            } else {
                dx[dCnt++]=abs(tempX);
            }
        }
        sort(my.begin(),my.end());
        sort(dx.begin(),dx.end());
        double res = 0;
        for(int i = 0; i < n; i++){
            res+=sqrt((double)my[i]*my[i]+(double)dx[i]*dx[i]);
        }
        cout << res << endl;
    }
}