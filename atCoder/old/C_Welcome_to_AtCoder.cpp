#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int penalty = 0, res = 0;
    vector<int> p(n+1);
    for(int i = 0; i < m; i++){
        int prob;
        string judge;
        cin >> prob >> judge;
        if(p[prob]==-1) continue;
        if(judge == "AC"){
            res++;
            penalty+=p[prob];
            p[prob] = -1;
        } else if(judge == "WA") {
            p[prob]++;
        }
    }
    cout << res << " " << penalty << endl;
}