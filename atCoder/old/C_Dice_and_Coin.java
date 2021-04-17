import java.util.*;
class C_Dice_and_Coin{
    void run(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        double res = 0.0;
        for(int i = 1; i<=n; i++){
            double temp = 1.0/n;
            int now = i;
            while(now<k){
                now*=2;
                temp/=2;
            }
            res+=temp;
        }
        System.out.println(res);
        sc.close();
    }
    public static void main(String[] args){
        new C_Dice_and_Coin().run();
    }
}