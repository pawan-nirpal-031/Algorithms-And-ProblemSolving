#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} 
#define NofSetBits(x) __builtin_popcount(x);
#define InpGrph(g,e) while(e--){ll x;ll y;cin>>x>>y ;g[x].pub(y);g[y].pub(x);}
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void Query(ll a,ll b,ll v,ll arr[],ll n){         
    arr[a]+=v;
    if(b+1<n){
        arr[b+1]-=v;
    }
}
void AdjustAndPrint(ll arr[],int n){
    for(ll i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
  FastIO;
  int q;
  cin>>q;
  ll arr[6]={0};
  while(q--){
    ll a,b,v;
    cin>>a>>b>>v;
    Query(a,b,v,arr,6);
  }
  AdjustAndPrint(arr,6);
  return 0;
}
