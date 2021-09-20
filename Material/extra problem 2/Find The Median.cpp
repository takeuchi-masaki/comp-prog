/*
 Source:
 Link:
 */

























/*
 ---------C++--------:
 
 #include <bits/stdc++.h>
 using namespace std;

 int main() {
     int n;
     cin >> n;
     vector<int> a(n);
     
     for (int i = 0; i < n; i++) {
         cin >> a[i];
     }
     
     sort(a.begin(), a.end());
     cout << a[n / 2];
     return 0;
 }
 
 
 
 
 -------Python-------:
 
 n = int(input())
 a = list(map(int, input().split()))
 a.sort()
 print(a[n // 2])
 
 
 
 
 
 --------Java--------:
 
 import java.util.*;

 public class Main {
     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         int n = sc.nextInt();
         int a[] = new int[n];

         for (int i = 0; i < n; i++)
             a[i] = sc.nextInt();
         
         Arrays.sort(a);
         System.out.print(a[n / 2]);
     }
 }
 
 
 */







