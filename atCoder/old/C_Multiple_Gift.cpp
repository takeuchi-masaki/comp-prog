#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long x, y;
    cin >> x >> y;
    int count = 0;
    while(x <= y){
        count++;
        x = (x << 1);
    }
    cout << count;
}

