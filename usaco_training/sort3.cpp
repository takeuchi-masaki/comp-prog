/*
ID: themasa1
TASK: sort3
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("sort3.in","r",stdin); freopen("sort3.out","w",stdout);
    int n; cin >> n;
    vector<int> count(3), award(n);
    for(int i = 0; i < n; i++){
        cin >> award[i];
        award[i]--;
        count[award[i]]++;
    }

    vector< vector<int> > count_in_range(3, vector<int>(3));
    for(int i = 0; i < count[0]; i++){
        count_in_range[0][award[i]]++;
    }
    for(int i = count[0]; i < count[0]+count[1]; i++){
        count_in_range[1][award[i]]++;
    }
    for(int i = count[0]+count[1]; i < n; i++){
        count_in_range[2][award[i]]++;
    }

    int trade_count = 0;
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++){
        if(i == j) continue;
        if(count_in_range[i][j]){
            trade_count += count_in_range[i][j];
            count_in_range[j][j] += count_in_range[i][j];
            if(count_in_range[i][j] <= count_in_range[j][i]){
                count_in_range[i][i] += count_in_range[i][j];
                count_in_range[j][i] -= count_in_range[i][j];
            } else {
                count_in_range[i][i] += count_in_range[j][i];
                count_in_range[i][3-i-j] += count_in_range[i][j]-count_in_range[j][i];
                count_in_range[j][3-i-j] -= count_in_range[i][j]-count_in_range[j][i];
                count_in_range[j][i] = 0;
            }
            count_in_range[i][j] = 0;
        }
    }

    // for(int i = 0; i < 3; i++){
    //     cout << "section " << i << '\n';
    //     for(int j = 0; j < 3; j++){
    //         cout << count_in_range[i][j] << '\n';
    //     }
    //     cout << '\n';
    // }

    cout << trade_count << '\n';
    return 0;
}