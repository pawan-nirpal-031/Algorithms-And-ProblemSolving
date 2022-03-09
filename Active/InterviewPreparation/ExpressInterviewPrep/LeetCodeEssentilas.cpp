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

class LRUCache {
    public:
        class node{
            public:
                int key;
                int val;
                node *next;
                node *prev;
            
            node(int k,int v){
                key = k;
                val = v;
                prev = next = NULL;
            }
        };

        node *head = new node(-1,-1);
        node *tail = new node(-1,-1);
        
        int capacity;
        unordered_map<int,node*>access;

        LRUCache(int capacity){
            this->capacity = capacity;
            head->next = tail;
            tail->prev = head;
        }

        void Remove(node *curr){

        }

        void Add(node *curr){

        }

        int get(int key){
            if(access.find(key)!=access.end()){
                node *required = access[key];
                int res = required->val;
                access.erase(key);
                Remove(required);
                Add(required);
                
                return res;
            }
            return -1;
        }
};

int main(){
  FastIO;
  
  return 0;
} 
