#include<iostream>
using namespace std;
int n;

int Marge(int data[], int left, int right, int Ar[]){
	if(left == right)	return 0;
	int mid=(left + right)/2;
	// Chia nho
	Marge(data, left, mid, Ar);
	Marge(data, mid+1, right, Ar);
	// Sap xep
	int i= left;
	int j= mid+1;
	int k=0;
	while(i <= mid || j<= right){
		if(i > mid)	
			Ar[k++]= data[j++];
		else if(j > right)
			Ar[k++]= data[i++];
			else if( data[i] > data[j])
				Ar[k++]= data[j++];
				else Ar[k++]= data[i++];
	};
	for (int i = 0; i < k; i++)
		data[left + i] = Ar[i];
	return 0;
}
main(){
	cin>>n;
	int data[n], Ar[n];
	for(int i=0; i<n; i++)	cin>>data[i];
	Marge(data, 0, n-1, Ar);
	for(int i=0; i<n; i++)cout<<Ar[i]<<" ";
	return 0;
}
