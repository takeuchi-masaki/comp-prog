import java.io.*;
import java.util.*;

public class cold {
    FastScanner sc;
    

    void run(){
        sc = new FastScanner();
        int n = sc.nextInt();
        int[] a = sc.readArray(n);
        int count = 0;
        for(int i:a){
            if(i < 0) count++;
        }
        System.out.println(count);
    }



    public static void main(String[] args) {
        cold solution = new cold();
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
