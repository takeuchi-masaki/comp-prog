#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool possible = false;
        if(s[0] != s[s.length()-1]){
            vector<int> open(3,-1);
            open[(int)s[0]-(int)'A'] = 1;
            open[(int)s[s.length()-1] - (int)'A'] = 0;
            {
                int openCount = 0;
                for(char c:s){
                    int num = (int)c - (int) 'A';
                    if(open[num] == 1){
                        openCount++;
                    } else {
                        openCount--;
                        if(openCount<0){
                            break;
                        } 
                    }
                }
                if(openCount == 0) possible = true;
            }
            if(!possible){
                int openCount = 0;
                for(char c:s){
                    int num = (int)c - (int) 'A';
                    if(open[num] == 0){
                        openCount--;
                        if(openCount<0){
                            break;
                        } 
                    } else {
                        openCount++;
                    }
                }
                if(openCount == 0) possible = true;
            }
        }
        cout << (possible?"YES":"NO") << endl;
    }
}