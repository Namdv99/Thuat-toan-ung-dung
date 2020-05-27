 #include<iostream>
 #include<bits/stdc++.h>
 #include<vector>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
long long Tich(vector< int> VT1, vector< int> VT2){
	IOS;
	long long tich= 0;
	sort( VT1.begin(), VT1.end());
	sort( VT2.begin(), VT2.end());
	for( int i= 0; i< VT1.size(); i++){
		tich+= VT1.at(i) * VT2.at(VT2.size() - 1 - i);
	};
	return tich;
}

int main(){
	IOS;
	//INPUT
	int T, k, at;
	cin>> T;
	vector< vector < int > > VT(2*T);
	for(int i= 0; i< T; i++){
		cin>> k;
		for( int j= 0; j< k; j++){
			cin>> at;
			VT.at(2*i).push_back(at);
		};
		for( int j= 0; j< k; j++){
			cin>> at;
			VT.at(2*i + 1).push_back(at);
		}
	};

	for( int i= 0; i< T; i++){
		cout<<"Case #"<<i+1<<": "<<Tich(VT.at(2*i), VT.at(2*i+1));
		cout<<"\n";
	};
	return 0;
}
