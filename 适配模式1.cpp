#include<iostream>
using namespace std;
class Adaptee{
	public:
		void Adpteepro(){
			cout<<"Adaptee class"<<endl;
		}
};
class Adapter{
	private:
		Adaptee objAdaptee;//�Ӷ��� 
	public:
		void Adapterpro(){
			objAdaptee.Adpteepro();
		}
};
int main(){
	Adapter objAdapter;
	objAdapter.Adapterpro(); 
}
