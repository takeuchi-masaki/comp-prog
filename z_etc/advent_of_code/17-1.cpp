#include <bits/stdc++.h>
using namespace std;

int xMin, yMin, xMax, yMax;

bool simulateXY(int currX, int currY, int velX, int velY){
    if(currX >= xMin && currX <= xMax
    && currY >= yMin && currY <= yMax) return true;
    if(currX > xMax || currY < yMin) return false;
    return simulateXY(currX + velX, currY + velY, max(velX - 1, 0), velY - 1);
}

bool simulateX(int currX, int velX){
    if(currX >= xMin && currX <= xMax) return true;
    if(currX > xMax) return false;
    if(currX < xMin && velX == 0) return false;
    return simulateX(currX + velX, velX - 1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    
    {
        string line;
        getline(cin, line);
        int find_x = line.find('x');
        int x1Begin = find_x + 2;
        int x1End = line.find('.', x1Begin);
        string x1_str = line.substr(x1Begin, x1End - x1Begin);
        xMin = stoi(x1_str);

        int x2Begin = x1End + 2;
        int x2End = line.find(',', x2Begin);
        string x2_str = line.substr(x2Begin, x2End - x2Begin);
        xMax = stoi(x2_str);

        int find_y = line.find('y');
        int y1Begin = find_y + 2;
        int y1End = line.find('.', y1Begin);
        string y1_str = line.substr(y1Begin, y1End - y1Begin);
        yMin = stoi(y1_str);

        int y2Begin = y1End + 2;
        int y2End = line.size();
        string y2_str = line.substr(y2Begin, y2End - y2Begin);
        yMax = stoi(y2_str);
        
        // cout << xMin << ' ' << xMax << ' ' << yMin << ' ' << yMax << '\n';
    }

    // find velocity <x, y> such that
    // y is maximized and target area is reached
    
    // find min valid x, max valid x
    int validXMin, validXMax = xMax;
    {
        int l = 0, r = xMax;
        while(r - l > 1){
            int mid = (l + r)/2;
            if(simulateX(0, mid)){
                r = mid;
            } else {
                l = mid;
            }
        }
        validXMin = r;
    }
    // cout << validXMin << ' ' << validXMax << '\n';

    for(int x = validXMin; x <= validXMax; x++){
        
    }
}