import java.util.*;


class Node{
    private String txt;
    private List<Node> chilNodes;
    private int posIndx;
    Node(String word,int pos){
        this.posIndx= pos;
        this.txt = word;
        this.chilNodes = new ArrayList<>();
    }
    List<Node> getChList(){
        return this.chilNodes;
    }
    public String getTxt(){
        return this.txt;
    }
    public int getPosition(){
        return this.posIndx;
    }
    public void setPosition(int pos){
        this.posIndx = pos;
    }
    public void setChildren(List<Node> Ch){
        this.chilNodes = Ch;
    }
    public void setTxt(String newTxt){
         this.txt = newTxt;
    }

}

class SuffixTree{
    private static final String WORD_TER = "$";
    private static final int UNDF = -1;
    private Node root;
    private String fullText;
    public SuffixTree(String txt){
        fullText = txt;
        root = new Node("",this.UNDF);
    }
    private void AddChildNode(Node ParNode,int indx, String s){
        ParNode.getChList().add(new Node(s,indx));
    }
    private String GetLongestPrefix(String s1,String s2){
        int cmpLen = Math.min(s1.length(),s2.length());
        for(int i =0;i<cmpLen;i++){
            if(s1.charAt(i)!=s2.charAt(i)){
                return s1.substring(0,i);
            }
        }
        return s1.substring(0,cmpLen);
    }
    private void SplitParChildNode(Node Par,String ParNewtxt,String childNewTxt){
        Node childNode = new Node(childNewTxt,Par.getPosition());
        if(Par.getChList().size()>0){
            while(Par.getChList().size()>0){
                childNode.getChList().add(Par.getChList().remove(0));
            }
        }
        Par.getChList().add(childNode);
        Par.setTxt(ParNewtxt);
        childNode.setPosition(this.UNDF);
    }
    private List<Node> getAllNodesInPath(String patt,Node strtNode,boolean isAllowdPartialMatch){
        List<Node> nodes = new ArrayList<>();
        for(int i=0;i<strtNode.getChList().size();i++){
            Node curr = strtNode.getChList().get(i);
            String nodetxt = curr.getTxt();
            if(patt.charAt(0)==nodetxt.charAt(0)){
                if(isAllowdPartialMatch && patt.length()<=nodetxt.length()){
                    nodes.add(curr);
                    return nodes;
                }
                int cmpLen = Math.min(nodetxt.length(),patt.length());
                for(int j =1;j<cmpLen;j++){
                    if(patt.charAt(j)!=nodetxt.charAt(j)){
                        if(isAllowdPartialMatch){
                            nodes.add(curr);
                        }
                        return nodes;
                    }
                }
                nodes.add(curr);
                if(patt.length()>cmpLen){
                    List<Node> nodes2 = getAllNodesInPath(patt.substring(cmpLen),curr, isAllowdPartialMatch);
                    if(nodes2.size()>0){
                        nodes.addAll(nodes2);
                    }else if(!isAllowdPartialMatch){
                        nodes.add(null);
                    }
                }
                return nodes;
            }
        }
       return nodes;
    }
}


public class TrieMatching{
    public static void main(String[] args) {
        
    }
}