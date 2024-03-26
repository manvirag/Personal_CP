#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
ll n,m;
set<int> g[100001];
set<int> not_visi;
void dfs(int x){
    vector<int> vec;
    for(auto it : not_visi)
        if(g[x].find(it)==g[x].end())
            vec.push_back(it);
    for(auto it : vec)
        not_visi.erase(it);
    for(auto it : vec)
        dfs(it);
}
void solve()
{   cin>>n>>m;
      for(int i=0;i<m;i++){
            ll u,v; cin>>u>>v;
            g[u].insert(v);
            g[v].insert(u);
      }
      ll ans=-1;
      for(int i=1;i<=n;i++)
            not_visi.insert(i);

      for(int i=1;i<=n;i++){
             if(not_visi.find(i)!=not_visi.end()){
                  dfs(i);
                  // cout<<endl;
                  ans++;
             }
      }
      cout<<ans<<endl;




}
int main(){pls(); solve(); return 0;}