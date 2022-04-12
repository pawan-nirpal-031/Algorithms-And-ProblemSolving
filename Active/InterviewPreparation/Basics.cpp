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



void GenerateAllSubsets(string s,int i,int n,string temp){
    if(i<n){
        temp+=s[i];
        GenerateAllSubsets(s,i+1,n,temp);
        temp.pop_back();
        GenerateAllSubsets(s,i+1,n,temp);
    }else cout<<temp<<'\n';
}

void PowerSet(string s,int n){
    for(int i =0;i<(1<<n);i++){
        for(int j =0;j<n;j++){
            if((i&(1<<j))) cout<<s[j];
        }
        cout<<'\n';
    }
}

int power(int a,int x){
   int res = 1;
   while(x){
       if(x&1) res = res*a;
       a = a*a;
       x>>=1;
   }
   return res;
}

int ValidateIp(string s){
    int idx =0;
    int n = s.length();
    int buff[3];
    int oct_cnt =0;
    for(int i =0;i<n;i++){
        if(s[i]=='.'){
            int oct =0;
            for(int j =0;j<idx;j++) oct+=(buff[j]*power(10,idx-1-j));
            if(oct>255) return 0;
            idx =0;
            oct_cnt+=1;
            continue;
        }
        buff[idx++] = s[i]-'0';
    }
    int oct=0;
    for(int j =0;j<idx;j++) oct+=(buff[j]*power(10,idx-1-j));
    return (oct_cnt==3 and oct<=255);
}

void PrintReverseWords(string str){
    vector<int>spaces;
    for(int i =0;i<str.length();i++) if(str[i]==' ') spaces.push_back(i);
    int n = spaces.size();
    for(int spidx = n-1;spidx>=0;spidx--){
        for(int j = spaces[spidx]+1;j<(spidx==n-1?str.length():spaces[spidx+1]);j++) cout<<str[j];
        cout<<"\n";
    }
    int i =0;
    while(str[i]!=' ' and i<str.size()) cout<<str[i++];
}

bool IsAllSame(string a[],int i,int n){
    bool yes = 1;
    char tmp =  a[0][i];
    for(int j=0;j<n;j++) if(a[j][i]!=tmp) return 0;
    return 1;
}


string LongestCommonPrefix(string a[],int n){
    vector<int>indx(n,-1);
    int mx_poss = INT_MAX;
    for(int i =0;i<n;i++) if(a[i].size()<mx_poss) mx_poss = a[i].size();
    int idx = -1;
    for(int i =0;i<mx_poss;i++){
        if(IsAllSame(a,i,n)){
            idx = i;
            continue;
        }else break;
    }
    string ans;
    for(int i =0;i<=idx;i++) ans+=a[0][i];
    return (ans.length()?ans:"-1");
}


int MissingElement(vector<int>&array,int n){
    int x =0;
    for(int i =1;i<=n;i++) x = x xor i;
    for(int i =0;i<n-1;i++) x = x xor array[i];
    return x;
}

int main(){
  FastIO;
  
  return 0;
} 
