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


int getsmallestlive(vector<bool>&live){
    for(int i =0;i<live.size();i++){
        if(live[i]) return i;
    }
    return -1;
}

int clearkthlive(vector<bool>&live,int small,int k){
    int times = 0; 
    while(times!=k){
        
    }
}

int hypothesis(int n,int k){
    int count = n; 
    vector<bool>live(n,1); 
    while(count>1){
        int smallest = getsmallestlive(live); 
        int cleared =  clearkthlive(live,smallest,k);
        cout<<"smallest : "<<smallest+1<<" chosen : "<<cleared+1<<'\n';
        count--;
    }
    return getsmallestlive(live);
}


int main(){
  FastIO;
  int n,k; 
  cin>>n>>k; 
  cout<<hypothesis(n,k)+1;
  return 0;
} 
// If Solved Mark (0/1) here => []