import java.util.*; 

public class JanuaryLongChallange{
    public static int Elections(){
        Scanner sc = new Scanner(System.in);
        
        int m = sc.nextInt();
        Vector<Integer>a = new Vector<Integer>();
        int sum_a = 0;
        for(int i =0;i<m;i++){
            a.add(sc.nextInt());
            sum_a+=a.get(i);
        }
        
        int n = sc.nextInt();
        int sum_b =0;
        Vector<Integer>b = new Vector<Integer>();
        for(int i=0;i<n;i++){
            b.add(sc.nextInt());
            sum_b+=b.get(i);
        }
        sc.close();
        a.sort(null);
        b.sort(null);
        int ans =0;
        int sdiff = sum_a-sum_b;
        int i =0;
        int j = n-1;
        int ediff = b.get(j) - a.get(i);
        while(sdiff<=0){
            if(i<m && j>=0){
                ediff = b.get(j) - a.get(i);
                if(ediff<=0){
                    return -1;
                }else{
                    sum_a+=ediff;
                    sum_b-=ediff;
                    i++;
                    j--;
                    ans++;
                    sdiff = sum_a-sum_b;
                }
            }else{
                return -1;
            }
        }    
        return ans;
        
    }

    public static void main(String[] args) {
        System.out.println(Elections());
    }
}