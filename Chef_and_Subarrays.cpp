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



bool cases =1;

/*
    prefix_prd[i,j] = prefix_prod[i]/prefix_prod[j-1] if j>0;

    1 2 3 4 5 
   [1 2 6 24 120 ]
*/

void SolveCase(){ // n could be 50 at max so bruteforce works
    ll n;
    cin>>n;
    ull a[n];
    ull dp[n]; // dp[i] = number of subarrays ending at i having sum = product;
    ull prfx_sum[n],prfx_prd[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
        if(i==0) prfx_prd[i] = prfx_sum[i] = a[i];
        else{
            prfx_prd[i] = prfx_prd[i-1]*a[i];
            prfx_sum[i] = prfx_sum[i-1]+a[i];
        }
        dp[i] =0;
    }
    for(int up = 0;up<n;up++){
        for(int low = 0;low<=up;low++){
            ull sm = prfx_sum[up] - (low>0?prfx_sum[low-1]:0);
            ull prd = (low==0?prfx_prd[up]:prfx_prd[up]/prfx_prd[low-1]);
            if(sm==prd) dp[up]+=1; 
        }
        if(up>0) dp[up]+=dp[up-1];
    }
    cout<<dp[n-1]<<'\n';
    
}

/*

O(Nlogsum) Complexity Solution 

Actually. Since there can’t be too many numbers greater than 1 in any such subarray (since the 
product grows exponentially, O(logsum) at most), you can store just the numbers 
greater than 1 in another array and try all their subarrays - there are O(Nlogsum) 
of them. For each such subarray, you know the product, which the ignored 1-s don’t change; this 
subarray corresponds to subarrays [a,b] in the original array, where aa and bb must be
in some, disjoint, ranges (only up to the first integer > 1>1 to the left/right); the sum 
is a linear function of b-ab−a and since it has to be equal to the product, any aa for which 
we have a valid bb gives one of the counted subarrays; we just need to find the range of such 
aa-s.For a given subarray of integers > 1>1, everything can be implemented in O(1)O(1), so we 
have O(Nlogsum) time complexity.


*/

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
     SolveCase();
  }
  return 0;
} 
