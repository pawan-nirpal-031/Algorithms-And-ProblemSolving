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


class Math{
    public:
    int Floor(int x,int y){
        return floor(x*1.0/y);
    }
    int Ceil(int x,int y){
        return ceil(x*1.0/y);
    }
};


class Utilty{
    public:
    
    vector<vector<int>> Get2dMatrix(int n,int m){        
        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i =0;i<n;i++) for(int j =0;j<m;j++) cin>>a[i][j];
        return a;
    }
};

void ReversePairs(){
    
}


int MergeAndCount(int a[],int l,int m,int r){
    int i = l;
    int j = m+1;
    int k = 0;
    int n = r-l+1;
    int buff[n];
    int locinv =0;
    while(i<=m and j<=r){
        if(a[i]>a[j]){
            locinv+=(m-i+1);
            buff[k++] = a[j++];
        }else{
            buff[k++] = a[i++];
        }
    }
    while(i<=m) buff[k++] = a[i++];
    while(j<=r) buff[k++] = a[j++];
    for(int i =0;i<n;i++) a[i+l] = buff[i];
    return locinv;
}

int invc =0;

void InversioncountUtil(int a[],int l,int r){
    if(l<r){
        int m = (l+r)/2;
        InversioncountUtil(a,l,m);
        InversioncountUtil(a,m+1,r);
        invc+=MergeAndCount(a,l,m,r);
    }
}

void Inversioncount(){
    int n;
    cin>>n;
    int a[n];
    for(int &x : a) cin>>x;
    InversioncountUtil(a,0,n-1);
    cout<<invc;
}

void SetMatrixToZeros(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    vector<bool>row(n,0),col(m,0);
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]==0) row[i] = col[j] = 1;
        }
    }
    for(int r =0;r<n;r++) if(row[r]) for(int j = 0;j<m;j++) a[r][j]=0;
    for(int c = 0;c<m;c++) if(col[c]) for(int i = 0;i<n;i++) a[i][c] =0;
    for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<a[i][j]<<' '; cout<<'\n';}
}

void BuyAndSellSingleDay(){
    int n;
    cin>>n;
    int stocks[n];
    for(int &x : stocks) cin>>x;
    int max_profit = -INT_MAX;
    int min_prefix = stocks[0];
    for(int i = 1;i<n;i++){
        int curr_profit = stocks[i] - min_prefix;
        max_profit = max(max_profit,curr_profit);
        min_prefix = min(min_prefix,stocks[i]);
    }
    cout<<max(0,max_profit);
}

void PascalsTringle(){
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n,0));
    
}

int majorityElement(vector<int>& nums) { // optimize using moore's voting algo
    map<int,int>h;
    int l = nums.size();
    for(int n : nums){
        h[n]++;
        if(h[n]>floor(1.0*l/2)) return n;
    }
    return 0;
}

void majorityElementByMooreSAlgorithm(vector<int>a){
    int n = a.size();
    int count =0;
    int majority = 0;
    for(int i=0;i<n;i++){
        if(count==0){
            majority = a[i];
        } 
        if(a[i]==majority) count++;
        else count--;
    }
    cout<<majority;
}

void MajorityElment2(vector<int>&nums){
    multimap<int,int>data;
    int n = nums.size();
    vector<int>ans;
    for(int x : nums){
        auto it = data.find(x);
        if(it==data.end()) data.insert({x,1});
        else{
            it->second++;
            if((it->second)>floor((n*1.0)/3)) ans.push_back(x);
        }
    }
    for(int x : ans ) cout<<x<<' ';
}

void SortOnesZeorsTwos(){
    int n;
    cin>>n;
    vector<int>a(n,0);
    for(int &x : a) cin>>x;
    int count[3] = {0,0,0};
    for(int n : a) count[n]++;
    for(int i =0;i<3;i++) while(count[i]--) cout<<i<<' ';
}

