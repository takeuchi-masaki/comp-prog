/*
 Source: SPOJ
 Link: https://www.spoj.com/problems/ALLIZWEL/
 */

























/*
 ---------C++--------:
 
 #include <bits/stdc++.h>
 #define MAX 101
 using namespace std;

 const string term = "ALLIZZWELL";
 int R, C;
 bool found;
 int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
 int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};
 bool visited[MAX][MAX];
 char table[MAX][MAX];

 bool isValid(int r, int c) {
     return r >= 0 && c >= 0 && r < R && c < C;
 }

 void DFS(int sr, int sc, int count) {
     if (count == term.size()) {
         found = true;
         return;
     }

     for (int i = 0; i < 8; i++) {
         int r = sr + dr[i];
         int c = sc + dc[i];

         if (isValid(r, c) && table[r][c] == term[count] && !visited[r][c]) {
             visited[r][c] = true;
             DFS(r, c, count + 1);
             visited[r][c] = false;
         }
     }
 }

 int main() {
     int T;
     cin >> T;

     while (T--) {
         cin >> R >> C;

         for (int i = 0; i < R; i++) {
             for (int j = 0; j < C; j++) {
                 cin >> table[i][j];
                 visited[i][j] = false;
             }
         }

         found = false;

         for (int i = 0; i < R; i++) {
             for (int j = 0; j < C; j++) {
                 if (table[i][j] == term[0] && !found) {
                     DFS(i, j, 1);
                 }
             }
         }

         cout << (found ? "YES" : "NO") << endl;
     }
     return 0;
 }
 
 
 
 
 -------Python-------:
 
 import sys
 sys.setrecursionlimit(100000)

 dr = [0, 0, 1, 1, 1, -1, -1, -1]
 dc = [1, -1, 0, 1, -1, 0, 1, -1]
 term = "ALLIZZWELL"

 def DFS(sr, sc, count):
     global found, table, visited
     if count == len(term):
         found = True
         return
     
     for i in range(8):
         r = sr + dr[i]
         c = sc + dc[i]

         if r in range(R) and c in range(C) and table[r][c] == term[count] and not visited[r][c]:
             visited[r][c] = True
             DFS(r, c, count + 1)
             visited[r][c] = False
     
 T = int(input())

 for _ in range(T):
     R, C = map(int, input().split())
     table = []
     visited = [[False] * C for _ in range(R)]

     for i in range(R):
         table.append(input())
     
     found = False

     for i in range(R):
         for j in range(C):
             if table[i][j] == term[0] and not found:
                 DFS(i, j, 1)
     
     print("YES" if found else "NO")
     input()
 
 
 
 
 
 --------Java--------:
 
 import java.util.*;

 public class Main {
     static final int MAX = 101;
     static String term = "ALLIZZWELL";
     static int R, C;
     static boolean found;
     static int[] dr = {0, 0, 1, 1, 1, -1, -1, -1};
     static int[] dc = {1, -1, 0, 1, -1, 0, 1, -1};
     static boolean[][] visited = new boolean[MAX][MAX];
     static char[][] table = new char[MAX][MAX];

     public static boolean isValid(int r, int c) {
         return r >= 0 && c >= 0 && r < R && c < C;
     }

     public static void DFS(int sr, int sc, int count) {
         if (count == term.length()) {
             found = true;
             return;
         }

         for (int i = 0; i < 8; i++) {
             int r = sr + dr[i];
             int c = sc + dc[i];

             if (isValid(r, c) && table[r][c] == term.charAt(count) && !visited[r][c]) {
                 visited[r][c] = true;
                 DFS(r, c, count + 1);
                 visited[r][c] = false;
             }
         }
     }

     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         int T = sc.nextInt();

         while (T-- > 0) {
             R = sc.nextInt();
             C = sc.nextInt();

             for (int i = 0; i < R; i++) {
                 table[i] = sc.next().toCharArray();
                 for (int j = 0; j < C; j++) {
                     visited[i][j] = false;
                 }
             }

             found = false;

             for (int i = 0; i < R; i++) {
                 for (int j = 0; j < C; j++) {
                     if (table[i][j] == term.charAt(0) && !found) {
                         DFS(i, j, 1);
                     }
                 }
             }

             System.out.println(found ? "YES" : "NO");
         }
     }
 }
 
 
 */







