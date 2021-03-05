#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)

void ins(stack<int>&v,int tmp){
   if(v.empty()==true||v.top()<=tmp){
       v.push(tmp);
       return;
   }
   int le = v.top();
   v.pop();
   ins(v,tmp);
   v.push(le);
}


void srt(stack<int>&v){
    if(v.size()==1){
        return;
    }
    int tmp = v.top();
    v.pop();
    srt(v);
    ins(v,tmp);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    stack<int>v;
    while(n--){
        int x;
        cin>>x;
        v.push(x);
    }
    srt(v);
    while(!v.empty()){
        cout<<v.top()<<' ';
        v.pop();
    }
    return 0;
}