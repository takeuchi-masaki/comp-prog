import java.util.*;
class D_Banned_K{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> al = new ArrayList<>();
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            int temp = sc.nextInt();
            al.add(temp);
            if(map.containsKey(temp)){
                map.put(temp,map.get(temp)+1);
            } else {
                map.put(temp,1);
            }
        }
        long combSum = 0;
        for(int i: map.keySet()){
            int num = map.get(i);
            if(num > 1){
                combSum += ncr(num);
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i : al){
            int cnt = map.get(i);
            long curr = combSum;
            if(cnt>=2){
                curr-=ncr(cnt);
                if(cnt-1>=2){
                    curr+=ncr(cnt-1);
                }
            }
            sb.append(curr).append('\n');
        }
        System.out.println(sb);
        sc.close();
    }

    public static long ncr(long n) { 
        long r = 2;
		long numerator = 1, denominator = 1; 
		if (r > n - r) { 
			r = n - r; 
		} 
		for (long i = 1L; i <= r; ++i) { 
			denominator *= i; 
		} 
		for (long i = n - r + 1L; i <= n; ++i) { 
			numerator *= i; 
		} 
		return numerator / denominator; 
	} 


}