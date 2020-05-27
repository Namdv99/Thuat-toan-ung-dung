#include<iostream>
using namespace std;
int k= 1000000000+7;
unsigned long long N;

unsigned int mod(int a , int b){
	if(b == 1)	return (a % k);
	if(b % 2 == 0){
		N = mod(a, b/2);
		N = N*N;
		return ( N % k);
	};
	if(b % 2 == 1){
		N = mod(a, (b-1)/ 2);
		N = ( N* N) % k;
		N = N*a;
		return (N % k);
	}
}
int main(){
	int a, b;
	cin>>a>>b;
	cout<<mod(a, b);
	return 0;
}
