#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity 1e18LL
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


int FirstMissingpostive(int a[],int n){ 
/*
  swap sort based solution : 
  The idea is very simple just put the elements in thier proper places once they are there 
  simply check the first index that misbehaves the policy
*/
    for(int i =0;i<n;i++){
      if(a[i]<1 or a[i]>n) continue;
      while(a[i]!=i+1 and (a[i]>=1 and a[i]<=n) and (a[i]!=a[a[i]-1])) swap(a[i],a[a[i]-1]);
    }
    for(int i =0;i<n;i++) if(a[i]!=i+1) return i+1;
    return n+1;
}


int LongestSubstringWithNonRepeatingChars(string s){
  int n= s.length();
  vector<int>f(26,0);
  int l = 0;
  int r = -1;
  int count = 0;
  int ans =1;
  while(r<n){
    if(count>0){
      f[s[l]-'a']--;
      if(f[s[l]-'a']==1) count--;
      l++;
    }else{
      r++;
      if(r==n) break;
      f[s[r]-'a']++;
      if(f[s[r]-'a']==2) count++;
    }
    if(count==0) ans = max(ans,r-l+1);
  }
  return ans;
}



int main(){
  FastIO;
  string s;
  cin>>s;
  cout<<LongestSubstringWithNonRepeatingChars(s);
  return 0;
} 
