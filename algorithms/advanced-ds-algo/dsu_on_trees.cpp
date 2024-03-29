// https://codeforces.com/contest/600/problem/E
/*
You are given a rooted tree with root in vertex 1. Each vertex is coloured in some colour.

Let's call colour c dominating in the subtree of vertex v if there are no other colours that appear in the subtree of vertex v more times than colour c. So it's possible that two or more colours will be dominating in the subtree of some vertex.

The subtree of vertex v is the vertex v and all other vertices that contains vertex v in each path to the root.

For each vertex v find the sum of all dominating colours in the subtree of vertex v.

Input
The first line contains integer n (1≤n≤105) — the number of vertices in the tree.

The second line contains n integers ci (1≤ci≤n), ci — the colour of the i-th vertex.

Each of the next n-1 lines contains two integers xj,yj (1≤xj,yj≤n) — the edge of the tree. The first vertex is the root of the tree.

Output
Print n integers — the sums of dominating colours for each vertex.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
// when you got tle but tc is right do this and make as global as possible
//#define endl "\n"
const ll MAX =1000000000000000000;
ll mod= 1000000000;
long double pi=3.141592653589793238;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
}
/*   DON'T STUCK ON SINGLE APPROACH AND ALWAYS STUCK ON QUESTION :)*/
const ll N=1e5+2;
/*
people say its n(logn)^2  , if use map or nlogn if use vector
they say correct
*/
ll col[N];
vector<ll> g[N];
map<ll,ll> dsu_on_tree[N];
vector<ll> ans(N),mxval(N);
void dfs(ll ix,ll p=-1)
{
     dsu_on_tree[ix][col[ix]]++;
     mxval[ix]=dsu_on_tree[ix][col[ix]];
     ans[ix]=col[ix];
     for(auto x: g[ix])
     {
           if(x==p)continue;
           dfs(x,ix);
           // first small
           if(dsu_on_tree[x].size()>dsu_on_tree[ix].size())
           {
               swap(dsu_on_tree[x],dsu_on_tree[ix]);
               mxval[ix]=mxval[x];
               ans[ix]=ans[x];
           }

           for(auto y: dsu_on_tree[x])
           {
                dsu_on_tree[ix][y.first]+=y.second;
                if(dsu_on_tree[ix][y.first]>mxval[ix])
                {
                     mxval[ix]=dsu_on_tree[ix][y.first];
                     ans[ix]=y.first;
                }
                else if(dsu_on_tree[ix][y.first]==mxval[ix])
                {
                     ans[ix]+=y.first;
                }
           }
     }
}
void solve()
{
   // int t;cin>>t;while(t--)
   {

        ll n; cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>col[i];
            ans[i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
            ll u,v; cin>>u>>v; u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0);
        for(int i=0;i<n;i++)
        {
           cout<<ans[i]<<" ";
        }
        cout<<endl;
      }
}
int main(){pls(); solve(); return 0;}