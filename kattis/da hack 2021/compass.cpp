#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int start, end; cin >> start >> end;
    
    // clockwise
    int s = start, e = end;
    if(s > e){
        e+=360;
    }
    int clockwise = e-s;

    // counter-clockwise
    if(end > start){
        start+=360;
    }
    int counterclockwise = end-start;

    if(clockwise <= abs(counterclockwise)){
        cout << clockwise << endl;
    } else {
        cout << counterclockwise << endl;
    }
}