bool BoundryCheck(int n,int m,int i,int j){
    return (i>=0 and i<n and j>=0 and j<m);
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void NumberOfIslandsUtil(vector<vector<char>>&g,int n,int m,int p,int q){
   g[p][q] = '0';
   for(int i =0;i<4;i++){
       int x = p+dx[i];
       int y = q+dy[i];
       if(BoundryCheck(n,m,x,y) and g[x][y]=='1') NumberOfIslandsUtil(g,n,m,x,y);
   }
}

int NumberOfIslands(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>g(n,vector<char>(m,'0'));
    for(int i=0;i<n;i++) for(int j =0;j<m;j++) cin>>g[i][j];
    int k=0;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='1'){
                NumberOfIslandsUtil(g,n,m,i,j);
                k++;
            }
        }
    }
    return k;
}

void SurroundingReigons(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>a(n,vector<char>(m,'0'));
    for(int i =0;i<n;i++) for(int j =0;j<m;j++) cin>>a[i][j];
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            if(a[i][j]=='0' and (i>0 and i<n-1 and j>0 and j<m-1) and (1  )){
                //
            }
        }
    }
}

int MaxIarea =0;

void MaxAreaOfIslandUtil(vector<vector<int>>&a,int n,int m,int i,int j){
    MaxIarea+=1;
    a[i][j] = 0;
    for(int d =0;d<4;d++){
        int x = i+dx[d];
        int y = j+dy[d];
        if(BoundryCheck(n,m,x,y) and a[x][y]) MaxAreaOfIslandUtil(a,n,m,x,y);
    }
}

int MaxAreaOfIsland(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
           cin>>a[i][j];
        }
    }
    int ans =0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(a[i][j]){
                MaxIarea = 0;
                MaxAreaOfIslandUtil(a,n,m,i,j);
                ans = max(ans,MaxIarea);
            }
        }
    }
    return ans;
}

int findDuplicate(vector<int>& nums) { // uses slow-fast pointer and floyd's cycle detetcion 
/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

*/
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow!=fast);
    fast = nums[0];
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

void SortAnArraysOfZerosOnesAndTwos(vector<int>&nums){// Dutch National flag algo
    int low =0, mid = 0, high = nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low++],nums[mid++]);
        }else if(nums[mid]==1) mid++;
        else{
            swap(nums[mid],nums[high--]);
        }
    }
}


void MaximumSubarraysum(){
    int n;
    cin>>n;
    vector<int>a(n,0);
    for(int &x : a) cin>>x;
    int sum =0;
    int mx = a[0];
    for(int i =0;i<n;i++){
        sum = max(a[i], sum+a[i]);
        mx = max(mx,sum);
    }
    cout<<mx<<'\n';    
}

int gloabal_inv =0;

int GetInversionsUtil(vector<int>&a,int l,int r,int m){
    int i = l;
    int n = r-l+1;
    int j = m+1;
    int k = 0;
    int buff[n];
    int local_inv =0;
    while(i<=m and j<=r){
        if(a[i]<=a[j]) buff[k++] = a[i++];
        else{
            local_inv+=(m-i+1);
            buff[k++] = a[j++];
        }
    }
    while(i<=m) buff[k++] = a[i++];
    while(j<=r) buff[k++] = a[j++];
    for(int i=0;i<n;i++) a[l+i] = buff[i];
    return local_inv;
}


void GetInversions(vector<int>&nums,int l,int r){
    if(l<r){
        int m = (l+r)/2;
        GetInversions(nums,l,m);
        GetInversions(nums,m+1,r);
        gloabal_inv+=GetInversionsUtil(nums,l,r,m);
    }
}

void isIdealPermutation(vector<int>& nums) {
    int n = nums.size();
    int local_inv =0;
    for(int i =0;i<n-1;i++) local_inv+=(nums[i]>nums[i+1]);
    GetInversions(nums,0,n-1);
    cout<<local_inv<<" "<<gloabal_inv;
}

bool searchMatrixLastElmentRelation(vector<vector<int>>& matrix, int target) {
    /*
        Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

        Integers in each row are sorted in ascending from left to right.
        Integers in each column are sorted in ascending from top to bottom.
    */
    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0;
    int h = m*n-1;
    while(l<=h){
        int mid = (l+h)/2;
        int v = matrix[mid/m][mid%m];
        if(v==target) return 1;
        else if(v<target) l = mid+1;
        else h = mid-1;
    }
    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int x = 0;
    int y = m-1;
    while(x>=0 and x<n and y>=0 and y<m){
        if(matrix[x][y]==target) return 1;
        else if(target<matrix[x][y]) y--;
        else x++;
    }
    return 0;
}


// vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
// }




void setZeroes(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    bool row_zero = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(a[i][j]==0){
                a[0][j] =0;
                if(i==0) row_zero =1;
                else a[i][0] = 0;
            }
        }
    }
    for(int i =1;i<n;i++){
        for(int j =1;j<m;j++){
            if(a[i][0]==0 or a[0][j]==0) a[i][j] =0;
        }
    }
    if(a[0][0]==0) for(int i =0;i<n;i++) a[i][0] = 0;
    if(row_zero) for(int j=0;j<m;j++) a[0][j] = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++) cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}



double Power(double x, int n) {
    double ans = 1.0;
    long long e = abs(n);
    while(e){
        if(e&1){
            ans*=x;
            e-=1;
        }else{
            x = (x*x);
            e = (e>>1);
        }
    }
    if(n<0) return ((1.0)/(ans));
    return ans;
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i =0;i<n;i++) for(int j = 0;j<i;j++) swap(matrix[i][j],matrix[j][i]);
    for(int i =0;i<n;i++) for(int j = 0;j<m;j++) reverse(matrix[i].begin(),matrix[i].end());
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>ans;
    if(intervals.size()==0) return ans;
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    int low = intervals[0][0];
    int high = intervals[0][1];
    for(int i =1;i<n;i++){
        if(intervals[i][0]<=high){
            high = max(high,intervals[i][1]);
        }else{
            ans.push_back({low,high});
            low = intervals[i][0];
            high = intervals[i][1];
        }
    }
    ans.push_back({low,high});
    return ans;
}

/*
Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.
*/
int maximumDifference(vector<int>& nums) {
    int max_diff = -INT_MAX;
    int prefix_min = nums[0];
    for(int i =1;i<nums.size();i++){
        max_diff = max(max_diff,nums[i]-prefix_min);
        prefix_min = min(prefix_min,nums[i]);
    }
    return (max_diff<0?-1:max_diff);
}


/*

There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

Return the maximum distance between two houses with different colors.

The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

*/
int maxDistance(vector<int>& colors) {
    vector<int>houses(102,0);
    int mn = 1000;
    int mx = 0;
    for(int i=0;i<colors.size();i++){
       houses[colors[i]] = 1;
       
    }
    return mx-mn;
}



void combinationSumUtil(vector<int>& candidates,vector<vector<int>>&cache,vector<int>&local,int target,int i){
    if(i==candidates.size()-1){
        if(target==0) cache.push_back(local);
        return;
    }
    if(candidates[i]<=target){
        local.push_back(candidates[i]);
        combinationSumUtil(candidates,cache,local,target-candidates[i],i);
        local.pop_back();
    }
    combinationSumUtil(candidates,cache,local,target,i+1);
}

vector<vector<int>> combinationSum(vector<int>&candidates, int target) {
    vector<vector<int>>cache;
    vector<int>local;
    combinationSumUtil(candidates,cache,local,target,0);
    return cache;
}



void combinationSum2Util(vector<int>&candidates, int target,vector<vector<int>>&cache,vector<int>&local,int i){
   if(target==0){
       cache.push_back(local);
       return;
   }
   for(int x =i;x<candidates.size();x++){
       if(x>i and candidates[x]==candidates[x-1]) continue;
       if(candidates[x]>target) break;
       local.push_back(candidates[x]);
       combinationSum2Util(candidates,target-candidates[x],cache,local,x+1);
       local.pop_back();
   }
}

vector<vector<int>> combinationSum2(vector<int>&candidates, int target) {
    vector<vector<int>>cache;
    vector<int>local;
    sort(candidates.begin(),candidates.end());
    combinationSum2Util(candidates,target,cache,local,0);
    return cache;
}

