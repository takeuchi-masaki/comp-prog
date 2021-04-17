#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    int x[n][d];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cin >> x[i][j];
        }
    }
    unordered_set<int> squares;
    for(int i = 0; i*i < 40000; i++){
        squares.insert(i*i);
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int sum = 0;
            for(int k = 0; k < d; k++){
                int subtract = abs(x[i][k]-x[j][k]);
                sum += subtract*subtract;
            }
            if(squares.find(sum) != squares.end()) ++count;
        }
    }
    cout << count;
}