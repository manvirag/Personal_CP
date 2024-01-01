#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mxN =200005;
vector<int> g[mxN];
int n;
int in[mxN],out[mxN];  
 /*
  in-->depth out--> go to parent then  1 one way---> parent of parent 2 way --> child of parent ie cousin of in
   1way---> 1+out[parent]
   2way--> 2+max(of in of all cousin except current node)
   out =max (1way,2way)
  
  */
void dfs1(int i,int parent)
{
	in[i]=0;
	for(auto child: g[i])
	{
		  if(child==parent) continue;
		  dfs1(child,i);
		  in[i]=max(in[i],1+in[child]);
	}
}
void dfs2(int i,int parent)
{
	int mx1=-1,mx2=-1;
	for(auto child: g[i])
	{
		if(child==parent)continue;
		 if(in[child]>=mx1){
		 	mx2=mx1;
		 	mx1=in[child];
		 }
		 else if(in[child]>mx2)
		 mx2=in[child];
	}
	for(auto child:g[i])
	{   if(child==parent)continue;
		 int use=mx1;
		 if(mx1==in[child])
		 use=mx2;
		 out[child]=max(2+use,1+out[i]);
		 dfs2(child,i);
	}
}
int32_t main(){
  ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

      /*
         problem statement--> simple ---> find the diameter for all nodes of tree
         you can find it on cses tree distance 1
         img --> folder
	  */
	  
	  cin>>n;
	  for(int i=0;i<n-1;i++){
	  	int u,v; cin>>u>>v; u--;v--;
	  	g[u].push_back(v);
	  	g[v].push_back(u);
	  }
	  dfs1(0,-1);   // in
	  dfs2(0,-1);   // out
	 
	  for(int i=0;i<n ;i++)
	  cout<<max(in[i],out[i])<<" ";
	  cout<<endl;	
	  
	  




 return 0;}


