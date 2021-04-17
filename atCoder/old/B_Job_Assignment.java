import java.util.*;
class B_Job_Assignment{
    void run(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<pair> ab = new ArrayList<>();
        for(int i = 0; i < n; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            ab.add(new pair(a,b));
        }
        ArrayList<pair> ba = new ArrayList<>(ab);
        
        Collections.sort(ab,Comparator.comparing(o->o.f));
        Collections.sort(ba,Comparator.comparing(o->o.s));
        int res = Math.max(ab.get(0).f, ba.get(0).s);
        if(ab.get(0).s==ba.get(0).s){
            res = Math.min( ab.get(0).f+ab.get(0).s, Math.min( Math.max(ab.get(1).f,ba.get(0).s), Math.max(ab.get(0).f,ba.get(1).s) ));
        }
        System.out.println(res);
        sc.close();
    }
    public static void main(String[] args){
        new B_Job_Assignment().run();
    }

    class pair {
        int f, s;
        pair(int a, int b){
            f = a;
            s = b;
        }
    }
}