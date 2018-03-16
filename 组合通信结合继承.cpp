#include<iostream>
#include<vector>
using namespace std;
class Base{
	public:
       virtual void fun()=0;//子类有同种方法，基类声明虚接口实现多态 
}; 
class D1:public Base{
	public:
		void fun(){
			cout<<"D1"<<endl;
		}
};
class D2:public Base{
	public:
		void fun(){
			cout<<"D2"<<endl;
		}
};
class D3:public Base{
	public:
		D3():Base(){}
		void fun(){
			cout<<"D3"<<endl;
		}
};
class Fac{
//声明Fac类作为整体类 
	private:
		vector<Base *> vec;
	public:
		void Add(Base *t){
			vec.push_back(t);
		}
		void Out(){
			vector<Base *>::iterator it;
			for(it=vec.begin();it!=vec.end();it++)
			     (*it)->fun();
		}
};
int main(){
	Fac *f=new Fac();
	f->Add(new D1());
	f->Add(new D2());
    f->Add(new D3());
	f->Out();
}
