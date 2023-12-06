#include<bits/stdc++.h>
using namespace std;
class Point{
	float x,y;
	public:
		Point(){
		}
		~Point(){
		}
		friend istream &operator >>(istream &in, Point &a);
		friend ostream &operator <<(ostream &out, Point a);
		friend float operator+(Point a, Point b);
};
istream &operator >>(istream &in, Point &a){
	cout<<"Nhap x: "; cin>>a.x;
	cout<<"Nhap y: "; cin>>a.y;
	return in;
}
ostream &operator <<(ostream &out, Point a){
	cout<<"("<<a.x<<","<<a.y<<")"<<endl;
	return out;
}
float operator+(Point a, Point b){
	float kq=sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
	return kq;
}
class Dagiac{
	Point a[100];
	int size;
	public:
		Dagiac(){
		}
		~Dagiac(){
		}
		friend istream &operator >>(istream &in, Dagiac &a);
		friend ostream &operator <<(ostream &out, Dagiac a);
		friend  bool ktra(Dagiac a);
};
istream &operator >>(istream &in, Dagiac &b ){//ham
cout<<"Nhap so diem: "; in>>b.size;
 for (int i = 0; i < b.size; i++) {
		cout << "Nhap diem thu " << i + 1 << ":" << endl;
		in >> b.a[i];//a[i] co dang la point khi nap chong in thi nos goi in tu point
	}
	return in;
}
ostream &operator <<(ostream &out, Dagiac a){
	for(int i=0;i<a.size;i++){
		out<<a.a[i];
	}
}

bool ktra(Dagiac d ){
 	if(d.size==3){
 		float AB=d.a[0]+ d.a[1]; 
		float BC= d.a[1]+d.a[2];
		float AC=d.a[2]+d.a[0]; 
		if(AB+AC>BC && AB+BC>AC && BC+AC>AB){
			return true;
		}
		
	 }
	 return false;
	
}
int main(){
	int n;
	cout<<"Nhap so da giac: "; cin>>n;
	Dagiac a[n];
	for(int i=0;i<n;i++){
		cout<<"Nhap da giac thu "<<i+1<<":"<<endl;
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cout<<"Diem cua da giac: "<<i+1<<endl;
		cout<<a[i];
	}
	for(int i=0;i<n;i++){
		cout<<"Da giac thu "<<i+1<<" ";
		if(ktra(a[i])){
			cout<<"la tam giac"<<endl;
		}
		else{
			cout<<"k phai tam giac"<<endl;
		}
	}
	return 0;
}
