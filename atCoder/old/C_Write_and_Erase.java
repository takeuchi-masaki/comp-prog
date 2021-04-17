import java.util.*;
class C_Write_and_Erase{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    HashSet<Long> set = new HashSet<>(200000);
    for(int i = 0; i < n; i++){
        long temp = sc.nextLong();
        if(set.contains(temp)){
            set.remove(temp);
        } else {
            set.add(temp);
        }
    }
    System.out.println(set.size());
    sc.close();
  }
}