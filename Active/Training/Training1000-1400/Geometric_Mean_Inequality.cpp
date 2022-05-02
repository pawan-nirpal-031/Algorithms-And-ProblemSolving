// Problem Link : 
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


/*
Problem Statement : 



*/


/*
Author's solution : 



*/



void test(int n,int pos,int neg){
    int a[n]; 
    cout<<neg<<' '<<pos<<'\n';
    for(int i =0;i<n;i++){
        if(i<neg) a[i] = -1;
        else a[i] = 1;
    }
    bool yes = 0;
    do{ 
        int cnt =0;
        for(int i = 1;i<n-1;i++){
            if(a[i]*a[i]!=(a[i-1]*a[i+1])){
                cnt+=1;
            }
        }
        if(cnt==n-2){
            yes = 1;
            break;
        }
    }while(next_permutation(a,a+n));
    if(yes){
        for(int i=0;i<n;i++) cout<<a[i]<<' ';
        cout<<'\n';
    }else{
        cout<<"none\n";
    }
    
}

void unit(){
  int n,pos,neg;
  cin>>n>>pos>>neg;
  test(n,pos,neg);
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n; 
    int a[n];
    int pos =0,neg =0;
    for(int i =0;i<n;i++){
        cin>>a[i];
        pos+=(a[i]>0);
    }
    neg = n-pos;
    if(n&1){
        int half = (n>>1);
        Status((pos==half and neg==half+1) or (pos==half+1 and neg==half));
    }else{
        int half = (n>>1);
        Status((pos==half and neg==half) or ((half&1) and ((pos==half-1 and neg==half+1) or (pos==half+1 and neg==half-1))));
    }
  }
  return 0;
} 
// If Solved Mark (0/1) here => []