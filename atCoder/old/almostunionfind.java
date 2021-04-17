import java.util.*;
class almostunionfind{
    void run(){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt()){
            StringBuilder sb = new StringBuilder();
            int n = sc.nextInt();
            int m = sc.nextInt();
            ArrayList<HashSet<Integer>> alset = new ArrayList<>(n+1);
            HashMap<Integer,Integer> map = new HashMap<>(n+1);
            HashMap<Integer,Long> sums= new HashMap<>(n+1);
            alset.add(new HashSet<>());
            for(int i = 1; i <= n; i++){
                alset.add(new HashSet<>());
                alset.get(i).add(i);
                map.put(i,i);
                sums.put(i,(long)i);
            }
            for(int i = 0; i < m; i++){
                int command = sc.nextInt();
                int p, q;
                switch (command) {
                    case 1:
                        // move entire set of q to p
                        p = sc.nextInt();
                        q = sc.nextInt();
                        int indexP = map.get(p);
                        int indexQ = map.get(q);
                        if(indexP != indexQ){
                            long currSum = sums.get(indexP)+sums.get(indexQ);
                            alset.get(indexP).addAll(alset.get(indexQ));
                            sums.replace(indexP,currSum);
                            alset.get(indexQ).clear();
                            sums.put(indexQ,0l);
                        }
                        break;
                    case 2:
                        // move p to q
                        p = sc.nextInt();
                        q = sc.nextInt();
                        int currP = map.get(p);
                        int currQ = map.get(q);
                        if(currP!=currQ){
                            sums.put(currP,sums.get(currP)-p);
                            sums.put(currQ,sums.get(currQ)+p);
                            map.replace(p,currQ);
                            alset.get(currP).remove(p);
                            alset.get(currQ).add(p);
                        }
                        break;
                    case 3:
                        p = sc.nextInt();
                        int index = map.get(p);
                        long sum = sums.get(index);
                        sb.append( alset.get(index).size() ).append(' ').append(sum).append('\n');
                        break;
                }
            }
            System.out.println(sb);
        }
        sc.close();
    }
    public static void main(String[] args){
        new almostunionfind().run();
    }
}