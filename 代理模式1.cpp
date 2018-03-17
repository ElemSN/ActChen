#include<iostream>
using namespace std;
class Base{
	public:
		virtual void method()=0;
}; 
class proxy:public Base{
//代理方 
	private:
		Base *base;
	public:
		proxy(Base *t){
			base=t;
		}
	    void method(){
	    	cout<<"proxy"<<endl;
	    	base->method();//base指向客户端传来的地址 
		} 
		~proxy(){
			delete base;
		}
};
class source:public Base{
	public:
		void method(){
			cout<<"source"<<endl;
		}
};
int main(){
	Base *b=new proxy(new source());
	b->method();
}
