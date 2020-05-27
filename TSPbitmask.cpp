#include<iostream>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m;
	k= min(n,m);
	cout<<(1<<n | m);
	return 0;
}
