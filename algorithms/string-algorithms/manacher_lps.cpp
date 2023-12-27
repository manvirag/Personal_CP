// manacher algorithm no of palindrome substring in o(n)
// cp algorithm
#include<bits/stdc++.h>
using namespace std;
#define int long long 
string s;
string aspermanacher()
{
	   string temp="";
	   temp+="{";

	   for(int i=0;i<s.size();i++)
	   {
	   	 temp+="#";
	   	 temp+=s[i];
	   }

	   temp+="#}";

	   cout<<temp<<endl;
	   return temp;
}
int longest_palindrome_sustring(){
	string ss=aspermanacher();
	
     int lps[ss.size()]={0};     // store longest palindrome of particular index as centre

     int centre=0 , right=0;   // centre and right limit of maximum palindrome substring till

     int mx_lps=1;

     for(int i=1;i<ss.size()-1;i++){

     	    int mirror_index=centre-(i-centre);

     	    if(right>i) // unlimit
     	    {
     	    	lps[i]=min(right-i,lps[mirror_index]);
     	    }


     	    // extending be focus since we extending forward to i+lps[i]--> right so linear complexity
           while(ss[i-lps[i]-1]==ss[i+lps[i]+1])
           	lps[i]++;


           if(i+lps[i]>right)          // updating centre
           {
           	   centre=i;
           	   right=i+lps[i];
           }

           mx_lps=max(mx_lps,lps[i]);
     }     
 return mx_lps;

}
int32_t main()
{
       int t;cin>>t; while(t--){
       	 cin>>s;

       	 cout<<longest_palindrome_sustring()<<endl;
       }


}
