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
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

vector<string> Tokenize(string line){
    vector<string>token;
    stringstream stream(line);
    string word;
    while(getline(stream,word,' ')){
        token.push_back(word);
    }
    return token;
}

ifstream input_buffr;
ofstream ouput_buffr;

void OpenFiles(string inp,string outp){
    input_buffr.open(inp, ios::in);
    ouput_buffr.open(outp,ios::out);
}

void CloseFiles(){
  input_buffr.close();
  ouput_buffr.close();
}

int StringToInteger(string s){
    stringstream stream(s);
    int num =0;
    stream>>num;
    return num;
}

char StringToChar(string s){
  char ch;

  return ch;
}






int main(){
  FastIO;
  OpenFiles("input2.txt","output2.txt");
  string line;
  int i =0;
  while(getline(input_buffr,line)){
    vector<string> token = Tokenize(line);
    int m,t1,t2,t3,x;
    if(i==0){
       m = StringToInteger(token[0]);
       t1 = StringToInteger(token[1]);
       t2 = StringToInteger(token[2]);
       t3 = StringToInteger(token[3]);
    }else{
        x = StringToInteger(token[0]);

    }
    i+=1;
  }
  CloseFiles();
  return 0;
} 