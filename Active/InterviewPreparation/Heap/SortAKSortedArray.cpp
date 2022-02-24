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


// Given an array that is nearly sorted ie the element that is supposed to be at ith pos in sorted array is either i+k indx away at max or i-k indx behind at max, we need to sort the array, the idea is to use a min heap as a window of size k and push elements in it until its size less than equal to k, once size exceeds k we pop the smallest and replace.


int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  priority_queue<int,vector<int>,greater<int>>heap;
  int a[n];
  for(int &x : a) cin>>x;
  vector<int>ans;
  for(int i =0;i<n;i++){
    heap.push(a[i]);
    if(heap.size()>k){
      ans.push_back(heap.top());
      heap.pop();
    }
  }
  while(not heap.empty()){
    ans.push_back(heap.top());
    heap.pop();
  }
  for(int c : ans) cout<<c<<" ";
  return 0;
} 
