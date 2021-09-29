#include <iostream>
#include <string>
using namespace std;

int convert16bitbinary(string input){
    if(input.length() > 16) return -1;
    int ans = 0;
    for(int i = input.size()-1; i >= 0; i--){
        if(input[i]=='1'){
            // bitwise leftshift
            ans += 1<<(15-i);
        }
    }
    return ans;
}

long long convert32bithex(string input){
    if(input.size() > 8) return -1;
    long long ans = 0;
    long long hex = 1;
    for(int i = input.size()-1; i >= 0; i--){
        int num;
        if(input[i]<'A'){
            num = input[i]-'0';
        } else {
            num = input[i]-'A'+10;
        }
        // cout << input[i] << ' ' << num << endl;
        ans += num * hex;
        hex *= 16;
    }
    return ans;
}

int main(){
    freopen("out.txt", "w", stdout);

    /* max numbers */
    string binary16 = "1111111111111111";
    string hex32 = "FFFFFFFF";
    cout << convert16bitbinary(binary16) << endl;
    cout << convert32bithex(hex32) << endl << endl;
    
    /* random numbers */
    binary16 = "1010001110100011";
    hex32    = "1B495FC0";
    
    cout << convert16bitbinary(binary16) << endl;
    cout << convert32bithex(hex32) << endl;
}