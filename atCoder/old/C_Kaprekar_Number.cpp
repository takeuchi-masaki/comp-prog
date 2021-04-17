#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int f;
    f = n;
    while(k--){
        string curr = to_string(f);
        priority_queue<char> descending;
        for(char c: curr){
            descending.push(c);
        }
        int size = descending.size();
        int count = 0;
        string asc = "";
        string des = "";
        while(!descending.empty()){
            char next = descending.top();
            asc = next + asc;
            des = des + next;
            descending.pop();
        }
        int num1 = atoi(des.c_str());
        int num2 = atoi(asc.c_str());
        f = num1 - num2;
    }
    cout << f;
}

