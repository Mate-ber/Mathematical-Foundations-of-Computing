#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n;
const double eps=1e-2;
vector<vector<double> > mat(1000);
vector<double> bb;
vector<double> intpas;
void solveNdim(vector<vector<double> > &v, int n, vector<double> &b){
	
	for(int i=0; i<n; i++){
		if(!v[i][i]){
			for(int j=i+1; j<n; j++){
				if(v[j][i]){
					swap(v[i],v[j]);
					swap(b[i],b[j]);
					break;
				}
			}
		}
		
		for(int j=0; j<n; j++){
			for(int h=0; h<n; h++){
				cout<<v[j][h]<<" ";
			}
			cout<<b[j];
			cout<<endl;
		}
		cout<<"-----"<<endl;
		
		for(int j=i+1; j<n; j++){
			double div=v[j][i]/v[i][i];
			for(int h=i; h<n; h++){
				v[j][h]-=div*v[i][h];
			}
			b[j]-=b[i]*div;
		}
	}
	
	double x[n];
	for(int i=n-1; i>=0; i--){
		double sum=0;
		
		for(int j=n-1; j>i; j--){
			sum+=x[j]*v[i][j];
		}
		
		x[i]=(b[i]-sum)/v[i][i];
	}
	cout<<"Answers: "<<endl;
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
		if(x[i]>intpas[i]+eps || x[i]<intpas[i]-eps){
			cout<<"<-error here "<<intpas[i]<<endl;
			break;
		}
	}
	cout<<endl;
	
}
void generate(){
	
	int MM=100,p=10,coef=10;
	
	for(int i=0; i<MM; i++)n=rand()%MM;
	
	vector<double> pas;
	
	for(int i=0; i<n; i++){
		int xux=1;
		for(int j=0; j<5; j++){
			xux=rand()%p;
		}
		pas.pb(xux);
		intpas.pb(xux);
	}
	mat.resize(n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n;  j++){
			int xux;int cc=2*coef;
			for(int h=0; h<5; h++){
				xux=rand()%cc;
			}
			if(xux==coef)xux++;
			mat[i].pb(xux-coef);
		}
	}
	
	for(int i=0; i<n; i++){
		int sum=0;
		
		for(int j=0; j<n; j++){
			sum+=mat[i][j]*pas[j];
		}
		
		bb.pb(sum);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<bb[i]<<endl;
	}
	cout<<"----"<<endl;
	
	cout<<"Intended answers:"<<endl;
	for(int i=0; i<n; i++){
		cout<<pas[i]<<" ";
	}
	cout<<endl<<"-----"<<endl;
}
int main(){

	cout<<setprecision(2)<<fixed;
	generate();
	
	vector<vector<double> > v(n);
	vector<double> b(n);	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			v[i].pb(mat[i][j]);
		}
	}
	
	for(double i=0; i<n; i++)b[i]=bb[i];
	
	solveNdim(v,n,b);
	
}
