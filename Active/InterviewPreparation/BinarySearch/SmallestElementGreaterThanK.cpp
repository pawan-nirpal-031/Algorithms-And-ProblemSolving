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

int SmallestElementGreaterThanK(int a[],int n,int k){
    int l =-1;
    int h = n;
    while(l+1<h){
        int m = (l+h)/2;
        if(k>=a[m]) l = m;
        else h = m;
    }
    if(a[l]==k) return l;
    return h;
}

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int &x : a) cin>>x;
  cout<<SmallestElementGreaterThanK(a,n,k);
  return 0;
} 
