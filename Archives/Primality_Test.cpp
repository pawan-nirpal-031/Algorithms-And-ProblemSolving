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
#define Status(b) (cout<<(b?"READY FOR BATTLE\n":"NOT READY\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x



bool cases =0;

/*


1) Initialize both first and second smallest as INT_MAX
   first = second = INT_MAX
2) Loop through all the elements.
   a) If the current element is smaller than first, then update first 
       and second. 
   b) Else if the current element is smaller than second then update 
    second

*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll first = LLONG_MAX;
    ll second = LLONG_MAX;
    for(int i =0;i<n;i++){
         ll curr;
         cin>>curr;
         if(curr<first){
            second = first;
            first = curr;
         }else if(curr<second){
             second = curr;
         }
    }
    cout<<first+second<<'\n';
  }
  return 0;
} 
