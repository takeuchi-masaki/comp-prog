#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minimumBribes(vector<int> q) {\
    bool chaotic = false;
    for(int i = 0; i < q.size(); i++){
        if(q[i]-(i+1)>2) {
            chaotic = true;
            break;
        }
    }
    if(chaotic){
        cout << "Too chaotic" << endl;
    } else {
        int ans = 0;
        for(int i = 0; i<q.size()-1; i++){
            for(int j = 0; j<q.size()-i-1; j++){
                if(q[j]>q[j+1]){
                    swap(&q[j], &q[j+1]);
                    ans++;
                }
            }
        }
        for(int i:q){
            cout << i << ' ';
        }
        cout << endl;
        cout << ans << endl;
    }
}

int main(){
    
}