// rabin karp
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
#define fastio   ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX =1e5;
int d=256;
int md=1;
int h=101;
bool rabinkarp(char txt[],char pat[])
{
	  // my hash function is abc===(a*256^2+b*a56^1+c )%101
	int pp=strlen(pat);
      int tt=strlen(txt);
      int ph=0;
      int th=0;
    
      for(int i=1;i<=pp-1;i++)
      md=(md*d)%h;        // 256^2 we would multiply it later


      // now pattern searching like windowsliding
      // calculate hash of size of pattern in text
      for(int i=0;i<pp;i++)
      {
      	    ph=(ph*d+pat[i])%h;
      	    th=(th*d+txt[i])%h;
      }

      for(int i=0;i<=tt-pp;i++)
      {
      	     if(ph==th)
      	     {
      	     	     int j=0;
      	     	     for(j=0;j<pp;j++)
      	     	     	if(txt[i+j]!=pat[j])
      	     	          break;

      	     	      if(j==pp)
      	     	      return true;    
      	     }
                 // shifting window right removing one word and adding one word
      	     if(i<tt-pp)
      	     {
      	     	   th=(d*(th-txt[i]*md)+txt[i+pp])%h;
      	     	   if(th<0)
      	     	  	th+=h;
      	     }
      }
      return false;

}
i32 main(){

  // time_t start,end;     // time(&start);// time(&end);

      char txt[]="anubhav gupta";
      char pat[]="gupta";

      if(rabinkarp(txt,pat))
      	cout<<"YES"<<endl;
      else
      	cout<<"NO"<<endl;

 

  //   double time_taken = double(end - start);    // cout << "Time taken by program is : " << fixed  //      << time_taken << setprecision(5); // cout << " sec " << endl; 

  return 0;
}
     
