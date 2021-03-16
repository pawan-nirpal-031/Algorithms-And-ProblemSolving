import java.util.*;





public class NQUEENS{
    void display(boolean grid[][],int n){
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==true){
                    System.out.print("Q ");
                }else{
                    System.out.print(". ");
                }
            }
            System.out.println('\n');
        }
    }

    boolean IsSafe(boolean grid[][],int row,int col,int n){
        for(int r = row-1;r>=0;r--){
            if(grid[r][col]){
                return false;
            }
        }
        for(int c = 0;c<n;c++){
            if(grid[row][c]){
                return false;
            }
        }
        for(int i =row-1, j = col-1; i>=0 && j>=0; i--,j--){
            if(grid[i][j]) return false;
        }
        for(int i = row-1,j = col+1; i>=0 && j<n; i--, j++){
            if(grid[i][j]) return false;
        }
        return true;
    }

    void Nqueens(boolean grid[][],int n,int row){
        if(row==n){
            display(grid,n);
            System.out.println('\n');
            return;
        }
        for(int col =0;col<n;col++){
            if(IsSafe(grid,row,col,n)==true){
                grid[row][col]= true;
                Nqueens(grid, n, row+1);
                grid[row][col] = false;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc  = new Scanner(System.in);
        int n = sc.nextInt();
        boolean grid[][] = new boolean[n][n];
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                grid[i][j] = false;
            }
        }
        new NQUEENS().Nqueens(grid,n,0);
        sc.close();
    }
}