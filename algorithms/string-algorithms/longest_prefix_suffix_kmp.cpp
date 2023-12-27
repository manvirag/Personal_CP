/*D2. Prefix-Suffix Palindrome (Hard version)
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output

this is the hard version of the problem. The difference is the constraint on the sum of lengths of strings and the number of test cases. You can make hacks only if you solve all versions of this task.

You are given a string s, consisting of lowercase English letters. Find the longest string, t, which satisfies the following conditions:

The length of t does not exceed the length of s.
t is a palindrome.
There exists two strings a and b (possibly empty), such that t=a+b ( "+" represents concatenation), and a is prefix of s while b is suffix of s.
Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤105), the number of test cases. The next t lines each describe a test case.

Each test case is a non-empty string s, consisting of lowercase English letters.

It is guaranteed that the sum of lengths of strings over all test cases does not exceed 106.

Output
For each test case, print the longest string which satisfies the conditions described above. If there exists multiple possible solutions, print any of them.

Example
inputCopy
5
a
abcdfdcecba
abbaxyzyx
codeforces
acbba
outputCopy
a
abcdfdcba
xyzyx
c
abba
Note
In the first test, the string s="a" satisfies all conditions.

In the second test, the string "abcdfdcba" satisfies all conditions, because:

Its length is 9, which does not exceed the length of the string s, which equals 11.
It is a palindrome.
"abcdfdcba" = "abcdfdc" + "ba", and "abcdfdc" is a prefix of s while "ba" is a suffix of s.
It can be proven that there does not exist a longer string which satisfies the conditions.

In the fourth test, the string "c" is correct, because "c" = "c" + "" and a or b can be empty. The other possible solution for this test is "s".
*/

// prereuisite prefix function kmp algorithm
// first undrestand prefix function properly just reverse string and add and just think
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
#define endl "\n"
#define fastio   ios_base::sync _with_stdio(false);cin.tie(NULL);
const int MAX =1000001;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
string a;
int n;
int kmp_longest_prefix(string aa){

   string ra=aa;
   reverse(aa.begin(),aa.end());
   string hero=ra+"#"+aa;
  
  // cout<<hero<<" ";
  
  int lps[(int)hero.size()]={0};
  int n=(int)hero.size();
  int len=0;
   int i=1;
   // construction longest prefix suffix
   while(i<n){
      if(hero[i]==hero[len])
        lps[i++]=++len;
      else
        {if(len)
          len=lps[len-1];
          else
            lps[++i]=0;}
   }
   // for(int i=1;i<n;i++)
    // cout<<lps[i]<<" ";
   return lps[n-1];
  

}
i32 main(){pls();
   int t; cin>>t;while(t--){
     cin>>a;
     n=a.size();
     int i=0,j=n-1;
     string ans="";
     while(i<=j && a[i]==a[j])
      i++,j--;

     if(i)
      ans=a.substr(0,i);
     
     if(j-i+1>0){
     string rem=a.substr(i,j-i+1);

     int r1=kmp_longest_prefix(rem);
     reverse(all(rem));
     int r2=kmp_longest_prefix(rem);

     if(r1>r2)
      { 
        reverse(all(rem));
        ans+=rem.substr(0,r1);
      }
     else
      ans+=rem.substr(0,r2);}

    if(i)
    {
      if(j<i ){
         if(n&1)
         ans+=a.substr(j+2);
         else  ans+=a.substr(j+1);
      }
      
    else
      ans+=a.substr(j+1);
    }
   cout<<ans<<endl;

   }
 
  return 0;}
     
