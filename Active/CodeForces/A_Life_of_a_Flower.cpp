// Problem Link : 
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


/*
Problem Statement : 



*/


/*
Author's solution : 



*/

class Math{
    public:
    int Floor(int x,int y){
        return floor(x*1.0/y);
    }
    int Ceil(int x,int y){
        return ceil(x*1.0/y);
    }
};


int solve(){
    int n;
    cin>>n;
    vector<bool>state(n,0);
    int height = 1;
    for(int i =0;i<n;i++){
        bool b;
        cin>>b;
        state[i] = b;
        if(i==0) height+=b;
        else{
            if(state[i] and state[i-1]) height+=5;
            else if(state[i]==0 and state[i-1]==0) return -1;
            else height+=b;
        }
    }
    return height;
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) cout<<solve()<<'\n';
  return 0;
} 
// If Solved Mark (0/1) here => []