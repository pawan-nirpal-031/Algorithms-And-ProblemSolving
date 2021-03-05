
// string LCSUtil(vector<vector<string>>&Cache,string &lcs,string s[],string t[],int si,int ti){
//   if(si>=s.length() or ti>=t.length()) return "";
//   if(Cache[si][ti]!="NULL") return Cache[si][ti];
//   if(s[si]==t[ti]) return Cache[si][ti] = (lcs+s[si]+LCSUtil(Cache,lcs,s,t,si+1,ti+1));
//   string first = LCSUtil(Cache,lcs,s,t,si+1,ti);
//   string second = LCSUtil(Cache,lcs,s,t,si,ti+1);
//   return Cache[si][ti] =  ((first.length()>second.length())?first:second);
// }

// void LCS(){
//   int n,m;
//   cin>>n>>m;
//   string s[n];
//   string t[m];
//   vector<vector<string>>Cache(n,vector<string>(m,"NULL"));
//   string lcs = "";
//   cout<<LCSUtil(Cache,lcs,s,t,0,0)<<'\n';
// }
