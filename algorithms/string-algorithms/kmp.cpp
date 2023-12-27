// kmp
// no of pattern in text
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define w(x) int x; cin>>x; while(x--)
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define vi vector<int>
#define mod 1000000007
#define pi pair<int,int>
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end() 
#define i32 int32_t
#define i16 int16_t
// const MAX 1e5
// int fac[MAX+1];
void filllps(int lps[],string p)
{
	      int len=0;
	      lps[0]=0;
	      int pii =1;   //pattern p0inter

	      while(pii<p.size())
	      {
	      	        if(p[pii]==p[len])
	      	        	{len++; lps[pii]=len; pii++;}
	      	        else{ if(!len) {lps[pii]=0;pii++;}else {len=lps[len-1];}}
          }
}
int KMP(string p,string t)
{
	   int pp=p.size();
	   int tt=t.size();

	   int lps[pp];

	   filllps(lps,p);

	   // for(int i=0;i<pp;i++)
	   	// cout<<lps[i]<<" ";
       int ans=0;
	   int i=0;  // for text
	   int j=0;  // for pattern
	   while(i<tt)
	   {
	   	    if(p[j]==t[i]) // while(p[j]==t[i] && i<tt && j<pp)
	   	    {
	   	    	  i++;
	   	    	  j++;
	   	    }
	   	    if(j==pp)   // got the full pattern
	   	    {
	   	    	 ans++;
	   	    	 j=lps[j-1];

	   	    }
	   	    if(p[j]!=t[i])
	   	    {
	   	    	if(j)
	   	    	j=lps[j-1]; //for saving segmentatiton fault , we will not decrease i here becoz there is enough j
	   	        else
	   	    	i++;
	   	    }

	   	    // cout<<i<<" "<<j<<endl;

	   }
	   return ans;
}
i32 main(){

  // time_t start,end;     // time(&start);// time(&end);

     string p,t; cin>>p>>t;

     cout<<KMP(p,t)<<endl; 

 

  //   double time_taken = double(end - start);    // cout << "Time taken by program is : " << fixed  //      << time_taken << setprecision(5); // cout << " sec " << endl; 

  return 0;
}
