#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    if(s.size()==0) return s;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            string reduced = "";
            if(i>0){
                reduced += s.substr(0,i);
            }
            if(i+2<s.size()){
                reduced += s.substr(i+2);
            }
            return superReducedString(reduced);
        }
    }
    return s;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("out.txt", "w", stdout);
    string s;
    getline(cin, s);

    string result = superReducedString(s);

    cout << result << "\n";

    return 0;
}
