/*
 Source: Kattis
 Link: https://open.kattis.com/problems/shortestpath3
 */

























/*
 ---------C++--------:
 
 #include <bits/stdc++.h>
 #define MAX_N 1005
 #define MAX_M 5005
 using namespace std;
 const int INF = 1e9 + 7;

 struct Edge {
     int source, target, weight;
 };

 int n, m;
 int dist[MAX_N];
 Edge graph[MAX_M];

 void BellmanFord(int s) {
     fill(dist, dist + n, INF);
     dist[s] = 0;

     for (int i = 0; i < n - 1; i++) {
         for (int j = 0; j < m; j++) {
             int u = graph[j].source;
             int v = graph[j].target;
             int w = graph[j].weight;

             if (dist[u] != INF && dist[u] + w < dist[v]) {
                 dist[v] = dist[u] + w;
             }
         }
     }

     for (int i = 0; i < n - 1; i++) {
         for (int j = 0; j < m; j++) {
             int u = graph[j].source;
             int v = graph[j].target;
             int w = graph[j].weight;

             if (dist[u] != INF && dist[u] + w < dist[v]) {
                 dist[v] = -INF;
             }
         }
     }
 }

 int main() {
     int u, v, w, q, s, f;

     while (cin >> n >> m >> q >> s, n != 0) {
         for (int i = 0; i < m; i++) {
             cin >> u >> v >> w;
             graph[i] = (Edge) {u, v, w};
         }

         BellmanFord(s);

         while (q--) {
             cin >> f;

             if (dist[f] == INF) {
                 cout << "Impossible" << endl;
             }
             else if (dist[f] == -INF) {
                 cout << "-Infinity" << endl;
             }
             else {
                 cout << dist[f] << endl;
             }
         }
         cout << endl;
     }
     return 0;
 }
 
 
 
 
 -------Python-------:
 
 INF = 10 ** 9

 def BellmanFord(s):
     dist[s] = 0

     for i in range(n - 1):
         for j in range(m):
             u, v, w = graph[j]
             if dist[u] != INF and dist[u] + w < dist[v]:
                 dist[v] = dist[u] + w
     
     for i in range(n - 1):
         for j in range(m):
             u, v, w = graph[j]
             if dist[u] != INF and dist[u] + w < dist[v]:
                 dist[v] = -INF

 while True:
     n, m, q, s = map(int, input().split())
     
     if n == 0:
         break
     graph = []
     
     for i in range(m):
         u, v, w = map(int, input().split())
         graph.append((u, v, w))
     
     dist = [INF] * n
     BellmanFord(s)

     for _ in range(q):
         f = int(input())
     
         if dist[f] == INF:
             print("Impossible")
         elif dist[f] == -INF:
             print("-Infinity")
         else:
             print(dist[f])
     print()
 
 
 
 
 
 --------Java--------:
 
 import java.util.*;
 import java.io.*;

 public class Main {
     static final int INF = (int)1e9 + 7;
     static final int MAX_N = 1005;
     static final int MAX_M = 5005;
     static class Edge {
         int source, target, weight;

         public Edge(int _source, int _target, int _weight) {
             this.source = _source;
             this.target = _target;
             this.weight = _weight;
         }
     }

     static int n, m;
     static int[] dist = new int[MAX_N];
     static Edge[] graph = new Edge[MAX_M];

     public static void BellmanFord(int s) {
         Arrays.fill(dist, INF);
         dist[s] = 0;

         for (int i = 0; i < n - 1; i++) {
             for (int j = 0; j < m; j++) {
                 int u = graph[j].source;
                 int v = graph[j].target;
                 int w = graph[j].weight;

                 if (dist[u] != INF && dist[u] + w < dist[v]) {
                     dist[v] = dist[u] + w;
                 }
             }
         }
         
         for (int i = 0; i < n - 1; i++) {
             for (int j = 0; j < m; j++) {
                 int u = graph[j].source;
                 int v = graph[j].target;
                 int w = graph[j].weight;

                 if (dist[u] != INF && dist[u] + w < dist[v]) {
                     dist[v] = -INF;
                 }
             }
         }
     }

     public static void main(String[] agrs) {
         MyScanner in = new MyScanner();
         while (true) {
             n = in.nextInt();
             m = in.nextInt();
             int q = in.nextInt();
             int s = in.nextInt();
             
             if (n == 0) {
                 break;
             }

             for (int i = 0; i < m; i++) {
                 int u = in.nextInt();
                 int v = in.nextInt();
                 int w = in.nextInt();
                 graph[i] = new Edge(u, v, w);
             }

             BellmanFord(s);

             while (q-- > 0) {
                 int f = in.nextInt();
                 
                 if (dist[f] == INF) {
                     System.out.println("Impossible");
                 }
                 else if (dist[f] == -INF) {
                     System.out.println("-Infinity");
                 }
                 else {
                     System.out.println(dist[f]);
                 }
             }
             System.out.println();
         }
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







