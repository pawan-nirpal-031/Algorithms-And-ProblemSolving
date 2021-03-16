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


void SolveCase(){
    int n,m;
    cin>>n>>m;
    string g[n];
    int cnt1=0;
    vector<int>row(n,0),col(m,0);
    vector<vector<int>>dp(n,vector<int>(m,0));
    int sx = -1;
    int sy = -1;
    for(int i =0;i<n;i++){
        int r =0;
        cin>>g[i];
        for(int j =0;j<m;j++){
            int x = g[i][j]-'0';
            col[j]+=x;
            dp[i][j] = x;
            if(x==1) r+=1;
            if(sx==-1 and sy==-1 and x) {
                sx= i;
                sy = j;
            }
        }
        row[i] = r;
        cnt1+=r;
    }
    int cl = 0;
    int rl = 0;
    for(int i=0;i<n;i++) {
        if(row[i]>0) rl+=1;
    }
    for(int i=0;i<m;i++){
      if(col[i]>0) cl+=1; 
    } 
    bool yes =0;
    if(sx>-1 and sy>-1 and rl>0 and cl>0){
        for(int  i= sx;i<=(sx+rl-1);i++){
            for(int j = sy+1;j<=(sy+cl-1);j++){
                dp[i][j]+=dp[i][j-1];
            }
        }
        for(int i = sx+1;i<=(sx+rl-1);i++){
            for(int j = sy;j<=(sy+cl-1);j++){
                dp[i][j]+=dp[i-1][j];
            }
        }
        yes = (dp[sx][sy]==1 and dp[sx][sy+cl-1]==cl and dp[sx+rl-1][sy]==rl and dp[sx+rl-1][sy+cl-1]==cl*rl);
    }
    Status(yes);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--)
    SolveCase();
  return 0;
} 