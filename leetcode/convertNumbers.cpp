#include <iostream>
#include <string>
using namespace std;

int convert16bitbinary(string input){
    if(input.length() > 16) return -1;
    int ans = 0;
    for(int i = input.size()-1; i >= 0; i--){
        if(input[i]=='1'){
            // bitwise leftshift
            ans += 1<<(input.size()-1-i);
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
    // freopen("out.txt", "w", stdout);

    /* max numbers */
    string binary16 = "1111111111111111";
    string hex32 = "FFFFFFFF";
    cout << convert16bitbinary(binary16) << '\n' << (1<<16)-1 << '\n';
    cout << convert32bithex(hex32) << '\n' << (1LL<<32)-1 << "\n\n";
    
    /* random numbers */
    binary16 = "1010001110100011";
    hex32    = "1B495FC0";
    cout << convert16bitbinary(binary16) << '\n';
    cout << convert32bithex(hex32) << "\n\n";

    /* small numbers */
    binary16 = "1001";
    hex32 = "1001";
    cout << convert16bitbinary(binary16) << '\n';
    cout << convert32bithex(hex32) << '\n';
}