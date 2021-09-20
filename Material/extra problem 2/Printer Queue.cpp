/*
 Source: UVA
 Link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3252
 */

























/*
 ---------C++--------:
 
 #include <bits/stdc++.h>
 using namespace std;

 struct Job {
     int pos, priority;
 };

 int main() {
     int Q, n, m, priority;
     cin >> Q;
     
     while (Q--) {
         queue<Job> q;
         priority_queue<int> pq;
         
         cin >> n >> m;
         
         for (int i = 0; i < n; i++) {
             cin >> priority;
             q.push((Job) {i, priority});
             pq.push(priority);
         }
         
         int count = 0;
         
         while (!pq.empty()) {
             if (pq.top() == q.front().priority) {
                 count++;
                 
                 if (q.front().pos == m) {
                     break;
                 }
                 
                 q.pop();
                 pq.pop();
             }
             else {
                 q.push(q.front());
                 q.pop();
             }
         }
         
         cout << count << endl;
     }
     return 0;
 }
 
 
 
 
 -------Python-------:
 
 import queue
 Q = int(input())

 for _ in range(Q):
     q = queue.Queue()
     pq = queue.PriorityQueue()
     
     n, m = map(int, input().split())
     prior = list(map(int, input().split()))
     
     for i in range(n):
         q.put((i, prior[i]))
         pq.put(-prior[i])
     
     count = 0
     
     while not pq.empty():
         jobPos, jobPrior = q.get()
         prior = -pq.get()
         
         if prior == jobPrior:
             count += 1
             if jobPos == m:
                 break
         else:
             q.put((jobPos, jobPrior))
             pq.put(-prior)
     
     print(count)
 
 
 
 
 
 --------Java--------:
 
 import java.util.*;

 public class Main {
     static class Job {
         int pos, priority;
         
         public Job(int _pos, int _priority) {
             this.pos = _pos;
             this.priority = _priority;
         }
     }
     
     public static void main(String[] agrs) {
         Scanner sc = new Scanner(System.in);
         int Q = sc.nextInt();
         
         while (Q-- > 0) {
             Queue<Job> q = new LinkedList<>();
             PriorityQueue<Integer> pq = new PriorityQueue<>();
             
             int n = sc.nextInt();
             int m = sc.nextInt();
             
             for (int i = 0; i < n; i++) {
                 int priority = sc.nextInt();
                 q.add(new Job(i, priority));
                 pq.add(-priority);
             }
             
             int count = 0;
             
             while (!pq.isEmpty()) {
                 if (-pq.peek() == q.peek().priority) {
                     count++;
                     
                     if (q.peek().pos == m) {
                         break;
                     }
                     
                     q.remove();
                     pq.remove();
                 }
                 else {
                     q.add(q.poll());
                 }
             }
             
             System.out.println(count);
         }
     }
 }
 
 
 */







