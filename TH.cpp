#include<bits/stdc++.h>
using namespace std;
class MH{
	private:
		string ma,ten;
		int stc;
	public:
		MH(){
		}
		string getma(){
			return ma;
		}
		void setma(string ma){
			this->ma;
		}
		void nhap(){
			cout<<"Nhap ma: "; getline(cin,ma);
			cout<<"Nhap ten: "; getline(cin,ten);
			cout<<"Nhap stc: "; cin>>stc; cin.ignore();
		}
		void xuat(){
			cout<<ma<<"\t"<<ten<<"\t"<<stc<<"\t";
		}
};
class TH: public MH{
	private:
		string kh;
	public:
		void nhap(){
			MH::nhap();
			cout<<"Nhap kieu hoc: "; getline(cin,kh);
		}
		void xuat(){
			MH::xuat();
			cout<<kh;
		}
		friend bool operator!=(TH a, TH b){
			if(a.getma()!=b.getma()){
				return false;
			}
			return true;
			
		}
};
int main(){
	int n;
	cout<<"nhap sl mon toan: "; cin>>n;cin.ignore();
	TH a[n];
	for(int i=0;i<n;i++){
		a[i].nhap();
	}
	TH b;
	cout<<"\nNhap dt can tim:"<<endl;
	b.nhap();
	bool check=false;
	for(int i=0;i<n;i++){
		if(a[i].getma()!=b.getma()){
			check = true;
		}
	}
	
	if(check=true){
		cout<<"Khong co trong ds";
	}
	else{
		cout<<"\nDa co trong ds"<<endl;
	}
	return 0;
}
