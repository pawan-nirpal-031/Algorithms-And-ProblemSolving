import java.util.*;
public class test {
    private int sm =0;
    int digSum(int n ){
        if(n>0){
            sm+=(n%10);
            digSum(n/10);
        }
        return sm;
    }
    void bin(int n){
        if(n>0){
            bin(n>>1);
            System.out.print(n%2);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        // System.out.println(new test().bin(n));
        new test().bin(n);
        sc.close();
    }
}