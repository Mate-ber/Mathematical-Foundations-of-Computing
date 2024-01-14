#include<bits/stdc++.h>
#include<chrono>
#define pb push_back
#define double long double
using namespace std;
int n;
const double eps=1e-3;
vector<vector<double> > mat(1000);
vector<double> bb;
vector<double> intpas;
void solveNdim(vector<vector<double> > &v, int n, vector<double> &b){
	
	for(int i=0; i<n; i++){
		if(v[i][i]==0){
			for(int j=i+1; j<n; j++){
				if(v[j][i]){
					swap(v[i],v[j]);
					swap(b[i],b[j]);
					break;
				}
			}
		}
		
//		for(int j=0; j<n; j++){
//			for(int h=0; h<n; h++){
//				cout<<v[j][h]<<" ";
//			}
//			cout<<b[j];
//			cout<<endl;
//		}
//		cout<<"-----"<<endl;
		
		for(int j=i+1; j<n; j++){
//			if(!v[i][i]){
//				cout<<"Invalid Matrix"<<endl;
//				return;
//			}
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
	
//	cout<<"Answers: "<<endl;
//	for(int i=0; i<n; i++){
//		cout<<x[i]<<" ";
//	}
//	cout<<endl;
	bool cor=true;
	if(!intpas.empty()){
		double sum_error=0.0;
		for(int i=0; i<n; i++){
//			if(fabs(x[i]-intpas[i])>eps){
//				cout<<x[i]<<"<-error here "<<intpas[i]<<endl;
//				cor=false;
//			}
			sum_error+=fabs(intpas[i]-x[i]);
		}
	//	cout<<endl;
		
		
//		if(!cor){
//			cout<<"Not correct"<<endl;
//		}
//		else{
//			cout<<"Correct"<<endl;
//		}
//		cout<<"Sum of error: "<<sum_error<<endl;
//		cout<<setprecision(18)<<fixed;
//		cout<<n<<" "<<sum_error<<endl;
		return;
	}
	
	vector<double> error;
	for(int i=0; i<n; i++){
		double k=bb[i];
		for(int j=0; j<n; j++){
			k-=x[j]*mat[i][j];
		}
		error.pb(k);
	}
	
	double sum_error=0.0;
	for(auto x:error){
		sum_error+=fabs(x);
	}
//	cout<<setprecision(18)<<fixed;
//	cout<<n<<" "<<sum_error<<endl;
	
}
void generate(){
	
	int MM=100,p=5,coef=10;
	
//	for(int i=0; i<MM; i++)n=rand()%MM;
//	n=10;
	vector<double> pas;
	intpas.clear();
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
		mat[i].clear();
	}
	bool hilbert=false;
	if(!hilbert){
		for(int i=0; i<n; i++){
			for(int j=0; j<n;  j++){
				double xux;int cc=2*coef;
				for(int h=0; h<5; h++){
					xux=rand()%cc;
				}
				mat[i].pb(xux-coef);
			}
		}
	}
	else{
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				double xux=i+j+2.0;
				xux=1/xux;
				mat[i].pb(xux);
			}
		}	
	}
	bb.clear();
	for(int i=0; i<n; i++){
		double sum=0;
		for(int j=0; j<n; j++){
			sum+=mat[i][j]*pas[j];
		}
		
		bb.pb(sum);
	}
	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			cout<<mat[i][j]<<" ";
//		}
//		cout<<bb[i]<<endl;
//	}
//	cout<<"----"<<endl;
//	
//	cout<<"Intended answers:"<<endl;
//	for(int i=0; i<n; i++){
//		cout<<pas[i]<<" ";
//	}
//	cout<<endl<<"-----"<<endl;
}
int main(){

	cout<<setprecision(9)<<fixed;
	
	
//	generate();
//	if(n==0){
//		cin>>n;
//		mat.resize(n);
//		for(int i=0; i<n; i++){
//			for(int j=0; j<n; j++){
//				int x;
//				cin>>x;
//				mat[i].pb(x);
//			}
//		}
//		for(int i=0; i<n; i++){
//			int x;
//			cin>>x;
//			bb.pb(x);
//		}
//		
//	}

//    ofstream cout;
//    cout.open("data1.txt");
	for(int z=1; z<1000; z++){
		n=z;
		generate();
		vector<vector<double> > v(n);
		vector<double> b(n);	
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				v[i].pb(mat[i][j]);
			}
		}
		
		for(double i=0; i<n; i++)b[i]=bb[i];

	
		auto start_time = std::chrono::high_resolution_clock::now();
		solveNdim(v,n,b);
   		auto end_time = std::chrono::high_resolution_clock::now();
   		auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);	
   		double time=(double)(elapsed_time.count())/1000.0;
   		cout<<n<<" "<<time<<endl;
	}
	
	
    
}
