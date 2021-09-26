/*
 Source: UVA
 Link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1594
 */

























/*
 ---------C++--------:
 
 #include <bits/stdc++.h>
 using namespace std;
 const int dr[] = {0, 0, 1, -1};
 const int dc[] = {1, -1, 0, 0};

 struct Cell {
     int r, c;
 };

 int R, C;
 vector<vector<int>> graph;

 bool isValid(int r, int c) {
     return r >= 0 && r < R && c >= 0 && c < C;
 }

 int BFS(Cell s, Cell f) {
     queue<Cell> q;
     graph[s.r][s.c] = 1;
     q.push(s);

     while (!q.empty()) {
         Cell u = q.front();
         q.pop();

         if (u.r == f.r && u.c == f.c) {
             break;
         }
         
         for (int i = 0; i < 4; i++) {
             int r = u.r + dr[i];
             int c = u.c + dc[i];
             
             if (isValid(r, c) && graph[r][c] == 0) {
                 graph[r][c] = graph[u.r][u.c] + 1;
                 q.push((Cell){r, c});
             }
         }
     }

     return graph[f.r][f.c] - 1;
 }

 int main() {
     int rows, n, row, col;
     Cell s, f;

     while (true) {
         cin >> R >> C;

         if (R == 0 && C == 0) {
             break;
         }

         graph = vector<vector<int> > (R, vector<int> (C));
         cin >> rows;

         for (int i = 0; i < rows; i++) {
             cin >> row >> n;

             for (int j = 0; j < n; j++) {
                 cin >> col;
                 graph[row][col] = -1;
             }
         }

         cin >> s.r >> s.c >> f.r >> f.c;
         cout << BFS(s, f) << endl;
     }
     return 0;
 }
 
 
 
 
 -------Python-------:
 
 dr = [0, 0, 1, -1]
 dc = [1, -1, 0, 0]

 def BFS(sr, sc, fr, fc):
     left = right = 0
     q[0] = (sr, sc)
     graph[sr][sc] = 1
     
     while left <= right:
         ur, uc = q[left]
         left += 1
         
         if ur == fr and uc == fc:
             break
             
         for i in range(4):
             r = ur + dr[i]
             c = uc + dc[i]
             
             if r in range(R) and c in range(C) and graph[r][c] == 0:
                 graph[r][c] = graph[ur][uc] + 1
                 right += 1
                 q[right] = (r, c)
     
     return graph[fr][fc] - 1

 while True:
     R, C = map(int, input().split())
     
     if R == 0 and C == 0:
         break
     
     graph = [[0] * C for _ in range(R)]
     q = [None] * R * C
     
     rows = int(input())
     
     for _ in range(rows):
         cols = list(map(int, input().split()))
         row = cols.pop(0)
         n = cols.pop(0)
         
         for col in cols:
             graph[row][col] = -1
     
     sr, sc = map(int, input().split())
     fr, fc = map(int, input().split())
     
     print(BFS(sr, sc, fr, fc))
 
 
 
 
 
 --------Java--------:
 
 import java.util.*;

 public class Main {
     static int[] dr = {0, 0, 1, -1};
     static int[] dc = {1, -1, 0, 0};
     static int R, C;
     
     static class Cell {
         int r, c;
         
         public Cell(int _r, int _c) {
             this.r = _r;
             this.c = _c;
         }
     }
     
     public static boolean isValid(int r, int c) {
         return r >= 0 && c >= 0 && r < R && c < C;
     }
     
     public static int BFS(Cell s, Cell f, int[][] graph) {
         Queue<Cell> q = new LinkedList<>();
         q.add(s);
         graph[s.r][s.c] = 1;
         
         while (!q.isEmpty()) {
             Cell u = q.poll();
             
             if (u.r == f.r && u.c == f.c) {
                 break;
             }
             
             for (int i = 0; i < 4; i++) {
                 int r = u.r + dr[i];
                 int c = u.c + dc[i];
                 
                 if (isValid(r, c) && graph[r][c] == 0) {
                     graph[r][c] = graph[u.r][u.c] + 1;
                     q.add(new Cell(r, c));
                 }
             }
         }

         return graph[f.r][f.c] - 1;
     }
     
     public static void main(String[] agrs) {
         Scanner sc = new Scanner(System.in);
         
         while (true) {
             R = sc.nextInt();
             C = sc.nextInt();
             
             if (R == 0 && C == 0) {
                 break;
             }
             
             int[][] graph = new int[R][C];
             int rows = sc.nextInt();
             
             for (int i = 0; i < rows; i++) {
                 int row = sc.nextInt();
                 int n = sc.nextInt();
                 
                 for (int j = 0; j < n; j++) {
                     int col = sc.nextInt();
                     graph[row][col] = -1;
                 }
             }
             
             Cell s = new Cell(sc.nextInt(), sc.nextInt());
             Cell f = new Cell(sc.nextInt(), sc.nextInt());
             System.out.println(BFS(s, f, graph));
         }
     }
 }
 
 
 */







