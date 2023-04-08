#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

#define FASTIO              ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
#define ll                  long long int
#define endl                "\n"
#define pb                  push_back
#define yes                 cout << "YES" << endl
#define no                  cout << "NO" << endl

/* Ordered Set/Multiset and Map. Used for finding k-th element in set. */
template <class T, class U>
using ordered_set = tree<T, null_type, U, rb_tree_tag, tree_order_statistics_node_update>;
 
// Pass 'U' as less<T> for ascending set, less_equal<T> for ascending multiset.
// Pass 'U' as greater<T> for descending set, greater_equal<T> for descending multiset.
// find_by_order(k) returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
 
template <class key, class value, class cmp>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define minus               cout<< "-1" <<endl
#define vl                  vector<ll>
#define vvl                 vector<vl>
#define pr                  pair<ll, ll>
#define vpr                 vector<pr>
#define all(x)              x.begin(),x.end()
#define search(x,a)         x.begin(),x.end(),a
#define mpll                map<ll,ll>
#define mpcl                map<char,ll>
#define usll                unordered_map<ll,ll>
#define uscl                unordered_map<char,ll>
#define gcd                 __gcd
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define maxe                *max_element
#define mine                *min_element
#define f                   first
#define s                   second
#define lb                  lower_bound
#define ub                  upper_bound
#define ins                 insert
#define mk                  make_pair
#define deci(x, y)          fixed<<setprecision(y)<<x
#define PI                  3.141592653589793238
#define mem0(x)             memset(x,0,sizeof x)
#define mem1(x)             memset(x,-1,sizeof x)
#define read(v,st,en)       for(ll k=st;k<en;k++)cin>>v[k];
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll inf = 1e18;

void solve(ll test){
    // cout<<"Case #"<<test<<": ";
    ll i=0;
    ll n;
    
}

int main(){
    FASTIO;
    ll t=1;
    std::cin >> t;
    for(ll i=1;i<=t;i++){
        solve(i);
    }
}
