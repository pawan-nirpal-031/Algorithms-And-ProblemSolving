#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x
#define null NULL

const int trie_size = 26;
class node{
    public:
        int count; // nof strings that start with the prefix that ends at this node
        bool is_end;
        int label;
        node* links[trie_size];
        node(){
            count = 0;
            is_end = 0;
            label = -1;
            for(int i =0;i<trie_size;i++) links[i] = NULL;
        }
        node* GetNewNode(){
            return new node();
        }
};

class Trie{
    private:
        node* root;
        int number_of_nodes;
        void DepthFirstTraverseutil(node *curr,int &lbl){
            if(curr==null) return;
            if(curr->label==-1){
                curr->label = lbl++;
                for(int i=0;i<26;i++) if(curr->links[i]!=null) DepthFirstTraverseutil(curr->links[i],lbl);
            }
        }
    public:
        Trie(){
            root = node().GetNewNode();
            root->label = 0;
            number_of_nodes = 0;
        }

        void Insert(string s){
            node* temp = root;
            for(int i =0;i<s.length();i++){
                int indx = s[i]-'A';
                if(temp->links[indx]==null){
                    temp->links[indx] = node().GetNewNode();
                    number_of_nodes+=1;
                }
                temp->count+=1;
                temp = temp->links[indx];
            }
            temp->is_end = 1;
        }

        void DepthFirstTraverse(){
            node *temp = root;
            int lbl = 1;
            for(int i =0;i<26;i++){
                if(temp->links[i]!=null){
                    DepthFirstTraverseutil(temp->links[i],lbl);
                }
            }
        }
        
        int NumberOFNodes(){
            return number_of_nodes;
        }

        void SolveUtil(node* par,node *child,int indx){
            if(child==null) return;
            cout<<par->label<<"->"<<child->label<<":"<<(char)(indx+65)<<'\n';
            for(int i=0;i<26;i++){
                if(child->links[i]!=null) SolveUtil(child,child->links[i],i);
            }
        }

        void Solve(){
            node *temp = root;
            for(int i =0;i<26;i++){
                if(temp->links[i]!=null){
                    SolveUtil(temp,temp->links[i],i);
                }
            }
        }

        bool Search(string s){
            node *temp = root;
            for(int i=0;i<s.length();i++){
                int indx = s[i]-'a';
                if(temp->links[indx]==null) return 0;
                temp = temp->links[indx];
            }
            return temp->is_end;
        }
};



int main(){
  FastIO;
  Trie t;
  int w;
  cin>>w;
  for(int i=0;i<w;i++){
      string s;
      cin>>s;
      t.Insert(s);
  }
  t.DepthFirstTraverse();
  t.Solve();
  return 0;
} 
