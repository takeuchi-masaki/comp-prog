/*
 Source: Codeforces
 Link: https://codeforces.com/problemset/problem/518/A
 */

























/*
 ---------C++--------:
 
 #include <iostream>
 #include <string>
 using namespace std;
  
 int main() {
     string s, t;
     cin >> s >> t;
  
     for (int i = s.size() - 1; i >= 0; i--) {
         if (s[i] == 'z') {
             s[i] = 'a';
         }
         else {
             s[i]++;
             break;
         }
     }
  
     cout << (s == t ? "No such string" : s);
     return 0;
 }
 
 
 
 -------Python-------:
 
 s = list(input())
 t = list(input())
  
 for i in range(len(s) - 1, -1, -1):
     if s[i] == 'z':
         s[i] = 'a'
     else:
         s[i] = chr(ord(s[i]) + 1)
         break
  
 print(''.join(s) if s != t else "No such string")
 
 
 
 
 
 --------Java--------:
 
 import java.util.Scanner;
 import java.util.Arrays;
  
 public class Main {
     public static void main(String[] agrs) {
         Scanner sc = new Scanner(System.in);
         char s[] = sc.next().toCharArray();
         char t[] = sc.next().toCharArray();
  
         for (int i = s.length - 1; i >= 0; i--) {
             if (s[i] == 'z') {
                 s[i] = 'a';
             }
             else {
                 s[i]++;
                 break;
             }
         }
  
         System.out.print(Arrays.equals(s, t) ? "No such string".toCharArray() : s);
     }
 }
 
 
 */







