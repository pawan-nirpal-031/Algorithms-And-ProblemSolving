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




bool q2(){
  string s,t;
  cin>>s>>t;
  vector<int>spts;
  for(int i =0;i<s.length();i++) if(t[0]==s[i]) spts.push_back(i);
  
  for(int s_ptr : spts){
    bool move = 1;
    for(int t_ptr =0;t_ptr<t.length() and s_ptr<s.length();){
      if(t_ptr+1==t.length() and t[t_ptr]==s[s_ptr]) return 1;
      if(s[s_ptr]==t[t_ptr]){
        t_ptr+=1;
        if(s_ptr>0 and s_ptr<s.length()-1){
          s_ptr+=((move)?1:-1);
          continue;
        }
        move^=1;
       
      }else{
        if(move and s_ptr>0){
          s_ptr-=1;
          move^=1;
          continue;
        }
        if((not move) and s_ptr<s.length()-1){
          s_ptr+=1;
          move^=1;
        } 
      }
    }
  }

  
}

int main(){
  FastIO;
  q2();
  return 0;
} 
