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

string LCSUtil(vector<vector<string>>&Cache,string &lcs,string s[],string t[],int si,int ti,int n,int m){
  if(si>=n or ti>=m) return "";
  if(Cache[si][ti]!="NULL") return Cache[si][ti];
  if(s[si]==t[ti]) return Cache[si][ti] = (lcs+s[si]+" "+LCSUtil(Cache,lcs,s,t,si+1,ti+1,n,m));
  string first = LCSUtil(Cache,lcs,s,t,si+1,ti,n,m);
  string second = LCSUtil(Cache,lcs,s,t,si,ti+1,n,m);
  return Cache[si][ti] =  ((first.length()>second.length())?first:second);
}

void LCS(){
  int n,m;
  cin>>n>>m;
  string s[n];
  string t[m];
  for(int i =0;i<n;i++) cin>>s[i];
  for(int j =0;j<m;j++) cin>>t[j];
  vector<vector<string>>Cache(n,vector<string>(m,"NULL"));
  string lcs = "";
  lcs = LCSUtil(Cache,lcs,s,t,0,0,n,m);
  cout<<lcs;
}


int main(){
  FastIO;
  LCS();
  
  return 0;
} 

 