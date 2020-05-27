#include<iostream>
#include<vector>
using namespace std;

unsigned long long hist(vector <int> vt){
	int max= vt.at(1);
	for(int i= 0; i< vt.size(); i++ )
		if( max < vt.at(i)) max= vt.at(i);
	int kt= 1;

	unsigned long long GTLN= 0;
	while(kt <= max){
		for(int i= 0; i< vt.size(); i++){
			int dem= 0;
			while((i < vt.size()) && (vt.at(i) >= kt)){
				dem += kt;
				i++;
			};
			if( GTLN < dem) GTLN = dem;
		};
		kt++;
	};
	return GTLN;
	return 0;
}

int main(){
	//INPUT
	vector< vector< int > > test;
	int k= 1, h;
	while(k){
		cin>> k;
		if(k == 0) break;
		vector< int> add;
		for(int i= 0; i< k; i++){
			cin>> h;
			add.push_back(h);
		};
		test.push_back(add);
	};
	//MAIN
	for(int i= 0; i< test.size(); i++){
		cout<<hist(test.at(i));
		cout<<"\n";
	}
	return 0;
}
