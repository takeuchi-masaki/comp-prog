/*
 Source: SPOJ
 Link: https://www.spoj.com/problems/PRO/
 */

























/*
 ---------C++--------:
 
 #include <bits/stdc++.h>
 using namespace std;
 const int MAX = 1e6 + 5;

 struct Bill {
     int number, price;
 };

 struct BillAscendingPrice {
     bool operator() (const Bill &a, const Bill &b) {
         return a.price < b.price;
     }
 };

 struct BillDescendingPrice {
     bool operator() (const Bill &a, const Bill &b) {
         return a.price > b.price;
     }
 };

 int main() {
     int n, k, x, nbills = 0;
     long long money = 0;
     bool taken[MAX] = {};
     priority_queue<Bill, vector<Bill>, BillAscendingPrice> maxHeap;
     priority_queue<Bill, vector<Bill>, BillDescendingPrice> minHeap;
     
     cin >> n;
     
     for (int i = 0; i < n; i++) {
         cin >> k;

         for (int j = 0; j < k; j++) {
             cin >> x;
             nbills++;
             maxHeap.push((Bill) {nbills, x});
             minHeap.push((Bill) {nbills, x});
         }

         while (taken[maxHeap.top().number]) {
             maxHeap.pop();
         }

         while (taken[minHeap.top().number]) {
             minHeap.pop();
         }

         money += maxHeap.top().price - minHeap.top().price;
         taken[maxHeap.top().number] = taken[minHeap.top().number] = true;
         maxHeap.pop();
         minHeap.pop();
     }

     cout << money;
     return 0;
 }
 
 
 
 
 -------Python-------:
 
 import heapq

 taken = [False] * 1000005
 maxHeap = []
 minHeap = []
 money = 0
 nbills = 0

 n = int(input())

 for _ in range(n):
     a = list(map(int, input().split()))
     
     for x in a[1:]:
         nbills += 1
         heapq.heappush(maxHeap, (-x, nbills))
         heapq.heappush(minHeap, (x, nbills))

     while taken[maxHeap[0][1]]:
         heapq.heappop(maxHeap)
     
     while taken[minHeap[0][1]]:
         heapq.heappop(minHeap)
     
     taken[maxHeap[0][1]] = taken[minHeap[0][1]] = True
     money += -heapq.heappop(maxHeap)[0] - heapq.heappop(minHeap)[0]

 print(money)
 
 
 
 
 
 --------Java--------:
 
 import java.util.*;

 public class Solution {
     static final int MAX = (int)1e6 + 5;

     static class Bill {
         int number, price;

         public Bill(int _number, int _price) {
             this.number = _number;
             this.price = _price;
         }
     }

     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         boolean[] taken = new boolean[MAX];
         int n = sc.nextInt();
         int nbills = 0;
         long money = 0;

         PriorityQueue<Bill> maxHeap = new PriorityQueue<>(new Comparator<Bill>() {
             public int compare(Bill a, Bill b) {
                 return b.price - a.price;
             }
         });

         PriorityQueue<Bill> minHeap = new PriorityQueue<>(new Comparator<Bill>() {
             public int compare(Bill a, Bill b) {
                 return a.price - b.price;
             }
         });

         for (int i = 0; i < n; i++) {
             int k = sc.nextInt();

             for (int j = 0; j < k; j++) {
                 int x = sc.nextInt();
                 nbills++;

                 maxHeap.add(new Bill(nbills, x));
                 minHeap.add(new Bill(nbills, x));
             }

             while (taken[maxHeap.peek().number]) {
                 maxHeap.remove();
             }

             while (taken[minHeap.peek().number]) {
                 minHeap.remove();
             }
             
             taken[maxHeap.peek().number] = taken[minHeap.peek().number] = true;
             money += maxHeap.poll().price - minHeap.poll().price;
         }

         System.out.print(money);
     }
 }
 
 
 */







