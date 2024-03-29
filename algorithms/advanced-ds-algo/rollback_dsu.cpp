// Not tested.
class DSU{
  public:
  	 vector<int> parent;
  	 vector<int> rank;
  	 stack<pair<int,int>> node_vs_parent_rank;

  	 DSU(int n)
  	 {
  	 	  parent.resize(n);
  	 	  rank.resize(n);
  	 	  for(int i=0;i<n;i++)
  	 	  	rank[i]=1,parent[i]=i;
  	 }
  	 void rollback(){
  	     pair<int,int> cur = node_vs_parent_rank.top();
  	     node_vs_parent_rank.pop()
  	     int parent_node = parent[cur.first];
  	     parent[cur.first]=cur.first;
  	     rank[parent_node] = cur.second;
  	 }
  	 void Union(int u,int v)
  	 {

           int pu=findd(u);
           int pv=findd(v);
           if(pu==pv) return ;
           pair<int,int> cur;
           if(rank[pu]<rank[pv])
           {
                 cur.first = pu;
                 parent[pu]=pv;
                 rank[pv]+=rank[pu];
                 cur.second = rank[pv];
           }
           else
           {
           		  parent[pv]=pu;
           		  cur.first = pv;
                  rank[pu]+=rank[pv];
                  cur.first = rank[pu];
           }

  	 }
  	 int findd(int i)
  	 {
  	 		if (parent[i] != i)
                 return findd(parent[i]);
             return parent[i];
  	 }


};
