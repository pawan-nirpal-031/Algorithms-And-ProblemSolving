#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void testCase(){
  ll n;
  cin>>n;
  bool a[n];
  for(bool &x : a){
    cin>>x;
  }
  vector<ll>ZeroSegSizes;
  for(ll i=0;i<n;i++){
    if(a[i]){
      continue;
    }else{
      ll ptr = i;
      while(a[ptr+1]==0 && ptr+1<n){
        ptr++;
      }
      ZeroSegSizes.emplace_back(ptr-i+1);
      i = ptr;
    }
  }
  if(ZeroSegSizes.empty()){
    cout<<"No"<<'\n';
  }else if(ZeroSegSizes.size()==1){
    if(ZeroSegSizes[0]%2){
      cout<<"Yes"<<'\n';
    }else{
      cout<<"No"<<'\n';
    }
  }else{
    ll maxLen =0;
    ll indx =-1;
    for(ll i=0;i<ZeroSegSizes.size();i++){
      if(maxLen<ZeroSegSizes[i]){
        maxLen = ZeroSegSizes[i];
        indx =i;
      }
    }
    swap(ZeroSegSizes[0],ZeroSegSizes[indx]);

    maxLen =0;
    indx =-1;
    for(ll i=1;i<ZeroSegSizes.size();i++){
      if(maxLen<ZeroSegSizes[i]){
        maxLen = ZeroSegSizes[i];
        indx =i;
      }
    }
    swap(ZeroSegSizes[1],ZeroSegSizes[indx]);
    if((ZeroSegSizes[0]&1) && ((ZeroSegSizes[0]+1)/2)>ZeroSegSizes[1]){
      cout<<"Yes\n";
    }else{
      cout<<"No\n";
    }
  }

}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    testCase();
  }
  return 0;
} 

