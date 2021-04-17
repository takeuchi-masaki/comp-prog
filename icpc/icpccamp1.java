import java.util.*;
class icpccamp1{
    ArrayList<Integer> x;
    ArrayList<Integer> y;
    PriorityQueue<edge> q1;

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
        q1 = new PriorityQueue<>();
        for(int i = 0; i < p; i++){
            int index = 0;
            while(index<q && (long)x.get(i)+y.get(index)<=s ){
                int diff = Math.abs(x.get(i)-y.get(index));
                q1.add(new edge(diff,i,index));
                index++;
            }
        }
        boolean ok = false;
        int count = 0;
        int res = -1;
        while(!ok){
            PriorityQueue<edge> queue = new PriorityQueue<>(q1);
            for(int i = 0; i < count; i++){
                if(queue.size()<n) break;
                queue.poll();
            }
            res = -1;
            int have = 0;
            if(queue.size()<n) break;
            boolean[] usex = new boolean[p];
            boolean[] usey = new boolean[q];
            Arrays.fill(usex,false);
            Arrays.fill(usey,false);
            while(!queue.isEmpty() && have < n){
                edge next = queue.poll();
                // System.out.println(next.diff + " " + next.ix + " " + next.iy);
                if(!usex[next.ix] && !usey[next.iy]){
                    usex[next.ix] = true;
                    usey[next.iy] = true;
                    res = Math.max(res,next.diff);
                    have++;
                }
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
        public int compareTo(icpccamp1.edge o) {
            return Integer.compare(this.diff, o.diff);
        }
    }
    

    public static void main(String[] args){
        new icpccamp1().run();
    }
}