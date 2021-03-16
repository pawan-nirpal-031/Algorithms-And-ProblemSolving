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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void Question1(){

}

void Question2(){

}

void Question3(){

}



void Question4(){
    int n,k;
    cin>>n>>k;
    if(k<=(n>>1)){
        cout<<-1<<' ';
        for(int i = 2;i<=n;i++){
            if((i==2) || (k>=1 && (i&1))){
                cout<<i<<' ';k--;
            }else{
                cout<<-i<<' ';
            }
        }
    }else{
        int kc = n-k;
        if(kc>=1){
            cout<<-1<<' ';kc--;
        }else{
            cout<<1<<' ';
        }
        for(int i = 2;i<=n;i++){
            if(kc>=1 && ((!(i&1)  && (i>2) ))){
                cout<<-i<<' ';kc--;
            }else{
                cout<<i<<' ';
            }
        }
    }
    cout<<'\n';
}


void Question5(){
    int n,k;
    cin>>n>>k;
}

int main(){
  FastIO;
//   int tc;
//   cin>>tc;
//   while(tc--){
//     Question4();
//   }
 Question5();
  return 0;
} 
