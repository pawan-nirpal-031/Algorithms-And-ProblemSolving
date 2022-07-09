// Problem Link : 
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity __UINT64_MAX__
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
#define Show(x) for(const auto &v : x) cout<<v<<' ';


/*
Problem Statement : 



*/


/*
Author's solution : 



*/



vector<ull> GetList(ull x){
  vector<ull>list; 
  while(x<=4*(1e18)){
    list.push_back(x); 
    x = x<<1;
  }
  return list;
}

pair<bool,int> Search(vector<ull> &listx,ull x){
  int l = 0; 
  int h = listx.size()-1; 
  while(l+1<h){
    int m = (l+h)/2; 
    if(listx[m]==x) return {1,m};
    else if(x>listx[m]){
      l = m;
    }else h = m;
  }
  if(listx[l]==x) return {1,l}; 
  if(listx[h]==x) return {1,h}; 
  return {0,-1};
}

int GetNumSteps(ull x){
  int cnt =0; 
  while(x>0){
    x>>=1; 
    cnt+=1;
  }
  return cnt-1;
}

int main(){
  FastIO;
  int t=1;
  cin>>t;
  while(t--){
      ull x,y; 
      cin>>x>>y;  
      if(x==0 or y==0){
        if(x==0 and y==0){
          cout<<0<<'\n';
        }else cout<<-1<<'\n';
      }else{
        if(x==y){
          cout<<x<<'\n';
          continue;
        }
        int indx =-1;
        if(x>y) swap(x,y);
        vector<ull>listx = GetList(x); 
        vector<ull>listy = GetList(y); 
        for(ull &upper : listy){
          auto p = Search(listx,upper);
          if(p.first){
            indx = p.second;
            break;
          } 
        }
        if(indx>=0 and indx<listx.size()){ 
          ull meet_point = listx[indx]; 
          int step1 = GetNumSteps(meet_point/x);
          int step2 = GetNumSteps(meet_point/y);
          cout<<meet_point+step1+step2<<'\n';
        }else cout<<-1<<'\n';
      }
  }  
  return 0;
} 
// If Solved Mark (0/1) here => []