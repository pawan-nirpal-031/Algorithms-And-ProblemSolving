import java.util.*;
public class queue {
    public List<Integer> que;
    queue(){
       que = new Vector<Integer>();
    }
    void insert(int n){
        if(que.isEmpty()){
            que.add(n);
        }else{
            que.add(0,n);
        }
        this.show();
    }
    void remove(int n){
        if(!que.isEmpty()){
            que.remove(que.size()-1);
        }
        this.show();
    }
    void show(){
        for(int n : que){
            System.out.print(n+' ');
        }
    }
    public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         queue q = new queue();
         int n = sc.nextInt();
         while(n-->0){
             int x  = sc.nextInt();
             q.insert(x);
         }
         sc.close();
    }    
}