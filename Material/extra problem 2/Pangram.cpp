/*
 Source: Codeforces
 Link: https://codeforces.com/problemset/problem/520/A
 */

























/*
 ---------C++--------:
 
 #include <bits/stdc++.h>
 #define MAX 26
 using namespace std;

 int main() {
     int n;
     cin >> n;
     char c;
     bool alphabet[MAX] = {};

     int count = 0;

     for (int i = 0; i < n; i++) {
         cin >> c;
         c = toupper(c);
         
         if (!alphabet[c - 'A']) {
             count++;
             alphabet[c - 'A'] = true;
         }
     }

     cout << (count == 26 ? "YES" : "NO");
     return 0;
 }
 
 
 
 
 -------Python-------:
 
 alphabet = [False] * 26
 n = int(input())
 text = input().upper()

 count = 0

 for c in text:
     if not alphabet[ord(c) - 65]:
         count += 1
         alphabet[ord(c) - 65] = True
     
 print("YES" if count == 26 else "NO")
 
 
 
 
 
 --------Java--------:
 
 import java.util.*;

 public class Main {
     public static void main(String[] agrs) {
         Scanner sc = new Scanner(System.in);
         boolean[] alphabet = new boolean[26];
         int n = sc.nextInt();
         String text = sc.next().toUpperCase();
         
         int count = 0;
         
         for (char c : text.toCharArray()) {
             if (!alphabet[c - 'A']) {
                 count++;
                 alphabet[c - 'A'] = true;
             }
         }
         
         System.out.print(count == 26 ? "YES" : "NO");
     }
 }
 
 
 */







