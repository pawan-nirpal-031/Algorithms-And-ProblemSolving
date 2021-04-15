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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


void UnitTests(){
    
}


bool cases =1;

void RandomGenrator(){

}



int main(){
  FastIO;
  int n,m,k;
  //cin>>n>>m>>k;
  n = 1000;
  m = 100;
  k = 5 + rand()%4;
  cout<<n<<" "<<m<<" "<<k<<endl;
  vector<vector<int>>g(n,vector<int>(m,0));
  for(int i=0;i<n;i++){
      for(int j =0;j<m;j++){
          //cin>>g[i][j];
          if(i==0){
              if(j==0){
                  g[i][j] =0;
              }else{
                  g[i][j] = g[i][j-1] + rand()%5;
              }
          }else{
              g[i][j] = g[i-1][j] + rand()%5;
          }
      }
  }
  int cnt =0;
  for(int left =0;left<m;left++){
      vector<int>cache(n,0);
      for(int right =left;right<m;right++){
            int x = right - left + 1;
            for(int row =0;row<n;row++) cache[row] = (right==left?g[row][left]:cache[row]+g[row][right]);
            int sum =0;
            for(int i =0;i<x;i++) sum+=cache[i];
            for(int l =0;l<=(n-x);l++){
                int r = l + x - 1;
                if(r<n-1){
                    r+=1;
                    sum+=(cache[r] - cache[l]);
                    if((sum/x*x)>=k) cnt+=1;
                }
            }
      }
  }
  cout<<cnt<<endl;
  return 0;
} 
