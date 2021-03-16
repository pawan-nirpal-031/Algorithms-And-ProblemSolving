import java.util.*;

public class KnightTour{
    
    void display(int [][]grid,int n ){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                System.out.print(grid[i][j]+" ");
            }
            System.out.println('\n');
        }
    }

    boolean IsKnightSafe(int [][]grid,int n,int i,int j,boolean vis[][]){
        return i>=0 && j>=0 && j<n && i<n && vis[i][j] ==false;
    }

    void Tour(int grid[][],int n,int i,int j,int count,boolean vis[][]){
        if(count==n*n-1){
            grid[i][j] = count;
            display(grid,n);
            System.out.println('\n');
            return;
        }
        if(count>=n*n) return;
        vis[i][j] =true;
        int xdir[] = {-2,-1,1,2,2,1,-1,-2};
        int ydir[] = {1,2,2,1,-1,-2,-2,-1};
        grid[i][j] = count;
        for(int x =0;x<8;x++){
            if(IsKnightSafe(grid, n, i+xdir[x], j+ydir[x],vis)){
                Tour(grid,n,i+xdir[x], j+ydir[x],count+1,vis);
            }
        }
        vis[i][j] = false;
        grid[i][j]--;
    } 

    public static void main(String[] args) {
        int n = (new Scanner(System.in)).nextInt();
        int grid[][] = new int[n][n];
        boolean vis[][] = new boolean[n][n];
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                grid[i][j] = 0;
                vis[i][j] = false;
            }
        }
        new KnightTour().Tour(grid,n,0,0,0,vis);
    }
}