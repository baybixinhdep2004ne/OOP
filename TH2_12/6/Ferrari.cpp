#include<bits/stdc++.h>
using namespace std;
class Vehicles{
	protected:
	int speed;
	public:
		Vehicles(){
		}
		Vehicles(int speed){
			this->speed=speed;
		}
		
		virtual float maxSpeed()=0;
		void input(){
			cout<<"Nhap toc do: "; cin>>speed; cin.ignore();
		}
		void output(){
			cout<<speed<<"\t";
		}
};
class Ferrari: public Vehicles{
	string mausac;
	double heso;
	public:
		Ferrari():Vehicles(){
		}
		Ferrari(int speed, string mausac, double heso):Vehicles(speed){
			this->mausac=mausac;
			this->heso=heso;
		}
		void input(){
			Vehicles::input();
			cout<<"Nhap mau sac: "; getline(cin,mausac);
			cout<<"Nhap he so toc do: "; cin>>heso; cin.ignore();
		}
		void output(){
			Vehicles::output();
			cout<<mausac<<"\t"<<heso<<endl;
		}
		float maxSpeed(){
			return heso*speed;
		}
		friend bool operator >(Ferrari a, Ferrari b){
			return a.maxSpeed()> b.maxSpeed();
		}
};
int main(){
	int n;
	cout<<"Nhap sl Ferari: "; cin>>n; cin.ignore();
	Ferrari a[n];
	for(int i=0;i<n;i++){
		cout<<"\nNhap Ferari thu "<<i+1<<" la: "<<endl;
		a[i].input();
	}
	sort(a,a+n, greater<Ferrari>());
	a[0].output();
	
	return 0;
}
