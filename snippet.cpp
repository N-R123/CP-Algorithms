#include <bits/stdc++.h>
using namespace std;


#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
// typedefs
typedef  long long                            ll;
typedef  unsigned long long                   ull;
typedef  long double                          lld;
typedef  pair<ll,ll>                          pll;
typedef  vector<ll>                           vll;
typedef  vector<char>                         vc;
typedef  vector<string>                       vs;
typedef  vector<pll>                          vp;
typedef  unordered_map<ll,ll>                 mll;
typedef  unordered_map<char,ll>               mc;
typedef  unordered_map<string,ll>             ms;
typedef  unordered_map<pll,ll>                mp;
typedef  priority_queue<ll>                   pql_mx;
typedef  priority_queue<ll,vll,greater<ll>>   pql_mn;
typedef  priority_queue<pll>                  pqp_mx;
typedef  priority_queue<pll,vp,greater<pll>>  pqp_mn;
// pair / vector / string
#define  ff             first
#define  ss             second
#define  pb             push_back
#define  mp             make_pair
#define  NO             {cout<<"NO"<<endl; return;}
#define  YES 			{cout<<"YES"<<endl; return;}
#define  NEG 		    {cout<<"-1"<<endl; return;}
#define  r(X)           return X;                                                    // return
#define  fwd(a)         a.begin(),a.end()                                            // forward
#define  bwd(a)         a.rbegin(),a.rend()                                          // backward
#define  precise(x,n)   fixed<<setprecision(n)<<x                                    // n digits after decimal
#define  fl(i,m,n)      for(int i=m; i<=n; i++)                                      // forward loop
#define  rl(i,m,n)      for(int i=m; i>=n; i--)                                      // reverse loop
#define  trav(it,s)     for(auto it=s.begin(); it!=s.end(); it++)                    // traversing using iterator
#define  prt(X)         {cout<<X<<endl;}                                             // print/debug
#define  prtvtr(X)      {for(ll i=0;i<X.size();i++) cout<<X[i]<<" "; cout<<endl;}    // print/debug
#define  srt(v)         sort(v.begin(),v.end());                                     // sort
#define  rev(v)         reverse(v.begin(),v.end());                                  // reverse
#define  set(X,t)       memset(X, t, sizeof(X));                                     // t = -1/0/inf/false/true
#define  getunique(v)   {sort(fwd(v)); v.erase(unique(fwd(v)), v.end());}            // erasing duplicates
// vector
ll sm(vector<ll> v){ll sm=0; fl(i,0,v.size()-1)sm+=v[i]; return sm;}                          // sum
ll mxI(vector<ll> v){ll t=0; fl(i,0,v.size()-1){ if(v[i]>v[t]) t=i;} return t;}               // maxValueIndex
ll mnI(vector<ll> v){ll t=0; fl(i,0,v.size()-1){ if(v[i]<v[t]) t=i;} return t;}               // minValueIndex
ll lbI(vector<ll> v,ll k){ll t = lower_bound(v.begin(),v.end(),k) - v.begin(); return t;}     // lowerBoundIndex
ll ubI(vector<ll> v,ll k){ll t = upper_bound(v.begin(),v.end(),k) - v.begin(); return t;}     // upperBoundIndex
// constants
const lld pi= 3.1415926535897932384626;
const ll inf = LONG_LONG_MAX;
const ll mod = 1e9+7;
const double epsilon = 1e-7;
// check
bool cmp_a(pair<ll,ll> &a, pair<ll,ll> &b){return (a.first < b.first);}
bool isPrime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(int i=5;i*i<=n;i+=6)if(n%i==0||n%(i+2)==0)return 0; return 1;}
bool isPowerOfTwo(ll n){ if(n==0)return 0; return(ceil(log2(n))==floor(log2(n)));}
bool isPerfectSquare(ll x){ if(x>=0){ll sr=sqrt(x); return(sr*sr==x);} return 0;}
// convert
string DecimalToBinary(ll n){string s="";ll i=0; while(n>0) {s=to_string(n%2)+s; n=n/2; i++;} return s;}
ll BinaryToDecimal(string n){string num=n; ll z=0; int b=1; int len=num.length();for(int i=len-1;i>=0;i--){if(num[i]=='1')z+=b; b*=2;}return z;}
// numbers
ll gcd(ll a, ll b){if(b==0)return a; return gcd(b,a%b);}
ll lcm(ll a, ll b){return ((a/gcd(a,b))*b);}
ll modularProduct(ll a,ll b,ll m){ll res=0; a%=m; while(b){ if(b&1) res=(res+a)%m; b>>=1;} return res;}
ll modularPower1(ll x, ll y, ll m){ll res=1; x = x%m;  res=res%m; while(y--){  res=(res*x)%m; } return res;}
ll modularPower2(ll x, ll y, ll m){ll res=1; x=x%m; if(x==0) return 0;while(y>0){if(y&1) res=(res*x)%m; y=y>>1; x=(x*x)%m;} return res;}// graph
// graph
vll* storegraph(ll n,ll m){ll i,u,v; vll *g=new vll[n];  while(m--){cin>>u>>v;  u--,v--;  g[u].pb(v); g[v].pb(u);}  return g;}
void dfs(ll u,ll par,vll*g){  for(ll v:g[u]){ if(v==par)continue; dfs(v,u,g);}}
/* dp
vector<ll> dp(n+1,-1);
vector<vector<ll>> dp(m+1,vector<ll>(n+1,-1));
*/
 















