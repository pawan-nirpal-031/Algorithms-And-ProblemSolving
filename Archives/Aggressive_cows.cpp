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
#define SortVector(v) sort(v.begin(),v.end())
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

bool cases =1;
void GenrateRandom(){

}

bool CanPlace(ll locs[],ll n,ll d,ll c){
    ll last = locs[0];
    int cnt =1;
    for(int i =1;i<n;i++){
        if(locs[i]-last>=d){
            cnt+=1;
            last = locs[i];
        }
    }
    return cnt>=c;
}

void SolveCase(){
  ll n,c;
  cin>>n>>c;
  ll barns[n]; 
  for(int i=0;i<n;i++) cin>>barns[i];
  sort(barns,barns+n);
  ll left = 1;          
  ll right = 1e18; 
  while(right-left>1){
      ll mid = left + ((right-left)>>1);
      ((CanPlace(barns,n,mid,c))?left = mid:right=mid);
  }
  cout<<left<<'\n';
}

// left -  dist that we are sure where they can accodmatate the cows
// right -  dist that we are sure cows can never accodmodate the cows
// 1 1 1 1 1 [1] 0 0 0 0 0 ...
// x the maximum distance where c cows can be placed 

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
    SolveCase();
  }
  return 0;
} 