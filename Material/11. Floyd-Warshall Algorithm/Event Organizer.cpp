/*
 Source: Codechef
 Link: https://www.codechef.com/problems/MAXCOMP
 */

























/*
 ---------C++--------:
 
 #include <bits/stdc++.h>
 #define MAX 48
 using namespace std;

 int dist[MAX + 1][MAX + 1];

 void FloydWarshall() {
     for (int k = 0; k <= MAX; k++) {
         for (int i = 0; i <= MAX; i++) {
             for (int j = 0; j <= MAX; j++) {
                 if (i <= k && k <= j) {
                     dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
                 }
             }
         }
     }
 }

 int main() {
     int T, N, S, E, C;
     cin >> T;

     while (T--) {
         cin >> N;
         for (int i = 0; i <= MAX; i++) {
             for (int j = 0; j <= MAX; j++) {
                 dist[i][j] = 0;
             }
         }

         for (int i = 0; i < N; i++) {
             cin >> S >> E >> C;
             if (C > dist[S][E]) {
                 dist[S][E] = C;
             }
         }

         FloydWarshall();
         cout << dist[0][MAX] << endl;
     }
     return 0;
 }
 
 
 
 
 -------Python-------:
 
 MAX = 48

 def FloydWarshall():
     for k in range(MAX + 1):
         for i in range(MAX + 1):
             for j in range(MAX + 1):
                 if i <= k <= j:
                     dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j])

 T = int(input())
 for _ in range(T):
     N = int(input())
     dist = [[0] * (MAX + 1) for i in range(MAX + 1)]
     
     for i in range(N):
         S, E, C = map(int, input().split())
         if C > dist[S][E]:
             dist[S][E] = C
     
     FloydWarshall()
     print(dist[0][MAX])
 
 
 
 
 
 --------Java--------:
 
 import java.util.*;

 public class Main {
     static final int MAX = 48;
     static int[][] dist = new int[MAX + 1][MAX + 1];

     public static void FloydWarshall() {
         for (int k = 0; k <= MAX; k++) {
             for (int i = 0; i <= MAX; i++) {
                 for (int j = 0; j <= MAX; j++) {
                     if (i <= k && k <= j) {
                         dist[i][j] = Math.max(dist[i][j], dist[i][k] + dist[k][j]);
                     }
                 }
             }
         }
     }

     public static void main(String[] agrs) {
         Scanner sc = new Scanner(System.in);
         int T = sc.nextInt();

         while (T-- > 0) {
             int N = sc.nextInt();
             for (int i = 0; i <= MAX; i++) {
                 Arrays.fill(dist[i], 0);
             }
             
             for (int i = 0; i < N; i++) {
                 int S = sc.nextInt();
                 int E = sc.nextInt();
                 int C = sc.nextInt();
                 if (C > dist[S][E]) {
                     dist[S][E] = C;
                 }
             }

             FloydWarshall();
             System.out.println(dist[0][MAX]);
         }
     }
 }
 
 
 */







