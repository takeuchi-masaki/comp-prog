#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> map(n);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        map[i] = temp-1;
    }
    int curr = 0;
    int count = 0;
    bool found = false;
    while(count < n+1){
        curr = map[curr];
        ++count;
        if(curr == 1){
            found = true;
            break;
        }
    }
    cout << (found ? count : -1);
}