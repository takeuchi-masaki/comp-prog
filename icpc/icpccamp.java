import java.util.*;
class icpccamp{
    ArrayList<Integer> x;
    ArrayList<Integer> y;
    ArrayList<edge> q1;

    int n,p,q;
    long s;

    void run(){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); // days of camp
        p = sc.nextInt(); // classical
        q = sc.nextInt(); // creative
        s = sc.nextLong(); // max diff
        x = new ArrayList<>();
        y = new ArrayList<>();
        for(int i = 0; i < p; i++){
            x.add(sc.nextInt());
        }
        for(int i = 0; i < q; i++){
            y.add(sc.nextInt());
        }
        Collections.sort(x);
        Collections.sort(y);
        q1 = new ArrayList<>();
        for(int i = 0; i < p; i++){
            int index = 0;
            while(index<q && (long)x.get(i)+y.get(index)<=s ){
                int diff = Math.abs(x.get(i)-y.get(index));
                q1.add(new edge(diff,i,index));
                index++;
            }
        }
        Collections.sort(q1);
        boolean ok = false;
        int count = -1;
        int res = -1;
        while(!ok){
            
            res = -1;
            int have = 0;
            boolean[] usex = new boolean[p];
            boolean[] usey = new boolean[q];
            Arrays.fill(usex,false);
            Arrays.fill(usey,false);
            int index = 0;
            while(index < q1.size() && have < n){
                edge next = q1.get(index);
                // System.out.println(next.diff + " " + next.ix + " " + next.iy);
                if(!usex[next.ix] && !usey[next.iy]){
                    usex[next.ix] = true;
                    usey[next.iy] = true;
                    res = Math.max(res,next.diff);
                    have++;
                }
                index++;
            }
            if(have!=n) {
                res = -1;
                count++;
            } else {
                ok = true;
            }
        }
        System.out.println(res);
        sc.close();
    }
    class edge implements Comparable<edge>{
        int diff;
        int ix, iy;
        edge(int diff,int ix, int iy){
            this.diff = diff;
            this.ix = ix;
            this.iy = iy;
        }
        @Override
        public int compareTo(icpccamp.edge o) {
            return Integer.compare(this.diff, o.diff);
        }
    }
    

    public static void main(String[] args){
        new icpccamp().run();
    }
}