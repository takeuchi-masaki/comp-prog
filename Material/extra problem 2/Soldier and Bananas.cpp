/*
 Source: Codeforces
 Link: https://codeforces.com/problemset/problem/546/A
 */

























/*
 ---------C++--------:
 
 #include "iostream"
 using namespace std;

 int main()
 {
     freopen("INPUT.INP", "rt", stdin);
     int k, n, w;
     long long res = 0;
     cin >> k >> n >> w;
     for (int i = 1; i <= w; i++)
     {
         res += i*k;
     }
     if (n >= res)
         cout << "0";
     else
         cout << res - n;
 }
 
 
 
 
 -------Python-------:
 
 k, n, w = map(int, input().split())
 res = 0
  
 for i in range(1, w + 1):
     res += i * k
 if n >= res:
     print(0)
 else:
     print(res - n)
 
 
 
 
 
 --------Java--------:
 
 import java.util.*;
 import java.io.*;

 public class Main
 {
     static PrintWriter out;

     public static void main(String[] args) {
         MyScanner in = new MyScanner();
         out = new PrintWriter(new BufferedOutputStream(System.out), true);
         int k,n,w;
         long res = 0;
         k = in.nextInt();
         n = in.nextInt();
         w = in.nextInt();
         for (int i = 1; i <= w; i++)
         {
                 res += i*k;
         }
         if (n >= res)
                 out.printf("%d",0);
         else
                 out.printf("%d",res - n);
     }
     public static class Pair<F,S>{

         public F getFirst() {
             return first;
         }

         public void setFirst(F first) {
             this.first = first;
         }

         public S getSecond() {
             return second;
         }

         public void setSecond(S second) {
             this.second = second;
         }

         public Pair(F first, S second) {
             this.first = first;
             this.second = second;
         }
         public F first;
         public S second;
     }
     public static class MyScanner {
         BufferedReader br;
         StringTokenizer st;

         public MyScanner() {
                 br = new BufferedReader(new InputStreamReader(System.in));
         }
         String next() {
                 while (st == null || !st.hasMoreElements()) {
                         try {
                                 st = new StringTokenizer(br.readLine());
                         } catch (IOException e) {
                                 e.printStackTrace();
                         }
                 }
                 return st.nextToken();
         }
         int nextInt() {
                 return Integer.parseInt(next());
         }
         long nextLong() {
                 return Long.parseLong(next());
         }
         double nextDouble() {
                 return Double.parseDouble(next());
         }
         String nextLine() {
                 String str = "";
                 try {
                         str = br.readLine();
                 } catch (IOException e) {
                         e.printStackTrace();
                 }
                 return str;
         }
     }
 }
 
 
 */







