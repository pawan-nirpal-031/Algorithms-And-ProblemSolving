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
    int data;
    int vertical_no;
    node *lft;
    node *right;
};

class Tree{
    node *root;
    Tree(){
        root = NULL;
    }
    void Insert(){

    }
};

void TopView(){
    int n;
    cin>>n;
    int m = n-1;
    while(m--){
        int n1,n2;
        char d;
        cin>>n1>>d>>n2;
        
    }
}

int main(){
  FastIO;
  TopView();
  return 0;
} 
