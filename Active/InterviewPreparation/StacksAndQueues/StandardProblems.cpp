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

pair<char,int>pre[4] = {{'-',0},{'+',0},{'*','1'},{'/',1}};

int GetPrecedence(char c){
    for(int i=0;i<4;i++) if(pre[i].first==c) return pre[i].second;
    return 0;
}


void InfixToPostfix(string expr){
    string ans;
    stack<char>opreator;
    for(char c : expr){
        if((c>='A' and c<='Z') or (c>='a' and c<='z')){
            cout<<c;
        }else{
            if(opreator.size()>0){
                if(c=='('){
                    opreator.push(c);
                }else if(c==')'){
                    while(opreator.size()>0 and opreator.top()!='('){
                        //ans+=opreator.top();
                        cout<<opreator.top();
                        opreator.pop();
                    }
                    opreator.pop();
                }
                else if((c=='/' or c=='*')){
                    if(opreator.top()=='(' or opreator.top()=='+' or opreator.top()=='-') opreator.push(c);
                    else{
                        int curr = GetPrecedence(c);
                        while(opreator.size()>0 and (opreator.top()!='(' or GetPrecedence(opreator.top())>=curr )){
                            ///ans+=opreator.top();
                            cout<<opreator.top();
                            opreator.pop();
                        }
                        opreator.push(c);
                    }
                }else{
                    int curr = GetPrecedence(c);
                    while(opreator.size()>0 and (opreator.top()!='(' or GetPrecedence(opreator.top())>=curr )){
                        //ans+=opreator.top();
                        cout<<opreator.top();
                        opreator.pop();
                    }
                    opreator.push(c);
                }
            }else opreator.push(c);
        }
    }
    while(not opreator.empty()){
        //ans+=opreator.top();
        cout<<opreator.top();
        opreator.pop();
    }
}

int main(){
  FastIO;
  string expr;
  cin>>expr;
  InfixToPostfix(expr);
  return 0;
} 
