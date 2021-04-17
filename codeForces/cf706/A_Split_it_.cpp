#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t-->0)
	{
		string s;
		int n, k;
		cin >> n >> k >> s;
		bool ok = true;
		// for 1 to k
		int indexR = n-1;
		for(int i = 0; i < k; i++)
		{
			if(s[i]!=s[indexR--])
			{
				ok = false;
				break;
			}
		}
        if(indexR<k) ok = false;
		cout << (ok?"YES":"NO") << endl;
	}
}