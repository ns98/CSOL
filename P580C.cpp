#include<bits/stdc++.h>
using namespace std;
#define mod                   1000000007
#define ll                    long long
#define Author                std::ios_base::sync_with_stdio(0);
#define NIKHIL_SETHI          cout.tie(0);
#define MNNIT_ALLAHABAD       cin.tie(0);
#define umii                  unordered_map<ll,ll>
#define mii                   map<ll,ll>
#define pii                   pair<ll,ll>
#define all(v)                v.begin(),v.end()
#define forP(i,j,k)           for(i=j; i<k; i++)
#define forN(i,j,k)           for(i=j; i>k; i--)
#define pb(a)                 push_back(a)
#define lb(v,t)               lower_bound(all(v),t)-v.begin()
#define ub(v,t)               upper_bound(all(v),t)-v.begin()
#define inf 1e18
 
//mainly used functions
bool prime[10000001];
ll abst(ll a){if(a<0)return -a; return a;}
ll power(ll a, ll b){ll res=1;while(b){if(b&1)res=res*a;a=a*a;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
ll lcm(ll a, ll b){return a*b/__gcd(a,b);}
ll ncr(ll n, ll r){ll p=1;ll i;for(i=1; i<=r; i++){p*=(n-i+1);p*=i;}return p;}
void sieve(){ll i;ll j;memset(prime,true,10000000);prime[0]=prime[1]=false;for(i=2; i*i<=10000000; i++){if(prime[i]){for(j=2*i; j<=10000000; j+=i){prime[j]=false;}}}}

vector <ll> adj[100004];
ll vis[100004];
ll a[100004];
ll var;

void dfs(ll i,ll c,ll m,ll mx)
{   
    vis[i] = 1;
    mx = max(mx,c);
    //cout<<i<<" "<<c<<" "<<mx<<"\n";
    if(adj[i].size()==1&&i!=1)
    {
        if(mx<=m)
        {
            var++;
        }
        //cout<<i<<" "<<var<<" "<<a[i]<<"\n";
        return;
    }
        ll j;
        for(j=0;j<adj[i].size();j++)
        {
            if(!vis[adj[i][j]])
            {
                if(a[adj[i][j]]==1)
                {
                    dfs(adj[i][j],c+1,m,mx);
                }
                else
                {
                    dfs(adj[i][j],0,m,mx);
                }
                
            }
        }
}


int main()
{   
    var = 0;
    ll n,m;
    cin>>n>>m;
    ll i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[y].pb(x);
        adj[x].pb(y);
    }
    if(a[1]==1)
    {
        dfs(1,1,m,-1);
    }
    else
    {
        dfs(1,0,m,-1);
    }
    cout<<var<<"\n";
}