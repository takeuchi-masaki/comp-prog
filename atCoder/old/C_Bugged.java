import java.util.*;

class C_Bugged{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> vec = new ArrayList<>(n);
        for(int i = 0; i < n; i++){
            vec.add(sc.nextInt());
        }
        sc.close();
        int sum = 0;
        for(int i : vec){
            sum+=i;
        }
        if(sum%10!=0){
            System.out.println(sum);
        } else {
            Collections.sort(vec);
            boolean ok = false;
            for(int i : vec){
                if(i%10 != 0){
                    sum-=i;
                    ok = true;
                    break;
                }
            }
            if(!ok) sum = 0;
            System.out.println(sum);
        }
    }
}