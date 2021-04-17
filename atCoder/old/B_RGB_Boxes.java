import java.util.*;
class B_RGB_Boxes{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int g = sc.nextInt();
        int b = sc.nextInt();
        int target = sc.nextInt();
        int count = 0;
        for(int i = 0; i*r<=target; i++){
            for(int j = 0; i*r+j*g <= target; j++){
                int k = target-i*r-j*g;
                if(k%b==0) count++;
            }
        }
        System.out.println(count);
        sc.close();
    }
}