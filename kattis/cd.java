import java.io.*;
import java.util.*;

public class cd {
    FastScanner sc;

    void run(){
        sc = new FastScanner();
        int n, m;
        while(true){
            n = sc.nextInt();
            m = sc.nextInt();
            if(n == 0 && m == 0) break;
            HashSet<Integer> s = new HashSet<>();
            for(int i = 0; i < n; i++){
                int cd = sc.nextInt();
                s.add(cd);
            }
            int ans = 0;
            for(int i = 0; i < m; i++){
                int cd = sc.nextInt();
                if(s.contains(cd)) ans++;
            }
            System.out.println(ans);
        }
    }



    public static void main(String[] args) {
        cd solution = new cd();
        solution.run();
    }

    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            try {
                return br.readLine();
            } catch(IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
