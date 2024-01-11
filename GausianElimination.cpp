#include<bits/stdc++.h>
#define pb push_back
using namespace std;
void solveNdim(vector<vector<double> > &v, int n, vector<double> &b){
	
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int h=0; h<n; h++){
				cout<<v[j][h]<<" ";
			}
			cout<<b[i];
			cout<<endl;
		}
		cout<<"-----"<<endl;
		for(int j=i+1; j<n; j++){
			double div=v[j][i]/v[i][i];
			for(int h=i; h<n; h++){
				v[j][h]-=div*v[i][i];
			}
			b[j]-=b[i]*div;
		}
		
	}
	
	
	
	double x[n];
	for(int i=n-1; i>=0; i--){
		int sum=0;
		for(int j=n-1; j>i; j--){
			sum+=x[j]*v[i][j];
		}
		x[i]=(b[i]-sum)/v[i][i];
	}
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
	
	
	
}
//void generate(){
//	int MM=100;
//	int n;
//	for(int i=0; i<MM; i++)n=rand()%MM;
//	
//	
//}
int main(){

	cout<<setprecision(1)<<fixed;
	int n;
	cin>>n;
	vector<vector<double> > v(n);
	vector<double> b(n);	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			double x;
			cin>>x;
			v[i].pb(x);
		}
	}
	for(double i=0; i<n; i++)cin>>b[i];
	solveNdim(v,n,b);
}
/*
3
1 1 1
2 -1 -1
6 -4 2

3 0 4
*/
