import java.util.*;

class C_Takahashi_s_Information{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[][] grid = new int[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                grid[i][j] = sc.nextInt();
            }
        }
        int[] a = new int[3];
        int[] b = new int[3];
        boolean ok = false;
        // for(int i = 0; i < 100; i++){
        //     // Arrays.fill(a,-1);
        //     // Arrays.fill(b,-1);
        //     for(int j = 0; j < 100; j++){
        //         for(int k = 0; k < 100; k++){
        //             a[0] = i;
        //             a[1] = j;
        //             a[2] = k;
        //             b[0] = grid[0][0]-a[0];
        //             b[1] = grid[1][1]-a[1];
        //             b[2] = grid[2][2]-a[2];
        //             boolean check = true;
        //             for(int z = 0; z < 3; z++){
        //                 for(int y = 0; y < 3; y++){
        //                     if(grid[z][y] != a[z]+b[y]) {
        //                         check = false;
        //                         break;
        //                     }
        //                 }
        //                 if(!check) break;
        //             }
        //             if(check) {
        //                 ok = true;
        //                 break;
        //             }
        //         }
        //         if(ok) break;
        //     }
        //     if(ok) break;
        // }
        for(int i = 0; i < 100; i++){
            a[0] = i;
            b[0] = grid[0][0]-i;
            b[1] = grid[0][1]-i;
            b[2] = grid[0][2]-i;
            a[1] = grid[1][1]-b[1];
            a[2] = grid[2][1]-b[1];
            boolean check = true;
            for(int z = 0; z < 3; z++){
                for(int y = 0; y < 3; y++){
                    if(grid[z][y] != a[z]+b[y]) {
                        check = false;
                        break;
                    }
                }
                if(!check) break;
            }
            if(check) {
                ok = true;
                break;
            }
        }
        System.out.println((ok?"Yes":"No"));
        sc.close();
    }
}