#include<stdio.h>
#include<iostream>
using namespace std;
class Base{
	protected:
		Base *next;
	public:
		Base(){}
		Base(Base *t){
			next=t;
		}
		virtual void fun()=0;//������ӿ�ʵ�ֶ�̬
		virtual ~Base(){
			cout<<"ʵ����ӿ�"<<endl;
		}
};
class ProductA:public Base{
	public:
		ProductA(Base *t):Base(t){}
		void fun(){
			cout<<"ProoductA"<<endl;
			if(next)
			next->fun();//���ø��ӹ���A��fun���� 
		}
}; 
class Decorator:public Base{
	public:
		Decorator(Base *t):Base(t){} 
        virtual void fun()=0;//��֤Decorator���麯�������ô�������ͬʱҲ���ּ̳���ϵ�������� 
        virtual ~Decorator(){
        	cout<<"ִ�и��ӹ�����ӿ�"<<endl; 
		}
};
class DecoratorA:public Decorator{
	public:
	DecratorA(){}
	DecoratorA(Base *t):Decorator(t){}
	void fun(){
		cout<<"DecoratorA"<<endl;
		if(next)
		next->fun();//���ø��ӹ���B��fun���� 
	}
	~DecoratorA(){
		cout<<"����DecoratorA����������"<<endl;	 
	}
};
class DecoratorB:public Decorator{
	public:
	DecoratorB(Base* t):Decorator(t){} 
	void fun(){
		cout<<"DecoratorB"<<endl;
		if(next)
		next->fun();
	}
};
int main(){
    DecoratorB* pdb=new DecoratorB(NULL);
	DecoratorA* pda=new DecoratorA(pdb);
	Base *base=new ProductA(pda);
	base->fun(); 
}

