#include<bits/stdc++.h>
using namespace std;
const int MAX =150000;
#define ll long long 
ll mod= 2000000011;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
//#endif
}
// ............................................................
// Returns (a * b) % m
// time complexity is log(b)
ll mul_mod(ll a, ll b, ll m){
		ll x = 0, y = a;
		while (b > 0){
			if(b & 1){
				// No overflows in additons.
				x = (x + y) % m;}
			y = (y + y) % m;
			b >>= 1;}
		return x;
}
inline int madd(int x,int y){ return (x%mod +y%mod)%mod;}
inline int msub(int x,int y){return (mod+x%mod -y%mod)%mod;}
// ...........................................................
ll gcd(ll a,ll b){if(b==0) return a;return gcd(b,a%b);}
// x%mod * a%mod  this can be overflow  10^11*10^7 may therefore we need > long long (64 bit)
//  either use incuit int_128 or use upper multiplication with time complexity log b
ll powmod(ll a, ll mod,ll p){ if(p==0) return 1LL%mod;  ll res; ll x=powmod(a,mod,p/2); res=x;if(p&1) x=mul_mod(x,a,mod);   return mul_mod(x,res,mod);}
ll exp(ll a,ll p){ if(p==0) return 1;  ll res; ll x=exp(a,p/2); res=x;if(p&1) x=(x * a);   return (x * res);}
ll sqt(ll x){  ll l=1LL;  ll r=x;  ll res; while(l<=r){ ll mid=l+(r-l)/2; if(mid*mid<=x){res=mid; l=mid+1;}else r=mid-1;   } return res;}
vector<int> soe(ll upto)
{             
	         vector<bool> prime(upto+1,0);
	         prime[1]=1;
	         prime[0]=1;
             for(int i=2;i<=sqt(upto);i++)
             {
                        if(!prime[i])
                        {
                              for(int j=2*i;j<=upto;j+=i)
                              	prime[j]=1;
                        	
                        }

             }
             vector<int> res;
             res.push_back(2);
             for(int i=3;i<prime.size();i+=2)
             {
                   if(!prime[i])
                   	 res.push_back(i);
             }
             return res;
}
int di[8]={-1,-1,-1,1,1,1,0,0};
int dj[8]={-1,0,1,-1,0,1,-1,1};
int ii[4]={0,0,-1,1};
int jj[4]={-1,1,0,0};
/*
  Read question untill don't understand
  Think logic
  Think edge cases
  Think twice code once
*/

/*


   2d rabin karp----> for searching pattern in matrix
   
   Rasta and Kheshtak--> hackerearth queastion
   
   question is that--> given two matrix find the maximum size of common square which is in both matrix
   
   logic---> if 5 size then 4 also match ......
   
   Do binary search on answer for size X
   
   X--->
   
   find the hash of all square of size X in matrix 1  -----> H1
   sort it 
   
   find hash of all square of size X in matrix 2 one by one
   check for existence in H1 with again binary searxh
   
   if( exist) 
   return true
   
   
   problem here is how to find hash 
   and next heah on constant time like linear rabin karp
   
   logic-->
   
   find the sum  matrix of given matrix -->like for index a,b-->sum(a-1)(b)+sum(a)(b-1)-sum(a-1)(b-1)+arr[a][b]
   
   but sum can be same for many square so for good hash--->sum(a-1)(b)+sum(a)(b-1)-sum(a-1)(b-1)+arr[a][b]*C1^(a)C2^(b)
   
   
   Now problem is how to check square are same for different indices
   
   Now for this multiply after getting sum by C1^(C-a)C2^(C-b)
   
*/
ll c1[2001],c2[2001];
ll n1,m1,n2,m2;
ll mat1[1001][1001],mat2[1001][1001];
ll sum1[1001][1001],sum2[1001][1001];
ll p=173;
ll q=137;
vector<ll> hash1;

ll find_2d_hash1(int i,int j,int sz)
{
	     ll res=sum1[i+sz-1][j+sz-1]-sum1[i-1][j+sz-1]-sum1[i+sz-1][j-1]+sum1[i-1][j-1];
	     res*=c1[2000-i]*c2[2000-j];
	     return res;
}
ll find_2d_hash2(int i,int j,int sz)
{
		 ll res=sum2[i+sz-1][j+sz-1]-sum2[i-1][j+sz-1]-sum2[i+sz-1][j-1]+sum2[i-1][j-1];
	     res*=c1[2000-i]*c2[2000-j];
	     return res;
}
bool ok(int sz)
{
	   hash1.clear();
	   for(int i=1;i+sz<=n1+1;i++)
	   		for(int j=1;j+sz<=m1+1;j++)
	   			 hash1.push_back(find_2d_hash1(i,j,sz));
	   
	   sort(hash1.begin(),hash1.end()) ;
	   for(int i=1;i+sz<=n2+1;i++)
	   		for(int j=1;j+sz<=m2+1;j++)
	   			 {
	   			 	  ll res=find_2d_hash2(i,j,sz);
	   			 	  int ix=lower_bound(hash1.begin(),hash1.end(),res)-hash1.begin();
	   			 	  if(ix!=hash1.size()&&hash1[ix]==res)
	   			 	  return true;
	   			 	  
	   			 }
	   return false;
	   
	   
	
}
void solve()
{ 
		 cin>>n1>>m1;
		 
		 for(int i=1;i<=n1;i++)  //for padding starting at ix=1
				for(int j=1;j<=m1;j++)
					cin>>mat1[i][j];
		 cin>>n2>>m2;
		 
		 for(int i=1;i<=n2;i++)  
				for(int j=1;j<=m2;j++)
					cin>>mat2[i][j];
		 
		 c1[0]=1;
		 c2[0]=1;
		 
		 for(int i=1;i<=2000;i++)
		 c1[i]=c1[i-1]*p;
		 for(int i=1;i<=2000;i++)
		 c2[i]=c2[i-1]*q;
		 
		 
		 for(int i=1;i<=n1;i++)  
				for(int j=1;j<=m1;j++)
					   sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+mat1[i][j]*c1[i]*c2[j];

					   
					
		 for(int i=1;i<=n2;i++)  
				for(int j=1;j<=m2;j++)
				       sum2[i][j]=sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1]+mat2[i][j]*c1[i]*c2[j];

					
		 
		 int l=0;
		 int h=701;
		 int res=-1;
		 while(l<=h)
		 {
		 	 int mid=(l+h)/2;

		 	 if(ok(mid))
		 	 {
		 	      res=mid;
				  l=mid+1;	
			 }
			 else
			 h=mid-1;
		 }
		 cout<<res<<endl;
}
int main(){pls(); solve(); return 0;}
