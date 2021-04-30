#include <bits/stdc++.h>
using namespace std;

int getLongestPalindrome(string s){
    int sz = s.size();
    vector<int> pair_start, triplet_start; //pair triplet starting index
    for(int i = 0; i < sz-1; i++){
        if(s[i] == s[i+1]) {
            pair_start.push_back(i);
        }
    }
    for(int i = 0; i < sz-2; i++){
        if(s[i] == s[i+2]) {
            triplet_start.push_back(i);
        }
    }
    int answer = 1;
    // max number of pairs = n-1
    for(int i = 0; i < pair_start.size(); i++){
        int l = pair_start[i];
        int r = l+1;
        int currLen = 2;
        l--, r++;
        while(l>=0 && r<sz && s[l]==s[r]){
            currLen+=2;
            l--, r++;
        }
        answer = max(answer, currLen); 
    // alt: if statement, store longest palindrome
    }
    for(int i = 0; i < triplet_start.size(); i++){
        int l = triplet_start[i];
        int r = l+2;
        int currLen = 3;
        l--, r++;
        while(l>=0 && r<sz && s[l]==s[r]){
            currLen+=2;
            l--, r++;
        }
        answer = max(answer, currLen);
    }
    return answer;
}

int main(){
    freopen("out.txt", "w", stdout);
    cout << getLongestPalindrome("aaaa");
}