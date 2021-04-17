import java.math.BigInteger;
import java.util.Scanner;

class B_Comparison{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String b = sc.nextLine();
        BigInteger a1 = new BigInteger(a);
        BigInteger b1 = new BigInteger(b);
        String res;
        switch(a1.compareTo(b1)){
            case 0: res = "EQUAL"; break;
            case 1: res = "GREATER"; break;
            default: res = "LESS";
        }
        System.out.println(res);
        sc.close();
    }
}