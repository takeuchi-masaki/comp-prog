/*
 Source: Codeforces
 Link: https://codeforces.com/problemset/problem/242/B
 */

























/*
 ---------C++--------:
 
 #include <iostream>
 #include <vector>
 using namespace std;
 const int INF = 1e9 + 5;
  
 int main() {
     int n;
     cin >> n;
     vector<int> L(n), R(n);
      
     int left = INF, right = 0;                  // Sentinal values
  
     for (int i = 0; i < n; i++) {
         cin >> L[i] >> R[i];
         left = min(left, L[i]);
         right = max(right, R[i]);
     }
  
     for (int i = 0; i < n; i++) {
         if (left == L[i] && right == R[i]) {
             cout << i + 1;
             return 0;
         }
     }
  
     cout << -1;
     return 0;
 }
 
 
 
 
 -------Python-------:
 
 n = int(input())
 L, R = [], []
  
 for _ in range(n):
     a, b = map(int, input().split())
     L.append(a)
     R.append(b)
  
 left, right = min(L), max(R)
  
 for i in range(n):
     if left == L[i] and right == R[i]:
         print(i + 1)
         exit()
  
 print(-1)
 
 
 
 
 
 --------Java--------:
 
 import java.util.Scanner;
 import java.util.ArrayList;
 import java.lang.Math;
  
 public class Main {
     static final int INF = (int)1e9 + 5;
  
     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         int n = sc.nextInt();
         ArrayList<Integer> L = new ArrayList<>(), R = new ArrayList<>();
  
         int left = INF, right = 0;              // Sentinal values
          
         for (int i = 0; i < n; i++) {
             L.add(sc.nextInt());
             R.add(sc.nextInt());
             left = Math.min(left, L.get(i));
             right = Math.max(right, R.get(i));
         }
  
         for (int i = 0; i < n; i++) {
             if (left == L.get(i) && right == R.get(i)) {
                 System.out.print(i + 1);
                 return;
             }
         }
  
         System.out.print(-1);
     }
 }
 
 
 */







