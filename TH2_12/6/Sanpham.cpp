#include<bits/stdc++.h>
using namespace std;
class Sanpham{
	private:
		string ten,nsx;
	public:
		Sanpham(){
		}
		Sanpham(string ten, string nsx){
			this->ten=ten;
			this->nsx=nsx;
		}
		string getten(){
			return ten;
		}
		void setten(string ten){
			this->ten=ten;
		}
		string getnsx(){
			return nsx;
		}
		void setnsx(string nsx){
			this->nsx=nsx;
		}
		virtual	void nhap(){
			cout<<"Nhap ten: "; getline(cin,ten);
			cout<<"Nhap nsx: ";  getline(cin,nsx);
		}
		virtual	void xuat(){
			cout<<ten<<"\t"<<nsx<<"\t";
		}
		virtual float thanhtoan()=0;
};
class SPBanle: public Sanpham{
	private:
		float gia;
		int sl;
	public:
		SPBanle(){
		}
		SPBanle(string ten, string nsx, float gia, int sl):Sanpham(ten,nsx){
			this->gia=gia;
			this->sl=sl;
		}
		void nhap(){
			Sanpham::nhap();
			cout<<"Nhap gia ban le: "; cin>>gia; cin.ignore();
			do{
				cout<<"Nhap so luong(<10): "; cin>>sl; cin.ignore();
			}while(sl<0 || sl>=10);
		}
		void xuat(){
			Sanpham::xuat();
			cout<<gia<<"\t"<<sl<<endl;
		}
		float thanhtoan(){
			return gia*sl;
		}
};
class SPBansi: public Sanpham{
	private:
		float gia;
		int sl;
	public:
		SPBansi():Sanpham(){
		}
		SPBansi(string ten, string nsx, float gia, int sl):Sanpham(ten, nsx){
			this->gia=gia;
			this->sl=sl;
		}
		void nhap(){
			Sanpham::nhap();
			cout<<"Nhap gia ban si: "; cin>>gia; cin.ignore();
			do{
				cout<<"Nhap sl(>100) : "; cin>>sl; cin.ignore();
			}while(sl<=100);
		}
		void xuat(){
			Sanpham::xuat();
			cout<<gia<<"\t"<<sl<<endl;
		}
		float thanhtoan(){
			return gia*sl;
		}
};
int main(){
	int n ;
	do{
		cout<<"Nhap sl sam pham: "; cin>>n; cin.ignore();
	}while(n<=0 || n>=10);
	vector<Sanpham *> sp;
	for(int i=0;i<n;i++){
		cout<<"1.Ban le"<<endl;
		cout<<"2.Ban si"<<endl;
		int chose;
		do{
			cout<<"Nhap lua chon cua ban: "; cin>>chose; cin.ignore();
		}while(chose<1 || chose >2);
		switch (chose){
			case 1:
				Sanpham *a;
				a=new SPBanle;
				a->nhap();
				sp.push_back(a);
				break;
			case 2: 
				Sanpham *b;
				b=new SPBansi;
				b->nhap();
				sp.push_back(b);
				break;
			
		}
	}
	for(int i=0;i<sp.size();i++){
		sp[i]->xuat();
	}
	float tong=0;
	for(int i=0;i<sp.size();i++){
		tong+=sp[i]->thanhtoan();
		
	}
	cout<<"Tong tien phai thanh toan: "<<tong;
	return 0;
}
