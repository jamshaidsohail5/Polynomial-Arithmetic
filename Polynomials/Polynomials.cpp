#include<iostream>
#include"polynomial.h"
#include<stdio.h>
using namespace std;

ostream & operator<<(ostream & out,const Polynomial & obj)
{
	Polynomial::node * current=NULL;
	current=obj.start;
	while (current!=NULL)
	{
		cout<<"Coefficient = "<<endl;
		out<<current->t.coeff<<endl;
		cout<<"Degree = "<<endl;
		out<<current->t.degree<<endl;
		current=current->next;
	}
	return out;
}

int main()
{
	Polynomial a("3x^2+2x^1+4");
	Polynomial b("-2x^2+10");
	cout<<b++<<endl;
	cout<<++b<<endl;
	
	
	//cout<<c<<endl;
	
	system("pause");
	return 0;
}
