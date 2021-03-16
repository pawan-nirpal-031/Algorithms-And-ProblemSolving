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
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));


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

// ll WatchCpl(vector<ll>heights,ll n,ll k,ll ha,ll hb,ll ca,ll cb,int indx){
//    if(indx>=n) return INT_MAX;
//    if(dp[ha][hb]!=-1 and vis[ha][hb] and vis[hb][ha] ) return ca+cb;
   
//    if(not vis[ha][hb] and not vis[hb][ha]){
//     ll height_a = (ha<k?WatchCpl(heights,n,k,ha+heights[indx],hb,ca+=1,cb,indx+1):INT_MAX);
//     ll height_b = (hb<k?WatchCpl(heights,n,k,ha,hb+heights[indx],ca,cb+=1,indx+1):INT_MAX);
//     vis[ha][hb] = vis[hb][ha] = 1;
//     return dp[ha][hb] = dp[hb][ha] = min(height_a,height_b);
//    }
//    return dp[ha][hb];
// }

void PrimeTuples(){
  ll n = 1000005;
  vector<bool>primes(1000005,1);
  primes[0] = primes[1] = 0;
  for(int i =2;i*i<=n;i++){
    if(primes[i]){
      for(int j = i*i;j<=n;j+=i){
        primes[j] = 0;
      }
    }
  }
  vector<ll>prefix(n,0);
  for(int i = 5;i<=n;i++){
    if(primes[i] and primes[i-2]){
      prefix[i] = 1;
    }
    prefix[i] =prefix[i]+prefix[i-1];
  }
  int t;
  cin>>t;
  while(t--){
    ll x;
    cin>>x;
    cout<<prefix[x]<<'\n';
  }
}

void MaximizeIslands(){
  int n,m;
  cin>>n>>m;
  string grid[n];
  for(int i =0;i<n;i++){
    cin>>grid[i];
  }

  int islands1 =0,islands2 = 0;
  int changes1 = 0,changes2 = 0;
  for(int i =0;i<n;i++){
    for(int j =0;j<m;j++){
      char obj = grid[i][j];
      char g1,g2;
      if(i%2==0){
        if(j%2==0){
          g1 = '*';
          islands1++;
          g2 = '.';
        }else{
          g1 = '.';
          g2 = '*';
          islands2++;
        }
      }else{
        if(j%2==0){
          g1 = '.';
          g2 = '*';
          islands2++;
        }else{
          g1 = '*';
          g2 = '.';
          islands1++;
        }
      }

      if(g1!=obj) changes1+=1;
      if(g2!=obj) changes2+=1;
    }
  }

  if(islands1==islands2){
    cout<<min(changes1,changes2)<<'\n';
    return;
  }
  if(islands1>islands2){
    cout<<changes1<<'\n';
  }else{
    cout<<changes2<<'\n';
  }
}


void Lunchtime1(){
  ll n;
  cin>>n;
  ll e=0,o=0;
  for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    if(x&1){
      o++;
    }else{
      e++;
    }
  }
  cout<<min(e,o)<<'\n';
}

void Lunchtime2(){
  ll n;
  cin>>n;
  ll sum=0;
  for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    sum+=x;
  }
  cout<<((sum&1)?2:1)<<'\n';
}

void Lunchtime3(){
  int n;
  cin>>n;
  string seq;
  cin>>seq;
  vector<int>prefix(n,0),suffix(n,0);
  prefix[0] = seq[0]-'0';
  if(seq[n-1]-'0'==0) suffix[n-1] = 1;
  int case1 =0;
  for(int i =0;i<n;i++){
    if(seq[i]-'0') case1+=1;
    else suffix[i] = 1;
    if(i>=1){
      prefix[i] = (seq[i]-'0') + prefix[i-1];
    }
  }
  for(int i = n-2;i>=0;i--){
    suffix[i] +=suffix[i+1];
  }
  int min_subseq = min(case1,n- case1);
  for(int i =0;i<n-1;i++){
    min_subseq = min(min_subseq,prefix[i]+suffix[i+1]);
  }
  cout<<min_subseq<<'\n';
}

int main(int argc, const char** argv) {
    FastIO;
    int t;
    cin>>t;
    while(t--)
    Lunchtime3();
    return 0;
}