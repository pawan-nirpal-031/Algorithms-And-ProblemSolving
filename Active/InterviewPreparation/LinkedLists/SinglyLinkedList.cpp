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

class node{
    public:
        int key;
        node *nxt;

        node(){
            this->nxt = NULL;
        }
        node(int x){
            this->key = x;
            this->nxt = NULL;
        }
};


class SinglyLinkedList{
    public:
        node *head;
        
        SinglyLinkedList(){
            head = NULL;
        }
        
        SinglyLinkedList(node *n){
            this->head = n;
        }
        
        node* Insert(int x){
            if(head==NULL){
                head = new node(x);
                return head;
            }
            node *tmp = head;
            while(tmp->nxt!=NULL) tmp = tmp->nxt;
            tmp->nxt = new node(x);
            return tmp->nxt;
        }
        void Show(node *tmp){
            while(tmp){
                cout<<tmp->key<<' ';
                tmp = tmp->nxt;
            }
        }
        void PrintReverse(node *tmp){
            if(tmp==NULL) return;
            PrintReverse(tmp->nxt);
            cout<<tmp->key<<' ';
        }
        bool Search(node*tmp,int x){
            if(tmp!=NULL and tmp->key==x) return 1;
            if(tmp==NULL) return 0;
            return Search(tmp->nxt,x);
        }

        int LengthOfList(node *tmp){
            if(tmp==NULL) return 0;
            return 1 + LengthOfList(tmp->nxt);
        }

        void ReverseLinkedList(node *it){
            if(it==NULL or it->nxt==NULL) return;
            node *prev = NULL;
            node *curr = it;
            node *tmp = curr->nxt;
            if(tmp->nxt==NULL){
                tmp->nxt = curr;
                curr->nxt = prev;
                this->head = tmp;
                return;
            } 
            while(tmp!=NULL){
                curr->nxt = prev;
                prev = curr;
                curr = tmp;
                tmp = curr->nxt;
            }
            curr->nxt = prev;
            this->head = curr;
        }

        void MostOptimizedReverseLinkedList(node *it){
            if(it==NULL) return;
            node *prev = NULL;
            node *curr = it;
            while(curr){
                node *nxt = curr->nxt;
                curr->nxt = prev;
                prev = curr;
                curr = nxt;
            }
            this->head = prev;
        }

        void RecursiveReverse(node *it){
            if(it->nxt==NULL){
                head = it;
                return;
            }
            RecursiveReverse(it->nxt);
            it->nxt->nxt = it;
            it->nxt = NULL;
        }

        bool DetectCycleUsingHashing(node *tmp){
            unordered_set<node*>data;
            while(tmp){
                auto it = data.find(tmp);
                if(it!=data.end()) return 1;
                data.insert(tmp);
                tmp = tmp->nxt;
            }
            return 0;

        }

        bool DetectCycleOptimized(node *tmp){
            node *fast = tmp;
            node *slow = tmp;
            while(fast->nxt!=NULL and fast->nxt->nxt!=NULL){
                slow = slow->nxt;
                fast = fast->nxt->nxt;
                if(slow==fast) return 1;
            }
            return slow==fast;
        }

        void RotateLinkedList(node *it,int k){
            int l = this->LengthOfList(it);
            if(k%l==0) return;
            k = k - (l*(k/l));
            int c = 0;
            while(it!=NULL and ++c<(l-k)) it = it->nxt;
            if(it==NULL) return;
            node *trv = it;
            while(trv->nxt!=NULL) trv = trv->nxt;
            trv->nxt = head;
            head = it->nxt;
            it->nxt = NULL;
        }

        node *MiddleOfLinkedList(node *it){
            node *slow = it;
            node *fast = it;
            while(fast!=NULL and fast->nxt!=NULL){
                slow = slow->nxt;
                fast = fast->nxt->nxt;
            }
            return slow;
        }

        node *MergeSortedLinkedLists(node *it1, node *it2){
            if(it1==NULL) return it2;
            if(it2==NULL) return it1;
            if((it1->key)>(it2->key)) swap(it1,it2);
            node *res = it1;
            while(it1!=NULL and it2!=NULL){
                node *tmp = NULL;
                while(it1!=NULL and it1->key<=it2->key){
                    tmp = it1;
                    it1 = it1->nxt;
                }
                tmp->nxt = it2;
                swap(it1,it2);
            }
            return res;
        } 


        node *AddTwoNumbers(node *l1,node *l2){
            node *dummy = new node(-1);
            node *tmp = dummy;
            int carry =0;
            while(carry or (l1!=NULL or l2!=NULL)){
                int sum =0;
                if(l1){
                    sum+=l1->key;
                    l1 = l1->nxt;
                }
                if(l2){
                    sum+=l2->key;
                    l2 = l2->nxt;
                }
                sum+=carry;
                carry = sum/10;
                node *nn = new node(sum%10);
                tmp->nxt = nn;
                tmp = tmp->nxt;
            }
            return dummy->nxt;
        }

        node* CheckIntersection(node *n1,node *n2){
            node *tmp1 = n1;
            node *tmp2 = n2;
            unordered_set<node*>hs;
            while(tmp1){
               hs.insert(tmp1);
               tmp1 = tmp1->nxt;
            }
            while(tmp2){
                if(hs.find(tmp2)!=hs.end()) return tmp2;
                tmp2 = tmp2->nxt;
            }
            return NULL;
        }

        bool CheckIntersectionOptimized(node *n1,node *n2){
            node *tmp1 = n1;
            node *tmp2 = n2;
            while(tmp1->nxt!=NULL) tmp1 = tmp1->nxt;
            while(tmp2->nxt!=NULL) tmp2 = tmp2->nxt;
            return (tmp1==tmp2 and tmp1!=NULL);
        }

};




int main(){
  FastIO;
  SinglyLinkedList l1,l2;
  l1.head = new node(1);
  l2.head = new node(2);
  l1.head->nxt = new node(2);
  l2.head->nxt = new node(8);
  l2.head->nxt->nxt = new node(1);
  l2.head->nxt->nxt->nxt = new node(3);
  node *ins = new node(8);
  l1.head->nxt->nxt = ins;
  l2.head->nxt->nxt->nxt->nxt = ins;
  ins->nxt = new node(9);
  ins->nxt->nxt = new node(19);
  ins->nxt->nxt->nxt = NULL;
  bool res = SinglyLinkedList().CheckIntersectionOptimized(l1.head,l2.head);
  if(res) cout<<"yes";
  else cout<<"none";
  return 0;
} 
