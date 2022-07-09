#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;


vector<ull> get_multiple_list(ull x){
  vector<ull>list; 
  while(x<=4*(1e18)){
    list.push_back(x); 
    x = x<<1;
  }
  return list;
}

pair<bool,int> look_up(vector<ull> &listx,ull x){
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

int what_power_of_2(ull x){
  int cnt =0; 
  while(x>0){
    x>>=1; 
    cnt+=1;
  }
  return cnt-1;
}

int main(){
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0);
  int t=1;
  cin>>t;
  while(t--){
      ull x,y; 
      cin>>x>>y;  
      if(x==0 || y==0){
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
        vector<ull>listx = get_multiple_list(x); 
        vector<ull>listy = get_multiple_list(y); 
        for(ull &upper : listy){
          auto p = look_up(listx,upper);
          if(p.first){
            indx = p.second;
            break;
          } 
        }
        if(indx>=0 && indx<listx.size()){ 
          ull meet_point = listx[indx]; 
          int step1 = what_power_of_2(meet_point/x);
          int step2 = what_power_of_2(meet_point/y);
          cout<<meet_point+step1+step2<<'\n';
        }else cout<<-1<<'\n';
      }
  }  
  return 0;
} 
