// string pattern search rabin karp
/*Watto, the owner of a spare parts store, has recently got an order for the mechanism that can process strings in a certain way. Initially the memory of the mechanism is filled with n strings. Then the mechanism should be able to process queries of the following type: "Given string s, determine if the memory of the mechanism contains string t that consists of the same number of characters as s and differs from s in exactly one position".

Watto has already compiled the mechanism, all that's left is to write a program for it and check it on the data consisting of n initial lines and m queries. He decided to entrust this job to you.

Input
The first line contains two non-negative numbers n and m (0 ≤ n ≤ 3·105, 0 ≤ m ≤ 3·105) — the number of the initial strings and the number of queries, respectively.

Next follow n non-empty strings that are uploaded to the memory of the mechanism.

Next follow m non-empty strings that are the queries to the mechanism.

The total length of lines in the input doesn't exceed 6·105. Each line consists only of letters 'a', 'b', 'c'.

Output
For each query print on a single line "YES" (without the quotes), if the memory of the mechanism contains the required string, otherwise print "NO" (without the quotes).

Examples
inputCopy
2 3
aaaaa
acacaca
aabaa
ccacacc
caaac
outputCopy
YES
NO
NO*/
#include<bits/stdc++.h>
using namespace std;
// polynomial roolling hashing
//  s[0]+s[1]*p+s[2]*p^2........%mod
// p should be prime > = no of character string 257
// mod as large as possible
#define int long long
#define mod 1000000007
const int MAX=600010;
int n,m;
set<int> mp;
int mul[MAX];
inline int hashi(string s){

	// int p=0;
	int poo=1;
	for(int i=0;i<s.size();i++){
		// p=(p+(s[i]-'a'+1)*poo)%mod;
		poo=(poo*257 + s[i])%mod; //   s[0]*p3+s[1]*p2+s[2]*p+s[3]
		// poo*=257;
	}
	return (int)poo;
}
bool Find(string s)
{
     int hh=hashi(s);

     for(int i=0;i<s.size();i++)  //  abc=a*p2+b*p+c // bbc=abc+(b-a)*p2
     	for(int j='a';j<='c';j++ )
     		if(s[i]!=j)
     			{  
     				int h=(((j-s[i])*mul[s.size()-i-1]+hh)%mod+mod)%mod;
     				if(mp.find(h)!=mp.end())
     					return 1;

     			}      
 return 0;
}

int32_t main()
{  

   mul[0]=1;
   for(int i=1;i<MAX;i++) 
   mul[i]=(mul[i-1]*257)%mod;	
   
   cin>>n>>m;

   for(int i=0;i<n;i++)
   {
      	string s; cin>>s;
        int hh=hashi(s);
        mp.insert(hh); 
   }
   for(int i=0;i<m;i++)
   {
   	   string s; cin>>s;
   	   if(Find(s))
   	   	cout<<"YES"<<endl;
   	   else
   	   	cout<<"NO"<<endl;
   } 
  
    
    return 0;


}
