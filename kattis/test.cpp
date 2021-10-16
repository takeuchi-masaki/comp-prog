#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class X{
    public:
    int a, b, c;
    X(){};
    X(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    bool operator<(const X& x2){
        
    }
};

vector< vector<int> > threeSum(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector< pair<int, int> > > m;
    unordered_set< X > ans;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            m[ nums[i]+nums[j] ].push_back(make_pair(i,j));
        }
    }
    for(int i = 0; i < n; i++){
        if(m.count(-nums[i])){
            for(pair<int,int> p:m[-nums[i]]){
                if(p.first != i && p.second != i){
                    vector<int> sol;
                    sol.push_back(nums[i]);
                    sol.push_back(nums[p.first]);
                    sol.push_back(nums[p.second]);
                    sort(sol.begin(), sol.end());
                    ans.insert(sol);
                }
            }
        }
    }
    vector< vector<int> > ret;
    for(vector<int> v:ans){
        ret.push_back(v);
    }
    return ret;
}

int main(){
    freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    auto start = chrono::steady_clock::now();

    int n[] = {-1,0,1,2,-1,-4};
    vector<int> nums;
    for(int i:n) nums.push_back(i);
    vector< vector<int> > ans = threeSum(nums);

    auto end = chrono::steady_clock::now();
    for(vector<int> v : ans){
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
    }
    cout << chrono::duration_cast<chrono::milliseconds>( end-start ).count() << '\n';
}