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


void Merge(int a[],int l,int r,int m){ 
    int n = r-l+1;
    int buffr[n];
    int i = l;
    int j = m+1;
    int k = 0;
    while(i<=m and j<=r){
        buffr[k++] = min(a[i],a[j]);
        if(a[i]<=a[j]) i++;
        else j++;
    }
    while(i<=m) buffr[k++] = a[i++];
    while(j<=r) buffr[k++] = a[j++];
    for(int i =0;i<n;i++) a[i+l] = buffr[i];
}

void Mergesort(int a[],int n,int l,int r){
   if(l<r){
       int m = (l+r)/2;
       Mergesort(a,n,l,m);
       Mergesort(a,n,m+1,r);
       Merge(a,l,r,m);
   }
}

int main(){
  FastIO;
  int n;
  cin>>n;
  int a[n];
  for(int &x : a) cin>>x;
  Mergesort(a,n,0,n-1);
  for(int x : a) cout<<x<<' ';
  return 0;
} 
