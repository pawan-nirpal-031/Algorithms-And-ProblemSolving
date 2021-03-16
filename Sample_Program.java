import java.io.IOException;
import java.util.*;

class Student{
    private int rollNo;
    private String name;
    private int subjcts[];
    Student(){
        subjcts = null;
        rollNo =0;
        name = null;
    }
    Student(int r,String n,int []s){
        subjcts = new int[5];
        rollNo =r;
        name = n;
        for(int i=0;i<s.length;i++){
            subjcts[i] = s[i];
        }
    }
    void Percentage(Student s){
        double sum =0;
        for(int mks : this.subjcts){
            sum+=(mks);
        }
        double per = (sum/100)*(100);
        System.out.println("Percentage : "+(double)(per)+"%");
        String div[]={"First","Second","Pass","Fail"};
        int d =-1;
        if(per>=80){
            d = 0;
        }else if(per>=60){
            d =1;
        }else if(per>=40){
            d = 2;
        }else{
            d =3;
        }
        System.out.println(div[d]+"\n");
    }

}
public class Sample_Program{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Student> dtabse = new ArrayList<>();
        for(int i =0;i<n;i++){
            System.out.println("Enter RollNo : ");
            int r = sc.nextInt();
            System.out.println("Enter Name : ");
            String name = sc.next();
            System.out.println("Enter Marks to 5 subjects : ");
            int mks[] = new int[5];
            for(int j=0;j<5;j++){
                mks[i] = sc.nextInt();
            }
            Student st = new Student(r,name,mks);
            dtabse.add(st);
            st.Percentage(st);
        }

    }
}