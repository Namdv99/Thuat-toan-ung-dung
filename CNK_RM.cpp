#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long g= 1000000007;
int n;

long long tinh(int k){
	long long kq=1;
	int a[2000], dem= 0;
	a[0] = n-k+1;
	for( int i= 1; i< k; i++) a[i]= a[i-1]+1;
	for( int i= k; i >= 2; i--){
		int j;
		for( j= k-1; j >= 0; j--){
			if( a[j] % i == 0){
				a[j]= a[j] / i;
				break;
			};
		};
		if(j == -1){
			int h= i;
			while(h > 1){
				for(int m= 2; m <= h; m++){
					if( h % m == 0){
						h= h/m;
						for(int t= 0; t< k; t++){
							if( a[t] % m == 0){
								a[t]= a[t] / m;
								break;
							}
						}
					}
				}
			}
		}
	}
	//for(int i= 0; i< b.size(); i++)cout<<b[i]<<" ";
	for( int i= 0; i< k; i++){
		kq= kq * a[i];
		if( kq > g ) kq= kq % g;
	}
	return kq;
}
int main(){
	//input
	int k;
	cin>>k>>n;
	//ham
	if( k > n/2 ) cout<< tinh(n-k);
	else cout<< tinh(k);
	return 0;
}
