#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> topRow(n), bottomRow(n);
    for(int i = 0; i < n; i++) {
        cin >> topRow[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> bottomRow[i];
    }
    vector<int> sumTop(n+1), sumBottom(n+1);
    for(int i = 0; i < n; i++){
        sumBottom[n-i-1] = sumBottom[n-i] + bottomRow[n-i-1];
        sumTop[i+1] = sumTop[i] + topRow[i];
    }
    int max = 0;
    for(int i = 0; i < n; i++){
        int count = sumTop[i+1]+sumBottom[i];
        // cout << count << endl;
        if(max < count) max = count;
    }
    cout << max;
}