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


int First(int a[],int n,int k){
    int l =0;
    int h = n-1;// points to first occurance of k
    while(l+1<h){
        int m = l + (h-l)/2;
        if(k<=a[m]) h = m;
        else l = m;
    }
    if(a[l]==k) return l;
    else if(a[h]==k) return h;
    return -1;
}

int Last(int a[],int n,int k){
    int l = 0; // points to last occurance 
    int h = n-1;
    while(l+1<h){
        int m = l + (h-l)/2;
        if(a[m]<=k) l= m;
        else h = m;
    }
    if(a[h]==k) return h;
    else if(a[l]==k) return l;
    return -1;
}

int CountOfElementInSorted(int a[],int n,int k){
    int first = First(a,n,k);
    if(first==-1) return 0;
    int last = Last(a,n,k);
    return last-first+1;
}

int main(){
  FastIO;
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int &v : a) cin>>v;
  cout<<CountOfElementInSorted(a,n,x);
  return 0;
} 
