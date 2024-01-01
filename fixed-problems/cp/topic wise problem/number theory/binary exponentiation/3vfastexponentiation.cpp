// f[3]=2*f[2]-1*f[1]+1 
#include<bits/stdc++.h> 
using namespace std; 
#define mod 1000000007
#define int long long
void multiply(int a[3][3], int b[3][3]) 
{ 
	int mul[3][3]; 
	for (int i = 0; i < 3; i++) 
	{ 
		for (int j = 0; j < 3; j++) 
		{ 
			mul[i][j] = 0; 
			for (int k = 0; k < 3; k++) 
				mul[i][j] =(mul[i][j] +(a[i][k]*b[k][j])); 
		} 
	} 

	for (int i=0; i<3; i++) 
		for (int j=0; j<3; j++) 
			a[i][j] = mul[i][j]; 
} 
int power(int F[3][3], int n) 
{ 
	int M[3][3] = {{2,-1,4}, {1,0,0}, {0,1,0}}; 

	if (n==1) 
		return ((F[0][0]*6) + (F[0][1]) + F[0][2]); 

	power(F, n/2); 

	multiply(F, F); 

	if (n%2 != 0) 
		multiply(F, M); 

	//  F(1) = 1, F(2) = 6 
	return ((F[0][0]*6) + (F[0][1]) + F[0][2]) ; 
} 
int findNthTerm(int n) 
{ 

	int F[3][3] = {{2,-1,4}, {1,0,0}, {0,1,0}} ; 

	if(n==0) 
    return 0; 
	if(n==1) 
	return 1;
	if(n==2)
	return 6; 

	return power(F, n-2); 


} 

int32_t main() 
{ 
 int t;cin>>t; while(t--){ 
     int i; cin>>i;
cout << findNthTerm(i)<<endl;} 

return 0; 
} 