void subsetSumsUtil(vector<int>a,int n,int i,vector<int>&res,int curr_sum){
    if(i>=n){
        res.push_back(curr_sum);
        return;
    }
    curr_sum+=a[i];
    subsetSumsUtil(a,n,i+1,res,curr_sum);
    curr_sum-=a[i];
    subsetSumsUtil(a,n,i+1,res,curr_sum);
}

vector<int> subsetSums(vector<int> arr, int N){
    vector<int>res;
    subsetSumsUtil(arr,arr.size(),0,res,0);
    return res;
}

void subsetsWithDupUtil(vector<int>& nums,int indx,vector<vector<int>>&ans,vector<int>&local){
    ans.push_back(local);
    for(int i =indx;i<nums.size();i++){
        if(i>indx and nums[i]==nums[i-1]) continue;
        local.push_back(nums[i]);
        subsetsWithDupUtil(nums,i+1,ans,local);
        local.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>local;
    sort(nums.begin(),nums.end());
    subsetsWithDupUtil(nums,0,ans,local);
    return ans;
}

void PrintAllPermutationsUtil(vector<int>&a,vector<vector<int>>&ans,int indx){
    if(indx==a.size()){
        ans.push_back(a);
        return;
    }
    for(int i =indx;i<a.size();i++){
        swap(a[indx],a[i]);
        PrintAllPermutationsUtil(a,ans,indx+1);
        swap(a[indx],a[i]);
    }
}

vector<vector<int>> permute(vector<int>& a) {
    vector<vector<int>>ans;
    PrintAllPermutationsUtil(a,ans,0);
    return ans;
}

bool IsValid(vector<pair<int,int>>&local,int r,int c){
    for(auto p : local) if(p.second==c or (abs(p.first-r)==abs(p.second-c))) return 0;
    return 1;
}

void solveNQueensUtil(int n,int row,vector<vector<string>>&board,vector<pair<int,int>>&local){
    if(row==n){
        vector<string>soln(n,string(n,'.'));
        for(auto c : local) soln[c.first][c.second] = 'Q';
        board.push_back(soln);
        return;
    }
    for(int col =0;col<n;col++){
        if(IsValid(local,row,col)){
            local.push_back({row,col});
            solveNQueensUtil(n,row+1,board,local);
            local.pop_back();
        }
    }
}   

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>>board;
    vector<pair<int,int>>local;
    solveNQueensUtil(n,0,board,local);
    return board;
}

bool IsPossible(vector<vector<char>>&board,char d,int r,int c){
    for(int i =0;i<9;i++) if(board[r][i]==d) return 0;
    for(int i =0;i<9;i++) if(board[i][c]==d) return 0;
    int bx = (r/3)*3;
    int by = (c/3)*3;
    for(int i =0;i<3;i++){
        for(int j = 0;j<3;j++){
            int x = i+bx;
            int y = j+by;
            if(board[x][y]==d) return 0;
        }
    }
    return 1;
}



