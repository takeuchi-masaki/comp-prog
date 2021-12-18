#include <bits/stdc++.h>
using std::string, std::cin, std::cout;

int packet_ver_total = 0;
string bin_str = "";

string to_bin(int num){
    string ret = "";
    while(num){
        if(num&1){
            ret.push_back('1');
        } else {
            ret.push_back('0');
        }
        num >>= 1;
    }
    // pad number with zeros
    while(ret.size() < 4){
        ret.push_back('0');
    }
    reverse(ret.begin(), ret.end()); 
    return ret;
}

int to_int(string bin){
    int ret = 0;
    for(int i = bin.size() - 1; i >= 0; i--){
        if(bin[i] == '1'){
            int complement = bin.size() - 1 - i;
            ret += 1 << complement;
        }
    }
    return ret;
}

int getLiteral(int& currIdx){
    string literal_num_bin = "";
    while(bin_str[currIdx++] == '1'){
        for(int i = 0; i < 4; i++, currIdx++){
            literal_num_bin.push_back(bin_str[currIdx]);
        }
    }
    for(int i = 0; i < 4; i++, currIdx++){
        literal_num_bin.push_back(bin_str[currIdx]);
    }
    int literal_num = to_int(literal_num_bin);
    
    return literal_num;
}

void getPacket(int& currIdx){
    string packet_ver_str = bin_str.substr(currIdx, 3);
    currIdx += 3;
    int packet_ver = to_int(packet_ver_str);
    packet_ver_total += packet_ver;

    string packet_type_str = bin_str.substr(currIdx, 3);
    currIdx += 3;
    int packet_type = to_int(packet_type_str);

    if(packet_type == 4){
        getLiteral(currIdx);
    } else {
        char length_type_ID = bin_str[currIdx++];
        if(length_type_ID == '0'){
            string subpacket_len_str = bin_str.substr(currIdx, 15);
            currIdx += 15;
            int subpacket_len = to_int(subpacket_len_str);
            int targetIdx = currIdx + subpacket_len;
            while(currIdx < targetIdx){
                getPacket(currIdx);
            }
        } else if(length_type_ID == '1'){
            string subpacket_cnt_str = bin_str.substr(currIdx, 11);
            currIdx += 11;
            int subpacket_cnt = to_int(subpacket_cnt_str);
            for(int i = 0; i < subpacket_cnt; i++){
                getPacket(currIdx);
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);

    // create binary string
    string hex_str;
    getline(cin, hex_str);
    for(char c : hex_str){
        int nextNum;
        if(c >= '0' && c <= '9'){
            nextNum = c - '0';
        } else {
            nextNum = c - 'A' + 10;
        }
        bin_str = bin_str + to_bin(nextNum);
    }
    // cout << hex_str << '\n';
    // cout << bin_str << '\n';
    
    int currIdx = 0;
    getPacket(currIdx);

    cout << packet_ver_total << '\n';
}