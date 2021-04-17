import java.util.*;
class icpcteamselection{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            ArrayList<Integer> al = new ArrayList<>(3*n);
            for(int i = 0; i < 3*n; i++){
                al.add(sc.nextInt());
            }
            Collections.sort(al);
            int sum = 0;
            int maxIndex = 3*n-1;
            // int minIndex = 0;
            for(int i = 0; i < n; i++){
                int number = al.get(maxIndex-1);
                maxIndex-=2;
                sum+=number;
            }
            System.out.println(sum);
        }
        sc.close();
    }
}