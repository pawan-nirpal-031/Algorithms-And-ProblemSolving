import java.util.*;

class node{
    public int val;
    public node ptrs[];
    node(){
        this.val =0;
        ptrs = new node[26];
        for (node ptr : ptrs) {
            ptr = null;
        }
    }    
}
class Tree{
    public node root = new node();
    int pass =0;
    void insert(String s,int indx) {
        node trv = root;
        for (int i = 0; i < s.length(); i++) {
            if (trv.ptrs[s.charAt(i) - 'A'] == null) {
                trv.ptrs[s.charAt(i) - 'A'] = new node();
                if(i==s.length()-1){
                    trv.ptrs[s.charAt(i)-'A'].val = indx;
                }else{
                    trv.ptrs[s.charAt(i)-'A'].val = -1;
                }
            }
            trv = trv.ptrs[s.charAt(i) - 'A'];
        }
    }
    
    private void visit(node trv){
        for(int i =0;i<26;i++){
            if(trv.ptrs[i]!=null){
                System.out.println(trv.ptrs[i].val+":"+((char)(i+'A')));
                visit(trv.ptrs[i]);
            }
        }
    }

    void visit(){
        this.visit(root);
    }
    void leaf(node trv){
        if(trv.val>=0){
            System.out.println(trv.val);
        }else{
            for(int i=0;i<26;i++){
                if(trv.ptrs[i]!=null){
                    if(trv.val>=0){
                        System.out.println(trv.ptrs[i].val);
                    }else{
                        leaf(trv.ptrs[i]);
                    }
                }
            }
        }
    }
    private void search(node trv,String s,int i){
        if(i<=s.length()-1){
            if(trv.ptrs[s.charAt(i)-'A']!=null){
                if(i==s.length()-1){
                    leaf(trv.ptrs[s.charAt(i)-'A']);
                }else{
                    search(trv.ptrs[s.charAt(i)-'A'], s, i+1);
                }
            }
        }
    }
    void query(String s){
        this.search(root, s, 0);
    }
}
public class Trie {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Tree t = new Tree();
        String txt = sc.next();
        int txtLen = txt.length();
        for(int i =0;i<txtLen;i++){
            t.insert(txt.substring(i,txtLen),i);
        }
        int q = sc.nextInt();
        while(q-->0){
           String m = sc.next();
           t.query(m);
        }
        sc.close();
    }
}