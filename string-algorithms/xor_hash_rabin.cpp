/* codeforces */


#include<bits/stdc++.h>
  using namespace std;
  #define int long long int
  #define ld long double
  #define w(x) int x; cin>>x; while(x--)
  #define fr(i,n)   for(int i=0;i<n;i++)
  #define frr(i,n)  for(int i=1;i<=n;i++)
  #define vi vector<int>
  #define mod 1000000000007
  #define pi pair<int,int>
  #define ff first
  #define ss second
  #define pb push_back
  #define mk make_pair
  #define all(x) x.begin(),x.end() 
  #define i32 int32_t
  #define i16 int16_t
  #define endl "\n"
  #define v2dd vector<vector<int>>
  #define v2d(m,r,c) vector<vector<int>> m(r,(vector<int> (c)))
  const int MAX =150000;
  void pls()
  {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  }
  // __builtin_popcount = int
  // __builtin_popcountl = long int
  // __builtin_popcountll = long long

  inline int madd(int x,int y)
  { 
     return (x%mod +y%mod)%mod;
  }
  inline int msub(int x,int y)
  {
     return (mod+x%mod -y%mod)%mod;
  }
  string a;
  string s;
  int k;
  unordered_set<int> st;
  i32 main(){pls();  // time_t start,end;     // time(&start);// time(&end);
  // .................................................................................................................................................   
   
   cin>>s;
   int n=s.size();
   cin>>a; 
    cin>>k;
  int res=0;

  for(int i=0;i<n;i++){

     string temp="";
     int tk=0;
     int h=0;
    for(int j=i;j<n;j++)
    {
         
            temp+=s[j];
            if((a[s[j]-'a']-'0')==0)
              tk++;
             // cout<<a[s[j]-'a']<<" "; 
            if(tk>k)
            break; 

            h=((h*131)^s[j]);
          
          

            if(st.find(h)==st.end())
            {
                 res++;
                 st.insert(h);
            }



    }}
   cout<<res;   


     
  // ...................................................................................................................................
  //   double time_taken = double(end - start);    // cout << "Time taken by program is : " << fixed  //      << time_taken << setprecision(5); // cout << " sec " << endl; 
   return 0;}
       
