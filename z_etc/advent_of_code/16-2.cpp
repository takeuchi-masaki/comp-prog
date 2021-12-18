#include <bits/stdc++.h>
using std::string, std::cin, std::cout;

string bin_str = "";

long long getPacket(int& currIdx);

string to_bin(long long num){
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

long long to_ll(string bin){
    long long ret = 0;
    for(int i = bin.size() - 1; i >= 0; i--){
        if(bin[i] == '1'){
            int complement = bin.size() - 1 - i;
            ret += 1ll << complement;
        }
    }
    return ret;
}

long long getLiteral(int& currIdx){
    string literal_num_bin = "";
    while(bin_str[currIdx++] == '1'){
        for(int i = 0; i < 4; i++, currIdx++){
            literal_num_bin.push_back(bin_str[currIdx]);
        }
    }
    for(int i = 0; i < 4; i++, currIdx++){
        literal_num_bin.push_back(bin_str[currIdx]);
    }
    long long literal_num = to_ll(literal_num_bin);
    
    return literal_num;
}

long long sumPackets(int& currIdx){
    long long currSum = 0;
    char length_type_ID = bin_str[currIdx++];
    if(length_type_ID == '0'){
        string subpacket_len_str = bin_str.substr(currIdx, 15);
        currIdx += 15;
        int subpacket_len = to_ll(subpacket_len_str);
        int targetIdx = currIdx + subpacket_len;
        while(currIdx < targetIdx){
            currSum += getPacket(currIdx);
        }
    } else if(length_type_ID == '1'){
        string subpacket_cnt_str = bin_str.substr(currIdx, 11);
        currIdx += 11;
        int subpacket_cnt = to_ll(subpacket_cnt_str);
        for(int i = 0; i < subpacket_cnt; i++){
            currSum += getPacket(currIdx);
        }
    }
    return currSum;
}

long long multPackets(int& currIdx){
    long long currProduct = 1;
    char length_type_ID = bin_str[currIdx++];
    if(length_type_ID == '0'){
        string subpacket_len_str = bin_str.substr(currIdx, 15);
        currIdx += 15;
        int subpacket_len = to_ll(subpacket_len_str);
        int targetIdx = currIdx + subpacket_len;
        while(currIdx < targetIdx){
            currProduct *= getPacket(currIdx);
        }
    } else if(length_type_ID == '1'){
        string subpacket_cnt_str = bin_str.substr(currIdx, 11);
        currIdx += 11;
        int subpacket_cnt = to_ll(subpacket_cnt_str);
        for(int i = 0; i < subpacket_cnt; i++){
            currProduct *= getPacket(currIdx);
        }
    }
    return currProduct;
}

long long minPackets(int& currIdx){
    long long currMin = 1e18;
    char length_type_ID = bin_str[currIdx++];
    if(length_type_ID == '0'){
        string subpacket_len_str = bin_str.substr(currIdx, 15);
        currIdx += 15;
        int subpacket_len = to_ll(subpacket_len_str);
        int targetIdx = currIdx + subpacket_len;
        while(currIdx < targetIdx){
            currMin = std::min(currMin, getPacket(currIdx));
        }
    } else if(length_type_ID == '1'){
        string subpacket_cnt_str = bin_str.substr(currIdx, 11);
        currIdx += 11;
        int subpacket_cnt = to_ll(subpacket_cnt_str);
        for(int i = 0; i < subpacket_cnt; i++){
            currMin = std::min(currMin, getPacket(currIdx));
        }
    }
    return currMin;
}

long long maxPackets(int& currIdx){
    long long currMax = 0;
    char length_type_ID = bin_str[currIdx++];
    if(length_type_ID == '0'){
        string subpacket_len_str = bin_str.substr(currIdx, 15);
        currIdx += 15;
        int subpacket_len = to_ll(subpacket_len_str);
        int targetIdx = currIdx + subpacket_len;
        while(currIdx < targetIdx){
            currMax = std::max(currMax, getPacket(currIdx));
        }
    } else if(length_type_ID == '1'){
        string subpacket_cnt_str = bin_str.substr(currIdx, 11);
        currIdx += 11;
        int subpacket_cnt = to_ll(subpacket_cnt_str);
        for(int i = 0; i < subpacket_cnt; i++){
            currMax = std::max(currMax, getPacket(currIdx));
        }
    }
    return currMax;
}

long long greaterThanPackets(int& currIdx){
    char length_type_ID = bin_str[currIdx++];
    if(length_type_ID == '0'){
        string subpacket_len_str = bin_str.substr(currIdx, 15);
        currIdx += 15;
    } else if(length_type_ID == '1'){
        string subpacket_cnt_str = bin_str.substr(currIdx, 11);
        currIdx += 11;
    }
    long long firstVal = getPacket(currIdx);
    long long secondVal = getPacket(currIdx);
    return firstVal > secondVal;
}

long long lessThanPackets(int& currIdx){
    char length_type_ID = bin_str[currIdx++];
    if(length_type_ID == '0'){
        string subpacket_len_str = bin_str.substr(currIdx, 15);
        currIdx += 15;
    } else if(length_type_ID == '1'){
        string subpacket_cnt_str = bin_str.substr(currIdx, 11);
        currIdx += 11;
    }
    long long firstVal = getPacket(currIdx);
    long long secondVal = getPacket(currIdx);
    return firstVal < secondVal;
}

long long equalToPackets(int& currIdx){
    char length_type_ID = bin_str[currIdx++];
    if(length_type_ID == '0'){
        string subpacket_len_str = bin_str.substr(currIdx, 15);
        currIdx += 15;
    } else if(length_type_ID == '1'){
        string subpacket_cnt_str = bin_str.substr(currIdx, 11);
        currIdx += 11;
    }
    long long firstVal = getPacket(currIdx);
    long long secondVal = getPacket(currIdx);
    return firstVal == secondVal;
}

long long getPacket(int& currIdx){
    string packet_ver_str = bin_str.substr(currIdx, 3);
    currIdx += 3;
    int packet_ver = to_ll(packet_ver_str);

    string packet_type_str = bin_str.substr(currIdx, 3);
    currIdx += 3;
    int packet_type = to_ll(packet_type_str);

    if(packet_type == 4){
        return getLiteral(currIdx);
    }
    
    switch(packet_type){
        case 0:
            return sumPackets(currIdx);
        case 1:
            return multPackets(currIdx);
        case 2:
            return minPackets(currIdx);
        case 3:
            return maxPackets(currIdx);
        case 5:
            return greaterThanPackets(currIdx);
        case 6:
            return lessThanPackets(currIdx);
        case 7:
            return equalToPackets(currIdx);
    }

    return 0;
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
    cout << getPacket(currIdx) << '\n';
}