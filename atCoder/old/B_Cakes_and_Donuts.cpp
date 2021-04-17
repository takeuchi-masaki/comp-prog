#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int max4 = n/4 + 1;
    int max7 = n/7 + 1;
    bool possible = false;
    for(int i = 0; i < max7; i++){
        for(int j = 0; j < max4; j++){
            if(7*i + 4*j == n) {
                possible = true;
                break;
            }
        }
    }
    cout << (possible?"Yes":"No");
}