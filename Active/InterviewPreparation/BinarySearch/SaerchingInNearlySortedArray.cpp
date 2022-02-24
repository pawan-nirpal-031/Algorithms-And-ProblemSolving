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

// nearly sorted array has a[i] at i-1 or i or i+1 if it were sorted search an element in it.

int SearchINNearlySortedArray(int a[],int n,int k){
    int l = 0;
    int h = n-1;
    while(l+1<h){
        int m = (l + (h-l)/2);
        if(a[m]==k) return m;
        else if(m-1>=l and a[m-1]==k) return m-1;
        else if(m+1<=h and a[m+1]==k) return m+1;
        else{
            if(m-2>=l and k<=a[m-2]) h = m-2;
            else if(m+2<=h and k>=a[m+2]) l = m+2;
        }
    }
    if(a[l]==k) return l;
    else if(a[h]==k) return h;
    return -1;
}

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int &x : a) cin>>x;
  cout<<SearchINNearlySortedArray(a,n,k);
  return 0;
} 
