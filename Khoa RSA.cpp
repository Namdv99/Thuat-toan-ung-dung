#include<iostream>
using namespace std;
int main(){
	int p,q;
	cin>>p>>q;
	unsigned int n,phi;
	n=p*q;
	phi=(p-1)*(q-1);
	cout<<"Chon e:";
	int e,d=0;
	cin>>e;
	for(int i=1; i<1000; i++){
		if((i*phi+1) % e ==0){
			d=(i*phi+1)/e;
			break;
		}
	};
	if(d==0)	cout<<"NOT KEY";
		else cout<<" Ku=( "<<e<<" , "<<n<<" )\n Kr=( "<<d<<" , "<<n<<" )";
	return 0;
}
