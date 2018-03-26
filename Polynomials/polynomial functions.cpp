#include<iostream>
#include<math.h>
#include<cmath>
#include<string>
#include"polynomial.h"
using namespace std;
Polynomial::Polynomial()
{
	start=NULL;
	end=NULL;
}
Polynomial::Polynomial(char * arr)
{
	start=NULL;
	end=NULL;
	node * current=NULL;
	current=start;
	int coeff=0;
	int  degree=0;
	int  count=0;
	int x= strlen(arr);
	char *a=new char[x];
	int l=0;
	for(int i=0;i<x;i++)
	{
		a[i]=arr[i];
		l=i+1;
	}
	a[l]='\0';
	for(int i=0;i<x;i++)
	{
		if(a[i]=='-' && i==0)
		{}
		else if(a[i]=='-' || a[i]=='+')
		{
			count++;
		}
	}
	char ** board;
	board=new char*[count+1];
	
	char * pnt=nullptr;
	char *pnt1=nullptr;
	char temp[100];
	char temp1[100];
	 pnt=strtok( a, "+" );
	 board[0]=pnt;
	for(int i=1;i<=count;i++)
	{
		pnt=strtok(NULL,"+");
		board[i]=pnt;
	}
	bool topi=false;
	bool flag=false;
	for(int i=0;i<=count;i++)
	{
			flag=false;
		for(int j=0;board[i][j]!='\0';j++)
		{
			if(board[i][j]=='^')
			{
				flag=true;
			}
		}
		for(int k=0;board[i][k]!='\0';k++)
		{
			
			if(board[i][k]=='x' && board[i][k+1]=='\0')
			{
				topi=true;
				break;
			}
		}
		
		if(flag==true)
		{
		coeff=atoi(strtok(board[i],"^"));
	    degree=atoi(strtok(NULL,""));
		node * newnode=new node;
		newnode->next=NULL;
		newnode->t.coeff=coeff;
		newnode->t.degree=degree;
		if(start==NULL)
		{
			start=newnode;
			end=newnode;
		}
		else
		 {
			end->next=newnode;
			end=newnode;
		
		 }
		}
		else
			if(flag==false)
			{
				coeff=atoi(board[i]);
				degree=0;
				node * newnode=new node;
				newnode->next=NULL;
				newnode->t.coeff=coeff;
				newnode->t.degree=degree;
				
				if(start==NULL)
				{
					start=newnode;
					end=newnode;
				}
				else
				{
					end->next=newnode;
					end=newnode;

				}
			}
			if(topi==true)
			{
				coeff=1;
				degree=1;
				node * newnode=new node;
				newnode->next=NULL;
				newnode->t.coeff=coeff;
				newnode->t.degree=degree;
				
				if(start==NULL)
				{
					start=newnode;
					end=newnode;
				}
				else
				{
					end->next=newnode;
					end=newnode;

				}
			}
						
		}
	
	/*current =start;
	while(current != NULL)
	{
		cout<<current->t.coeff<<endl;
		cout<<current->t.degree<<endl;
		current= current ->next;
	}*/
	
}
Polynomial Polynomial::operator*(const Polynomial & rightobject)
{
	Polynomial temp;
	node * current=NULL;
	current=start;
	node * current_node_of_right_object=NULL;
	current_node_of_right_object=rightobject.start;
	node * current_of_temp=NULL;
	while(current!=NULL)
	{
		current_node_of_right_object=rightobject.start;
		while (current_node_of_right_object!=NULL)
		{
			    node * newnode=new node;
				newnode->next=NULL;
				if(temp.start==NULL)
				{
					temp.start=newnode;
					temp.end=newnode;
				}
				else
				{
					temp.end->next=newnode;
					temp.end=newnode;
				}
				current_of_temp=temp.start;
				current_of_temp->t.coeff=(current->t.coeff*current_node_of_right_object->t.coeff);
				current_of_temp->t.degree=(current->t.degree+current_node_of_right_object->t.degree);
				current_node_of_right_object=current_node_of_right_object->next;
		}
		current=current->next;
	}
	cout<<temp;
	return temp;
}
Polynomial:: Polynomial(const Polynomial & otherobject)
{
	start=NULL;
	node *  newnode;
	node * current;
	if(start!=NULL)
	{
		node * temp=NULL;
			while(start!=NULL)
			{
				temp = start; 
				start = start->next;
				delete  temp; 
			}
			end = NULL;
	}
	if(otherobject.start==NULL)
	{
		start=NULL;
		end=NULL;
	}
	else
	{
		current=otherobject.start;
		start= new node;
		start->t.coeff=current->t.coeff;
		start->t.degree=current->t.degree;
		start->next=NULL;
		end=start;
		current=current->next;
	
	while (current!=NULL)
	{
		newnode=new node;
		newnode->t.coeff=current->t.coeff;
		newnode->t.degree=current->t.degree;
		newnode->next=NULL;
		end->next=newnode;
		end=newnode;
		current=current->next;
	}
  }
}	
const Polynomial & Polynomial:: operator=(const Polynomial & rightobject)
{
	start=NULL;
	node * newnode=NULL;
	node * current=NULL;
		if(start!=NULL)
		{
			node * temp;
			while(start!=NULL)
			{
				temp = start; 
				start = start->next;
				delete  temp; 
			}
			end = NULL; 
		}
		if(rightobject.start==NULL)
		{
			start=NULL;
			end=NULL;
		}
		else
		{
			current=rightobject.start;
			start=new node;
			start->t.coeff=current->t.coeff;
			start->t.degree=current->t.degree;
			start->next=NULL;
			end=start;
			current=current->next;

			while(current!=NULL)
			{
				newnode=new node;
				newnode->t.coeff=current->t.coeff;
				newnode->t.degree=current->t.degree;
				newnode->next=NULL;
				end->next=newnode;
				end = newnode;
				current=current->next;
			}
		
	   }
	return *this;
}
Polynomial Polynomial:: operator++()
{
	node * current=NULL;
	current = start;
	while(current != NULL)
	{
		if(current->t.degree==0)
		{
			current->t.coeff++;
		}
		current=current->next;
	}

	return *this;
}
Polynomial Polynomial::operator++(int a)
{
	Polynomial temp=*this;
	node * current=NULL;
    current=start;
	while(current != NULL)
	{
		if(current->t.degree==0)
		{
			current->t.coeff++;
		}
		current=current->next;
	}
	return temp;
}
Polynomial Polynomial::operator-()
{
	node * current=NULL;
	current= start;
	while(current != NULL)
	{
		current->t.coeff=current->t.coeff*-1;
		current=current->next;
	}
	return *this;

}
bool Polynomial::operator==(const Polynomial & rightobject)
{
	int lenght=0;
	int lenght1=0;
		bool flag = true;

	if(!start && !rightobject.start)return true;
	else if(!start && rightobject.start)return false;
	else if(start && !rightobject.start)return false;
	else
	{
		node * current =NULL;
		current=start;
		while (current!=NULL)
		{
			lenght++;
			current=current->next;
		}
		current=rightobject.start;
		while (current!=NULL)
		{
			lenght1++;
			current=current->next;
		}
		current=start;
		node * current1;
		current1=rightobject.start;
		while (current !=NULL || current1 !=NULL)
		{
			if(current->t.coeff==current1->t.coeff && current->t.degree==current1->t.degree)
			{
				current=current->next;
				current1=current1->next;
			}
			else
			{
				flag=false;
				current=current->next;
				current1=current1->next;
			}
		}
	}
	if(flag)
	{
		return true;
	}
	else if(!flag)
	{
		return false;
	}
}
int Polynomial::evaluate(int value)
{
	int sum=0;
	node * current=NULL;
	current = start;

	while(current != NULL)
	{
		current->t.degree=pow(value,current->t.degree);
		current=current->next;
	}
	current=start;
	while(current!=NULL)
	{
		current->t.coeff=current->t.coeff*current->t.degree;
		current=current->next;
	}
	current = start;
	while (current!=NULL)
	{
		sum=sum+current->t.coeff;
		current=current->next;
	}
	return sum;

}
Polynomial Polynomial::clear()
{
	node * temp;
	while (start!=NULL)
	{
		temp=start;
		start=start->next;
		delete temp;
	}
	end = NULL;
	return *this;
}
Polynomial Polynomial::derivate()
{
	node * current=NULL;
	current=start;
	while(current != NULL)
	{
		current->t.coeff=current->t.coeff*current->t.degree;
		current->t.degree=current->t.degree-1;
		current=current->next;
	}
	return * this;
}
Polynomial Polynomial::delete_negative_terms(int x)
{
	node * current=NULL;
	current=start;


	while(current != NULL)
	{
		current->t.degree=pow(x,current->t.degree);
		current=current->next;
	}
	current=start;
	while(current!=NULL)
	{
		current->t.coeff=current->t.coeff*current->t.degree;
		current=current->next;
	}
	current=start;
	node * q=NULL;
	q=current;
	while(current != NULL)
	{
		if(current->t.coeff<0)
		{
			q=current->next;
			current->next=q->next;
			delete q;
		}
		current=current->next;
	}
	return *this;
}
int Polynomial::maxima(int range1,int range2)
{	
	int maxima=0;
	int sum=0;
	int num=0;
	while(range1<range2)
	{
		node * current=NULL;
		current=start;
		int arr[1000]={0};
		int index=0;
		while(current !=NULL)
		{
			arr[index]=pow(range1,current->t.degree);
			current=current->next;
			index++;
		}
		index=0;
		current=start;
		while(current!=NULL)
		{
			arr[index]=current->t.coeff*arr[index];
			current=current->next;
			index++;
		}
		int k=0;
		while (k<index)
		{
			sum=sum+arr[k];
			k++;
		}
		if(sum>maxima)
		{
			maxima=sum;
			num=range1;
		}
		range1++;
	}
	return num;
}
int Polynomial::minima(int range1,int range2)
{
	int count=0;
	int minima=0;
	int sum=0;
	int num=0;
	while(range1<range2)
	{
		node * current=NULL;
		current=start;
		int arr[1000]={0};
		int index=0;
		while(current !=NULL)
		{
			arr[index]=pow(range1,current->t.degree);
			current=current->next;
			index++;
		}
		index=0;
		current=start;
		while(current!=NULL)
		{
			arr[index]=current->t.coeff*arr[index];
			current=current->next;
			index++;
		}
		int k=0;
		while (k<index)
		{
			sum=sum+arr[k];
			k++;
		}
		
		if(count==0)
		{
			minima=sum;
			num=range1;
			count++;
		}
		else if(sum<minima)
		{
			minima = sum;
			num = range1;
		}
		range1++;
	}
	return num;

}
//istream & operator>>(istream & in,Polynomial & obj)
//{
//	in.getline(obj.arr,1000,'\n');
//	return in;
//}
