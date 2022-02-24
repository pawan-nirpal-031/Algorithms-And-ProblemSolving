#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef pair<int,pair<int,int>> Tuple;
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



// Simple as you read the array maintain a max heap of size k because we remove all the unnecessary elements that would appear in sorted sequence which are not useful and are redundant we need not sort them so complexity reduces from nlogn to nlogk because we always maintain a k size heap and pop whenever size exceeds k  

// priority_queue<int,vector<int>,greater<int>>min_heap; // min heap decln



int main(){
  FastIO;
  priority_queue<int>heap; // max heap decln 
  int n,k;
  cin>>n>>k;
  for(int i =0;i<n;i++){
      int x;
      cin>>x;
      heap.push(x);
      if(heap.size()>k) heap.pop();  
  }
  cout<<heap.top();
  return 0;
} 
