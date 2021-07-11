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

const int trie_size = 27;

class node{
    public:
        int count; // nof strings that start with the prefix that ends at this node
        bool is_end;
        node* links[trie_size];
        node(){
            count = 0;
            is_end = 0;
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
    public:
        Trie(){
            root = node().GetNewNode();
            number_of_nodes = 0;
        }

        void Insert(string s){
            node* temp = root;
            for(int i =0;i<s.length();i++){
                int indx = s[i]-'@';
                if(temp->links[indx]==null){
                    temp->links[indx] = node().GetNewNode();
                    number_of_nodes+=1;
                }
                temp->count+=1;
                temp = temp->links[indx];
            }
            temp->is_end = 1;
        }

        
        int NumberOFNodes(){
            return number_of_nodes;
        }

        void DfsTraverseUtil(int indx,node *curr,string s){
          if(indx==0){
            cout<<s<<'$'<<'\n';
            return;
          }
          int lks =0;
          for(int i =1;i<trie_size;i++) if(curr->links[i]!=null) lks+=1;
          if(lks==1) s+=(char)(indx+64);
          if(lks>1) cout<<s<<'\n';
          for(int i =0;i<trie_size;i++) if(curr->links[i]!=null) DfsTraverseUtil(i,curr->links[i],s);
        }

        void DfsTraverse(){
          node *temp = root;
          for(int i =0;i<trie_size;i++){
            if(temp->links[i]!=null){
              string s;
              DfsTraverseUtil(i,temp,s);
            }
          }
        }

        bool Search(string s){
            node *temp = root;
            for(int i=0;i<s.length();i++){
                int indx = s[i]-'@';
                if(temp->links[indx]==null) return 0;
                temp = temp->links[indx];
            }
            return temp->is_end;
        }
};



int main(){
  FastIO;
  Trie t;
  for(int i =0;i<4;i++){
    string s;
    cin>>s;
    s[s.length()-1] = '@';
    t.Insert(s);
  }
  t.DfsTraverse();
  return 0;
} 
