#include<iostream>
using namespace std;
class Adaptee{
	public:
		void method(){
			cout<<"Adaptee"<<endl;
		}
};
class AdaptorBase{
	public:
		virtual void method()=0;
}; 
class AdaptorA:public AdaptorBase{
	public:
		void method(){
			cout<<"AdaptorA"<<endl;
		}
}; 
class AdaptorB:public AdaptorBase{
	private:Adaptee *ad; 
	public:
		AdaptorB(){
			ad=new Adaptee();
		} 
		void method(){
			cout<<"AdaptorB"<<endl; 
			ad->method();//调用Adaptee类中的method方法 
		}
		~AdaptorB(){
			delete ad;
		}
};
class AdaptorC:public AdaptorBase{
	public:
		void method(){
			cout<<"AdaptorC"<<endl;
		}
};
int main(){
	AdaptorBase *pbase=new  AdaptorB();
	pbase->method();
	delete pbase;
}
