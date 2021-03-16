#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define getl(s) getline(cin,s);

void adjust(stack<int>&s,int tmp){
  if(s.empty()){
    s.push(tmp);
    return;
  }else{
    int res = s.top();
    s.pop();
    adjust(s,tmp);
    s.push(res);
  }
}

void rvrse(stack<int>&s){
  if(s.empty()){
    return;
  }else{
    int tmp = s.top();
    s.pop();
    rvrse(s);
    adjust(s,tmp);
  }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  stack<int>s;
  for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    s.push(x);
  }
  stack<int>cp(s);
  while(!cp.empty()){
    cout<<cp.top()<<' ';
    cp.pop();
  }
  rvrse(s);
  cout<<'\n';
  while(!s.empty()){
    cout<<s.top()<<' ';
    s.pop();
  }
  return 0;
}
