/*
 Source: UVA
 Link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1552
 */

























/*
 ---------C++--------:
 
 #include <cstdio>
 #include <iostream>
 #include <algorithm>
 #include <vector>
 using namespace std;

 int main(){
     // freopen("test.in", "rt", stdin);
     ios::sync_with_stdio(false);

     int n, q, x, pos;
     vector<int> a;

     cin >> n;
     for (int i = 0; i < n; i++){
         cin >> x;
         a.push_back(x);
     }
     cin >> q;
     while (q--){
         cin >> x;
         pos = lower_bound(a.begin(), a.end(), x) - a.begin();
         if (pos == 0)
             cout << "X ";
         else
             cout << a[pos-1] << " ";
         pos = upper_bound(a.begin(), a.end(), x) - a.begin();
         if (pos == n)
             cout << "X\n";
         else
             cout << a[pos] << "\n";
     }

     return 0;
 }
 
 
 
 
 -------Python-------:
 
 import sys

 def inp():
     return map(int, input().split())


 def solve():
     n = int(input())
     a = list(inp())

     q = int(input())
     query = list(inp())
     for x in query:
         pos = -1
         l = 0
         r = n-1
         while l <= r:
             mid = int( (l + r) / 2 )
             if a[mid] < x:
                 pos = max(pos, mid)
                 l = mid + 1
             else:
                 r = mid - 1
         if pos == -1:
             ans = "X"
         else:
             ans = str(a[pos])

         pos = n
         l = 0
         r = n - 1
         while l <= r:
             mid = int( (l + r) / 2)
             if a[mid] > x:
                 pos = min(pos, mid)
                 r = mid - 1
             else:
                 l = mid + 1
         if pos == n:
             ans += " X"
         else:
             ans += " " + str(a[pos])

         print(ans)


 solve()
 
 
 
 
 
 --------Java--------:
 
 import sys

 def inp():
     return map(int, input().split())


 def solve():
     n = int(input())
     a = list(inp())

     q = int(input())
     query = list(inp())
     for x in query:
         pos = -1
         l = 0
         r = n-1
         while l <= r:
             mid = int( (l + r) / 2 )
             if a[mid] < x:
                 pos = max(pos, mid)
                 l = mid + 1
             else:
                 r = mid - 1
         if pos == -1:
             ans = "X"
         else:
             ans = str(a[pos])

         pos = n
         l = 0
         r = n - 1
         while l <= r:
             mid = int( (l + r) / 2)
             if a[mid] > x:
                 pos = min(pos, mid)
                 r = mid - 1
             else:
                 l = mid + 1
         if pos == n:
             ans += " X"
         else:
             ans += " " + str(a[pos])

         print(ans)


 solve()
 
 
 */







