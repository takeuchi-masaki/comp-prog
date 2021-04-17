import java.util.*;
class B_Guidebook{
    class Restaurant implements Comparable<Restaurant>{
        String city;
        int score, index;
        Restaurant(String city, int score, int i){
            this.city = city;
            this.score = score;
            this.index = i;
        }
        
        @Override
        public int compareTo(Restaurant o) {
            int cmp = this.city.compareTo(o.city);
            if(cmp == 0){
                return Integer.compare(o.score,this.score);
            } else {
                return cmp;
            }
        }
    }
    void run(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Restaurant> arr = new ArrayList<>(n);
        for(int i = 0; i < n; i++){
            sc.skip("\n");
            String s = sc.next();
            int num = sc.nextInt();
            arr.add(new Restaurant(s, num, i+1));
        }
        Collections.sort(arr);
        StringBuilder sb = new StringBuilder();
        for(Restaurant r : arr){
            sb.append(r.index).append('\n');
        }
        System.out.print(sb);
        sc.close();
    }
    public static void main(String[] args){
        new B_Guidebook().run();
    }
}