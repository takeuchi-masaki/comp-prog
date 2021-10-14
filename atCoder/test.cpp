#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int a = 1, d = 3, k = 10;
	long long add = (k/2) * (2*a + (k-1)*d);
	cout << add << endl;
}