bool solveSudokuUtil(vector<vector<char>>& board){
    int fininshed =0;
    for(int i =0;i<9;i++){
        for(int j =0;j<9;j++){
            if(board[i][j]=='.'){
                fininshed++;
                for(int d = 1;d<=9;d++){
                    if(IsPossible(board,'0'+d,i,j)){
                        board[i][j] = '0'+d;
                        if(solveSudokuUtil(board)) return 1;
                        else board[i][j] = '.';
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

void solveSudoku(vector<vector<char>>& board){
 solveSudokuUtil(board);
}



bool ValidParenthesis(string s){
    stack<char>stk;
    for(char c : s){
        if(c=='(' or c=='{' or c=='[') stk.push(c);
        else{
            if((not stk.empty()) and ((c==')' and stk.top()=='(') or (c=='}' and stk.top()=='{') or (c==']' and stk.top()=='['))) stk.pop();
            else return 0;
        }
    }
    return stk.empty();
}

bool ALetter(char c){
  return (( c>='a' and c <='z') or (c>='A' and c<='Z'));
}

string simplifyPath(string path) {
    stack<string>sys;
    int n = path.length();
    sys.push("/");
    for(int i =0;i<n;i++){
        if(i+1<n){
            if(path[i]=='.' and path[i+1]=='.' and (i+2<n and path[i+2]!='.') and (not sys.empty())) sys.pop();
            if(path[i]=='/' and (sys.top()!="/") and path[i+1]!='/') sys.push("/");
            if(not ALetter(path[i++])) continue;
            string dir;
            while(ALetter(path[i]) and i<n){
                dir+=path[i++];
            }
            sys.push(dir);
        }else if(path[i]!='/'){
            string v(1,path[i]);
            sys.push(v);
        }
    }
    string ans;
    while (not sys.empty()){
        ans+=sys.top();
        sys.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}



bool CanColour(vector<int>g[],vector<int>&colour,int node,int col){
    for(int v : g[node]) if(colour[v]==col) return 0;
    return 1;
}

bool KColouringUtil(vector<int>g[],vector<int>&colour,int node,int k){
    if(node==colour.size()) return 1;
    for(int c = 1;c<=k;c++){
        if(CanColour(g,colour,node,c)){
            colour[node] = c;
            if(KColouringUtil(g,colour,node+1,k)){
                return 1;
            }
            colour[node] = 0;
        }
    }
    return 0;
}

void KColouring(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>g[n];
    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int>colour(n,0);
    vector<bool>vis(n,0);
    Status(KColouringUtil(g,colour,0,k));
}

struct node{
    int time;
    int x,y;
};


int orangesRotting(vector<vector<int>>& grid) {
    queue<node>basket;
    int n = grid.size();
    int m = grid[0].size();
    int fresh =0;
    int rotten =0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j]==2){
                node n;
                rotten+=1;
                n.time =0;
                n.x = i;
                n.y = j;
                basket.push(n);
            }else if(grid[i][j]==1) fresh+=1;
        }
    }
    if(fresh==0) return 0;
    if(fresh and rotten==0) return -1;
    int time_taken = -1;
    while(not basket.empty()){
        node curr = basket.front();
        basket.pop();
        time_taken = max(time_taken,curr.time);
        for(int i =0;i<4;i++){
            int tx = curr.x+dx[i];
            int ty = curr.y+dy[i];
            if(tx>=0 and tx<n and ty>=0 and ty<m){
                if(grid[tx][ty]==1){
                    node nxt;
                    grid[tx][ty] = 2;
                    nxt.time = curr.time+1;
                    nxt.x = tx;
                    nxt.y = ty;
                    basket.push(nxt);
                }
            }
        }
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j]==1) return -1;
        }
    }
    return time_taken;       
}

int firstUniqChar(string s) {
    vector<pair<int,int>>freq(26,{0,-1});
    for(int i=0;i<s.length();i++){
        if(freq[s[i]-'a'].second==-1) freq[s[i]-'a'].second = i;
        freq[s[i]-'a'].first++;
    }
    int ans = INT_MAX;
    for(int i =0;i<26;i++){
        if(freq[i].second==-1 or freq[i].first>1) continue;
        ans = min(ans,freq[i].second);
    }
    return (ans!=INT_MAX?ans:-1);
}

string FirstNonRepeating(string A){
    vector<int>freq(26,0);
    queue<char>que;
    string ans;
    for(char c : A){
        freq[c-'a']+=1;
        que.push(c);
        while(not que.empty() and freq[que.front()-'a']>1) que.pop();
        if(que.empty()) ans+='#';
        else ans+=que.front();
    }
    return ans;
}

void MaximumOFAllSubarraysOfSizek(vector<int>&arr,int k){
    int n = arr.size();
    deque<int>list;
    for(int i =0;i<n;i++){
        if(not list.empty() and list.front()==i-k) list.pop_front(); // remove out of bounds of window if any
        while(not list.empty() and (arr[list.back()]<arr[i])) list.pop_back(); // maintain decreasing order
        list.push_back(i); // insert current element of window
        if(i>=k-1) cout<<arr[list.front()]<<" ";// print maximum of subarray;
    }
}

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  vector<int>a(n,0);
  for(int i =0;i<n;i++) cin>>a[i];
  MaximumOFAllSubarraysOfSizek(a,k);
  return 0;
} 


