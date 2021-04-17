import java.util.*;

class C_Sentou{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        long sum = 0;
        long prevEnd = 0;
        for(int i = 0; i < n; i++){
            int temp = sc.nextInt();
            sum += t-Math.max(0,(prevEnd-temp));
            prevEnd = temp+t;
        }
        System.out.println(sum);
        sc.close();
    }
}