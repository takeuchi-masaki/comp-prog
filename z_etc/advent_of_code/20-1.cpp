#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);

    string line, image_algo;
    getline(cin, image_algo);

    vector<string> grid_initial;
    while(cin >> line) grid_initial.push_back(line);

    set<pair<int,int>> lit_pixel;
    int minI = INF, minJ = INF, maxI = -INF, maxJ = -INF;
    for(int i = 0; i < grid_initial.size(); i++){
        for(int j = 0; j < grid_initial[0].size(); j++){
            if(grid_initial[i][j] == '#'){
                lit_pixel.insert(make_pair(i, j));
                minI = min(minI, i);
                minJ = min(minJ, j);
                maxI = max(maxI, i);
                maxJ = max(maxJ, j);
            }
        }
    }
    minI -= 4, maxI += 4, minJ -= 4, maxJ += 4;

    for(int i = minI; i <= maxI; i++){
        for(int j = minJ; j <= maxJ; j++){
            char out = (lit_pixel.count(make_pair(i, j)) ? '#' : '.');
            cout << out;
        }
        cout << '\n';
    }
    cout << '\n';

    for(int enhance = 0; enhance < 2; enhance++){
        set<pair<int,int>> enhanceLitPixel;
        for(int i = minI; i <= maxI; i++){
            for(int j = minJ; j <= maxJ; j++){
                vector<pair<int,int>> coords = {
                    {i - 1, j - 1},
                    {i - 1, j},
                    {i - 1, j + 1},
                    {i, j - 1},
                    {i, j},
                    {i, j + 1},
                    {i + 1, j - 1},
                    {i + 1, j},
                    {i + 1, j + 1}
                };
                int bin_num = 0;
                for(int pixel = 0; pixel < 9; pixel++){
                    if(lit_pixel.count(coords[pixel])){
                        int complement = 8 - pixel;
                        bin_num += 1 << complement;
                    }
                }
                if(image_algo[bin_num] == '#'){
                    enhanceLitPixel.insert(make_pair(i, j));
                }
            }
        }
        lit_pixel.swap(enhanceLitPixel);
        int cnt = 0;
        for(int i = minI + 1; i <= maxI; i++){
            for(int j = minJ + 1; j <= maxJ - 1; j++){
                char out = (lit_pixel.count(make_pair(i, j)) ? '#' : '.');
                cout << out;
                if(out == '#') cnt++;
            }
            cout << '\n';
        }
        cout << cnt << '\n';
        cout << '\n';
    }
    cout << lit_pixel.size() << '\n';
}