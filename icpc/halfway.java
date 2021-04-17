import java.util.*;
class halfway{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long res = ((n*(n-1)/2)+1)/2;
        
        System.out.println(res);
    }
}