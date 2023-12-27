/*D. Prefixes and Suffixes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a string s = s1s2...s|s|, where |s| is the length of string s, and si its i-th character.

Let's introduce several definitions:

A substring s[i..j] (1 ≤ i ≤ j ≤ |s|) of string s is string sisi + 1...sj.
The prefix of string s of length l (1 ≤ l ≤ |s|) is string s[1..l].
The suffix of string s of length l (1 ≤ l ≤ |s|) is string s[|s| - l + 1..|s|].
Your task is, for any prefix of string s which matches a suffix of string s, print the number of times it occurs in string s as a substring.

Input
The single line contains a sequence of characters s1s2...s|s| (1 ≤ |s| ≤ 105) — string s. The string only consists of uppercase English letters.

Output
In the first line, print integer k (0 ≤ k ≤ |s|) — the number of prefixes that match a suffix of string s. Next print k lines, in each line print two integers li ci. Numbers li ci mean that the prefix of the length li matches the suffix of length li and occurs in string s as a substring ci times. Print pairs li ci in the order of increasing li.

Examples
inputCopy
ABACABA
outputCopy
3
1 4
3 2
7 1
inputCopy
AAA
outputCopy
3
1 3
2 2
3 1
*/

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
#define fastio   ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX =100001;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
string a; 
int lps[MAX];
int n;
int prefunction()
{
   int len=0;
   lps[0]=0;

   int i=1;

   while(i<n)
   {
       if(a[i]==a[len]){
        ++len; lps[i++]=len;

       }
       else if(len)
        len=lps[len-1];
      else
        lps[i++]=0;
       
   
   }

   return lps[n-1];
}

i32 main(){pls();
    cin>>a; n=a.size();
    int x=prefunction();
    
    // x is longest prefix which is also suffix

    // possible palindromic length = x,x-1,..1
      int k=x;

      vector<int> pl; 
    while(k){
        pl.push_back(k); k=lps[k-1];
    }
    // full string palin

      cout<<pl.size()+1<<endl;
 
    // now i have prefix length which is suffix also
    // now i have to find count of it ...hmmm we can do it by prefix function
    // suppose lps =x ,, then for x-1 length we have to see lps[x-1]
    
   // for(int i=0;i<n;i++)
    // cout<<lps[i]<<" ";
  // cout<<endl;
    int cnt[n+1];
    for(int i=0;i<=n;i++) cnt[i]=1;

    for(int i=n;i>=1;i--) cnt[lps[i-1]]+=cnt[i]; 
    
     

     sort(all(pl));
    for(int i=0;i<pl.size();i++)
      cout<<pl[i]<<" "<<cnt[pl[i]]<<endl;
      cout<<n<<" "<<"1"<<endl;




return 0;}
     
