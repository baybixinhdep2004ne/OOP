#include<bits/stdc++.h>
using namespace std;
class TLClass{
	string id;
	string name; 
	string description;
	string position; 
	public: 
	void input();
	void output(); 
	string getId1(); 
	string getName(); 
	string getDescription(); 
	string getPosition();
};
class TLStudent{
	string id;
	string name; 
	string address; 
	string description; 
	TLClass tlClass; 
	double note; 
	public :
	void output();
	void input();
	string getId();
	string getName();
	string getAddress();
	string getDescription();
	TLClass getClass();
	string getId1();
	double getNote();
};
void TLClass::input(){
	cout<<"Nhap ma lop: "; getline(cin,id);
	cout<<"Nhap ten lop: "; getline(cin,name);
	cout<<"Mo ta ve lop: "; getline(cin,description);
	cout<<"Vi tri lop: "; getline(cin,position);
}
void TLClass::output(){
	cout<<id<<"\t"<<name<<"\t"<<description<<"\t"<<position<<endl;
}
string TLClass::getId1(){
	return id;
}
string TLClass::getName(){
	return name;
}
string TLClass::getDescription(){
	return description;
}
string TLClass::getPosition(){
	return position;
}
void TLStudent::input(){
	cout<<"Nhap ma sv: ";cin.ignore(); getline(cin,id);
	cout<<"Nhap ten sv: "; getline(cin,name);
	cout<<"Nhap dia chi sv: "; getline(cin,address);
	cout<<"Mo ta sv: "; getline(cin,description);
	cout<<"Lop cua sv "<<endl; tlClass.input();
	cout<<"Nhap diem sv: "; cin>>note;
}
void TLStudent::output(){
	cout<<id<<"\t"<<name<<"\t"<<address<<"\t"<<description<<"\t"<<note<<"\t";
	tlClass.output();
}
string TLStudent::getId(){
	return id;
}
string TLStudent::getName(){
	return name;
}
string TLStudent::getAddress(){
	return address;
}
string TLStudent::getDescription(){
	return description;
}
TLClass TLStudent::getClass(){
	return tlClass;
}
string TLStudent::getId1(){
	return tlClass.getId1();
}
double TLStudent::getNote(){
	return note;
}

int main(){
	vector<TLStudent> sv;
	
	TLStudent a;
	
	while(1){
		cout<<"----------menu------------"<<endl;
		cout<<"1.Them sinh vien vao danh sach"<<endl;
		cout<<"2.Xoa sv khoi danh sach"<<endl;
		cout<<"3.Tim kiem sv theo ma "<<endl;
		cout<<"4.Liet ke sv"<<endl;
		cout<<"5.Tim kiem sv theo id cua lop"<<endl;
		cout<<"6.Liet ke sv co diem lon hon hoac bang 5 va so luong"<<endl;
		cout<<"7.Liet ke sv co diem duoi 5 va so luong"<<endl;
		cout<<"8.Liet ke danh sach sv co diem cao nhat va so luong"<<endl;
		cout<<"9.Thoat"<<endl;
		cout<<endl;
		int l;
		cout<<"Nhap lua chon cua ban:"; cin>>l;
		system("cls");
		switch(l){
		case 1:
			a.input();
			sv.push_back(a);
			break;
		case 2 :
			if(sv.empty()){
				cout<<"Khong co sinh vien trong ds"<<endl;
			}
			else{
				int i=0;
				string ma;
				cout<<"Nhap ma sv ban muon xoa: "; cin.ignore(); getline(cin,ma);
				while(i<sv.size()){
					if(ma==sv[i].getId()){
						sv.erase(sv.begin()+i);
					}
					else{
						i++;
					}
				//	sv[i].output();
				}
			}
			break;
		case 3:
			if(sv.empty()){
				cout<<"Khong co sinh vien trong ds"<<endl;
			}
			else{
				bool check= false;
				string tim;
				cout<<"Nhap ma sv ban muon tim: "; cin.ignore(); getline(cin,tim);
				for(int i=0;i<sv.size();i++){
					if(tim==sv[i].getId()){
						check=true;
						sv[i].output();
					}
					
				}
				if(!check){
					cout<<"Khong tim thay sv trong danh sach"<<endl;
				}
				
			}
			break;
		case 4:
			for(int i=0;i<sv.size();i++){
				sv[i].output();
			}
			break;
		case 5:
			if(sv.empty()){
				cout<<"Khong co sv trong ds"<<endl;
			}
			else{
				string id;
				cout<<"Nhap id lop ban muon tim: "; cin.ignore(); getline(cin,id);
				bool ktra=false;
				for(int i=0;i<sv.size();i++){
					if(id==sv[i].getId1()){
						ktra =true;
						sv[i].output();
					}
				}
				if(!ktra){
					cout<<"Khong tim thay sinh vien theo id lop"<<endl;
				}
			}
			break;	
		case 6:
			if(sv.empty()){
				cout<<"Khong co sv trong danh sach"<<endl;
			}
			else{
				int dem=0;
				cout<<"Danh sach sv co diem >=5 la: "<<endl;
				for(int i=0;i<sv.size();i++){
					if(sv[i].getNote()>=5.0 ){
						sv[i].output();
						dem++;
					}
				}
				cout<<"So luong sv co diem >=5: "<<dem<<endl;
			}
			break;
		case 7:
			if(sv.empty()){
				cout<<"Khong co sv trong danh sach"<<endl;
			}
			else{
				int dem1=0;
				cout<<"Danh sach sv co diem <5 la: "<<endl;
				for(int i=0;i<sv.size();i++){
					if(sv[i].getNote()<5.0 ){
						sv[i].output();
						dem1++;
					}
				}
				cout<<"So luong sv co diem <5: "<<dem1<<endl;
			}
			break;
		case 8:
			if(sv.empty()){
				cout<<"Khong co sv trong ds"<<endl;
			}
			else{
				float max=sv[0].getNote();
				int count=1;
				for(int i=1;i<sv.size();i++){
					if(sv[i].getNote()>max){
						max=sv[i].getNote();
					}
					else if( max==sv[i].getNote()){
						count++;
					}
				}
				for(int i=0;i<sv.size();i++){
					if(max==sv[i].getNote()){
					sv[i].output();
					}
				}
				cout<<"So luong sinh vien co diem cao nhat la:"<<count<<endl;		
			}
			break;
		case 9:
			cout<<"Ban muon thoat khoi chuong trinh"<<endl;
			cout<<"1.Thoat\n2.O lai"<<endl;
			int c;
			cout<<"Nhap lua chon:"; cin>>c;
			if(c==1){
				return 0;
			}			
		default:
			cout<<"Hay lua chon lai"<<endl;
		}
	}
	return 0;
}

