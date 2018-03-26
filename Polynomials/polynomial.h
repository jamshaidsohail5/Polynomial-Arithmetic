#include<iostream>
using namespace std;
class Polynomial
{
private:
	//char arr[1000];

	struct term{
		int coeff;
		int degree;
	};
	struct node{
		term t;
		node * next;
	};
	node *start,*end;


public:
	
	
	Polynomial();
	//parametrized constructor
	Polynomial( char * str);
	
	// copy constructor
	Polynomial (const Polynomial & otherobject);
	
	//assignment operator
	const Polynomial & operator=(const Polynomial & rightobject);

	//operator "+"
	Polynomial operator+(const Polynomial & rightobject) ;

	//operator "-"
	Polynomial operator-(const Polynomial & rightobject);

	//operator "*"
	Polynomial operator*(const Polynomial & rightobject);

	//operator "=="
	bool operator==(const Polynomial & obj) ;

	//operator "<<"
	friend ostream & operator<<(ostream & out,const Polynomial & obj);

	//operator ">>"
	//friend istream & operator>>(istream & in,const Polynomial & obj);

	//operator pre-increment
	Polynomial operator++();

	//operator post-increment
	Polynomial operator++(int);

	//operator negation
	Polynomial operator-();
	//evaluate
	int evaluate(int);
	//clear
	Polynomial clear();
	//derivate
	Polynomial derivate();
	//delete negative terms
	Polynomial delete_negative_terms(int );
	//maxima
	int maxima(int,int);
	//minima
	int minima(int,int);
};
