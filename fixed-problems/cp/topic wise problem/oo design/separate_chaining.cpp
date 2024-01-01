#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mxN =150000;
class Hash{
	public:
		list<int> * table;
		int sz;
		
		Hash(int size)
		{
			sz=size;
			table=new list<int> [sz];
		}
		
		int hashkey(int val)
		{
			return val%sz;
		}
		void insert(int val)
		{
			 int key=hashkey(val);
			 table[key].push_back(val);
		}
		
		bool Find(int val)
		{
			int key=hashkey(val);
			
			for(auto i=table[key].begin();i!=table[key].end();i++)
			{
				 if(*i==val)
				 return true;
			}
			
			return false;
		}
		
		void del(int val)
		{
			 int key=hashkey(val);
			
			auto i=table[key].begin();
			for(i=table[key].begin();i!=table[key].end();i++)
			{
				 if(*i==val)
				 break;
			}
			if(i==table[key].end()) return ;
			 table[key].erase(i);
		}
		
		
	
	
};
int32_t main(){
  ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

		Hash h(7);
		
		int a[7]={2,7,6,9,3,5,1};
		
		for(int i=0;i<7;i++)
		h.insert(a[i]);
		
		if(h.Find(6))
        cout<<"working"<<endl;
        
        h.del(6);
        
        if(!h.Find(6))
        cout<<"working"<<endl;
 		
		
		





 return 0;}


