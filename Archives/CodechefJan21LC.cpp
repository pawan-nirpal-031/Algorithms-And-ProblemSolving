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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAns(b) cout<<(b?"Yes\n":"No\n"); 

int  Elections(){
   int m;
   cin>>m;
   ll a[m];
   ll sum_a =0;
   for(ll &x : a){
       cin>>x;
       sum_a+=x;
   }
   int n;
   cin>>n;
   ll b[n];
   ll sum_b =0;
   for(ll &x : b){
       cin>>x;
       sum_b+=x;
   }

   sort(a,a+m);
   sort(b,b+n);
   int i =0;
   int j = n-1;
   ll sdiff = sum_a-sum_b;
   ll ediff = b[j] - a[i];
   int ans =0;
   while(sdiff<=0){
       if(i<m and j>=0){
           ediff = b[j] - a[i];
           if(ediff<=0){
               return -1;
           }else{
               sum_a+=ediff;
               sum_b-=ediff;
               i++;
               j--;
               ans++;
               sdiff = sum_a-sum_b;
           }
       }else{
           return -1;
       }
   }
   return ans;
}

vector<vector<ll>>dp(4000,vector<ll>(4000,-1));
vector<vector<bool>>vis(4000,vector<bool>(4000,0));

ll WatchCpl(vector<ll>heights,ll n,ll k,ll ha,ll hb,ll ca,ll cb,int indx){
   if(indx>=n) return INT_MAX;
   if(dp[ha][hb]!=-1 and vis[ha][hb] and vis[hb][ha] ) return ca+cb;
   
   if(not vis[ha][hb] and not vis[hb][ha]){
    ll height_a = (ha<k?WatchCpl(heights,n,k,ha+heights[indx],hb,ca+=1,cb,indx+1):INT_MAX);
    ll height_b = (hb<k?WatchCpl(heights,n,k,ha,hb+heights[indx],ca,cb+=1,indx+1):INT_MAX);
    vis[ha][hb] = vis[hb][ha] = 1;
    return dp[ha][hb] = dp[hb][ha] = min(height_a,height_b);
   }
   return dp[ha][hb];
}


int main(){
  FastIO;
  ll n,k;
  cin>>n>>k;
  vector<ll>h(n,0);
  for(ll &x : h) cin>>x;
  cout<<WatchCpl(h,n,k,0,0,0,0,0);
 
  return 0;
} 

