#include<iostream>
#include<vector>
using namespace std;
int m,n,kq= 100000;

void duyet(vector< vector<int> > &cour, vector< vector<int> > &xd, vector<int> mark, vector<int> gv, int i){
	if(i==n){
		int dem=0;
		for(int j= 0; j< gv.size(); j++)
			if(dem < gv[j])	dem= gv[j];
		if( kq > dem )	kq= dem;
		return; 
	};
	for(int j= 0; j< n; j++){
		if(!mark[j]){
			mark[j]= 1;
			int k;
			//them mon cho giao vien
			for(k= 0; k< m; k++){
				int thoat=0;
				for( int K= 0; K< cour[k].size(); K++)	
					if(j == cour[k][K]){
						gv[k]++;
						thoat++;
					};
				if(thoat> 0) break;
			};
			// Xoa cac mon xd cua giao vien vua them
			vector <int> them;
			for(int t= 0; t< cour[k].size(); t++){
				for(int r= 0; r< xd[j].size(); r++){
					if( cour[k][t] == xd[j][r]){
						cour[k].erase(cour.at(k).begin()+k);
						them.push_back(xd[j][r]);
						break;
					} 
				}
			};
			//De quy
			duyet(cour, xd, mark, gv, i+1);
			gv[k]--;
			for(int r=0; r< them.size(); r++){
				cour[k].push_back(them[r]);
			};				
			mark[j]= 0;
		}
	}
}
int main(){
// INPUT
	cin>>m>>n;
	vector< vector<int> > cour(m);
	// Nhap list GV
	for(int i=0; i< m; i++){
		int h, k;
		cin>>h;
		for (int j= 0; j< h; j++){
			cin>> k;
			k= k-1;
			cour.at(i).push_back(k);
		}
	};
	// NHap list mon xung dot
	vector< vector<int> > xd(n);
	int k;
	cin>> k;
	for(int i= 0; i< k; i++){
		int K, H;
		cin>> K>> H;
		K=K-1;
		H=H-1;
		xd[K].push_back(H);
	};
	
// Ham 
	vector<int> mark(m, 0), gv(n, 0);
	duyet(cour, xd, mark, gv, 0);
	cout<<kq;
	return 0;
}
