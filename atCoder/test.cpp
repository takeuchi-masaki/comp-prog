#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isSubset(vector<int> L, vector<int> B){
	unordered_map<int,int> L_map;
	for(int i:L){
		L_map[i]++;
	}
	for(int i:B){
		if(!L_map.count(i)) return false;
		L_map[i]--;
		if(L_map[i] < 0) return false;
	}
	return true;
}

int main(){
    vector<int> L = {
        1, 2, 3, 4, 5, 6
    };
    vector<int> B = {
        
    };
    
    cout << isSubset(L, B) << '\n';
}