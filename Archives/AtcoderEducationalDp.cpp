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

void Frog1(){
  int n;
  cin>>n;
  int k = 2;
  vector<ll>h(n,0);
  vector<ll>dp(n,Mod);
  for(int i =0;i<n;i++){
    cin>>h[i];
  }
  dp[0] = 0;
  for(int i =1;i<n;i++){
    for(int j = 1 ;j<=k;j++){
      if(i-j>=0){
        dp[i] =  min(dp[i],abs(h[i]-h[i-j])+dp[i-j]);
      }
    }
  }  
  cout<<dp[n-1];
}


void Frog2(){
  int n,k;
  cin>>n>>k;
  vector<ll>h(n,0);
  vector<ll>dp(n,Mod);
  for(int i =0;i<n;i++){
    cin>>h[i];
  }
  dp[0] = 0;
  for(int i =1;i<n;i++){
    for(int j = 1 ;j<=k;j++){
      if(i-j>=0){
        dp[i] =  min(dp[i],abs(h[i]-h[i-j])+dp[i-j]);
      }
    }
  }  
  cout<<dp[n-1];
}


void Vacation(){
  int n;
  cin>>n;
  ll a[n][3];
  ll dp[n][3];
  for(int i=0;i<n;i++){
      for(int j =0;j<3;j++){
          cin>>a[i][j];
      }
  }
  for(int i =0;i<3;i++){
      dp[0][i] = a[0][i];
  }
  for(int i =1;i<n;i++){
      dp[i][0] = a[i][0] + max(dp[i-1][1],dp[i-1][2]);
      dp[i][1] = a[i][1] + max(dp[i-1][0],dp[i-1][2]);
      dp[i][2] = a[i][2] + max(dp[i-1][0],dp[i-1][1]);
  }
  cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}

vector<vector<ll>>dp(101,vector<ll>(100005,-1));

ll KnapSack1Util(vector<pair<ll,ll>>&item,int n,int max_weight,int curr_item,int curr_weight){
    if(curr_item==n) return 0;
    if(dp[curr_item][curr_weight]!=-1) return dp[curr_item][curr_weight];
    ll total_value = 0;
    total_value = max(total_value,KnapSack1Util(item,n,max_weight,curr_item+1,curr_weight));
    if(max_weight>=curr_weight+item[curr_item].first) total_value = max(total_value,item[curr_item].second+KnapSack1Util(item,n,max_weight,curr_item+1,curr_weight+item[curr_item].first));
    return dp[curr_item][curr_weight] = total_value;
}

void KnapSack1(){
    int n,w;
    cin>>n>>w;
    vector<pair<ll,ll>>item(n,{0,0});
    for(int i =0;i<n;i++){
        ll wi,vi;
        cin>>wi>>vi;
        item[i].first = wi;
        item[i].second = vi;
    }
    cout<<KnapSack1Util(item,n,w,0,0);
}


vector<vector<ll>>dp2(100,vector<ll>(100005,-1));
ll KnapSack2Util(vector<pair<ll,ll>>&item,ll max_weight,int n,int curr_item,int val_to_achive){
    if(curr_item==n){
        if(val_to_achive==0) return 0;
        else max_weight+1;
    }
    if(dp2[curr_item][val_to_achive]!=-1) return dp2[curr_item][val_to_achive];
    
    ll min_wight = max_weight+1;
    min_wight = min(min_wight,KnapSack2Util(item,max_weight,n,curr_item+1,val_to_achive));
    if(val_to_achive>=item[curr_item].second) min_wight = min(min_wight,item[curr_item].first+KnapSack2Util(item,max_weight,n,curr_item+1,val_to_achive-item[curr_item].second));
    return dp2[curr_item][val_to_achive] = min_wight;
}

void KnapSack2(){
    ll n,w;
    cin>>n>>w;
    vector<pair<ll,ll>>item(n,{0,0});
    for(int i =0;i<n;i++){
        ll wi,vi;
        cin>>wi>>vi;
        item[i].first = wi;
        item[i].second = vi;
    }
    ll max_val =0;
    for(ll v = 1;v<=100000;v++){
        if(KnapSack2Util(item,w,n,0,v)<=w){
            max_val = max(max_val,v);
        }
    }
    cout<<max_val;
}

string lcs;
ll LCSUtil(vector<vector<int>>&Cache,string &lcs,string s,string t,int si,int ti){
  if(si>=s.length() or ti>=t.length()) return 0;
  if(Cache[si][ti]!=-1) return Cache[si][ti];
  if(s[si]==t[ti]) return Cache[si][ti] = 1+LCSUtil(Cache,lcs,s,t,si+1,ti+1);
  return Cache[si][ti] = max(LCSUtil(Cache,lcs,s,t,si+1,ti),LCSUtil(Cache,lcs,s,t,si,ti+1));
}

void LCS(){
  string s,t;
  cin>>s>>t;
  lcs = "";
  vector<vector<int>>Cache(s.length(),vector<int>(t.length(),-1));
  int lcslen = LCSUtil(Cache,lcs,s,t,0,0);
  int i = 0;
  int j = 0;
  int cntr = 0;
  cout<<lcslen<<"\n";
  // while(cntr!=lcslen){
  //   cout<<i<<" :  "<<j<<'\n';
  //   if(s[i]==t[j]){
  //     lcs+=s[i];
  //     i+=1;
  //     cntr+=1;
  //     j+=1;
  //   }else if(Cache[i+1][j]>=Cache[i][j+1]){
  //     i+=1;
  //   }else {
  //     j+=1;
  //   }
  // }
  cout<<lcs;
}


inline bool exist(const std::string& name) {
  ifstream file(name); 
  return ((not file)?0:1);
}


int main(){
  FastIO;
  int x = 22343;
  string p = to_string(x);
  cout<<p;
  return 0;
} 