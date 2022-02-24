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

int NumberOfTimesRotated(int a[],int n){
    int l =0;
    int h = n-1;
    int smallest_indx = -1;
    while(l+1<h){
        int m = l + (h-l)/2;
        int prev = (m+n-1)%n;
        int nxt = (m+1)%n;
        if(a[m]<a[nxt] and a[m]<a[prev]) return m;
        else if(a[m]<=a[h]) h = m;
        else l = m;
    }
    return (a[l]<a[h]?l:h);
}   // returns indx of Min element, this can be extended into multiple problems furthur for ex, search an element in rotated sorted array so the soln is to get the indx of min element and we have a partion ie [1,indx-1] is sorted and [indx, n] are sorted so just apply two binary searches


int main(){
  FastIO;
  int n;
  cin>>n;
  int a[n];
  for(int &x : a) cin>>x;
  cout<<(n-NumberOfTimesRotated(a,n))%n;
  return 0;
} 
