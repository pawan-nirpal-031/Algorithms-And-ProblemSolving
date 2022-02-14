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

class Node{
    public:
    int v;
    Node *nxt;

    Node* NewNode(int v){
        Node *n = new Node();
        n->v = v;
        n->nxt = NULL;
        return n;
    }
};



class SinglyLinkedList{
    public:
    Node *head, *tail;
    SinglyLinkedList(){
        head = tail = NULL;
    }

    bool IsEmpty(){
        return (head==tail and head==NULL);
    }

    void Insert(int e){
        Node *n = Node().NewNode(e);
        if(IsEmpty()){
            head = tail = n;
        }else{
            tail->nxt = n;
            tail = n;
        }
    }

    bool Search(int v){
        Node *tmp = head;
        while(tmp!=NULL){
            if(tmp->v==v) return true;
            tmp = tmp->nxt;
        }
        return false;
    }

    void Delete(int v){
        Node *tmp = head;
        while(tmp!=NULL){
            if(tmp->nxt->nxt==NULL and tmp->nxt->v==v){
                Node *x = tmp->nxt;
                tmp->nxt = NULL;
                
            }
        }
    }

    void Show(){
        Node *tmp = head;
        while(tmp!=NULL){
            cout<<tmp->v<<" ";
            tmp = tmp->nxt;
        }
    }

};



int main(){
  FastIO;
  SinglyLinkedList L;
  int q;
  cin>>q;
  while(q--){
      int v;
      cin>>v;
      L.Insert(v);
  }
  L.Show();
  return 0;
} 
