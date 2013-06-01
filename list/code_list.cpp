/**
\file code_list.cpp ���������� ����������� ������ 

@author �������� ������� ��8-23
@brief ���������� ����������� ������

*/

#include <iostream>
using namespace std;

///����� ��������� ������

class elem
{
public:
	float val;					///�������� ��������
	elem *prev;					///��������� �� ���������� �������
	elem *next;					///��������� �� ��������� �������
};

/// ����� ������
class List
{
private:
	elem *first;					///��������� �� ������ ������� ������
	elem *last;					///��������� �� ��������� ������� ������
	int size;					///���-�� ��������� ������
public:
	List()						
	{
		first=NULL;
		last=NULL;
		size=0;
	}	
	int getsize();					
	void add(float x, int i);		
	void del(int i);				
	float get(int i);				
};


int List::getsize()	/// @function getsize - ������� ��������� ���-�� ��������� 
{
	return size;
}


void List::add(float x, int z)	/// @function add - ������� ���������� �������� �� ����� � �������� i, �������� ���������� - 2 @param x - �������� ������ �������� @param i - ������ ����� *////
{
	elem *newelem=new elem;
	newelem->val=x;
	if (size==0)					/// ��� ������� ������
	{
		newelem->prev= NULL;
		newelem->next= NULL;
		first=newelem;
		last=newelem;
	}

	else if (z==0)					///�������� ������� � ������
	{
		newelem->prev=NULL;
		newelem->next=first;
		first->prev=newelem;
		first=newelem;
	}
	else if (z==size)				///�������� ������� � �����
	{
		newelem->prev=last;
		newelem->next=NULL;
		last->next=newelem;
		last=newelem;
	}
	else						///��������� ������
	{
		elem *curr=first;
		for(int i=0;i<z;i++) 
			curr=curr->next;
		newelem->prev=curr->prev;
		newelem->next=curr;
		curr->prev->next=newelem;
		curr->prev=newelem;
	}
	size++;
}

void List::del(int z)	/// @function del - ������� �������� �������� � �������� i
{
	elem *curr=first;
	if((z==0)&&(z!=size-1))		///���� ��������� ������ �������, ������� �� �������� ������������ � ������
	{				
		curr->next->prev= NULL;
		first=first->next;
	}
	else if((z==size-1)&&(z!=0))	///���� ��������� ��������� �������, ������� �� �������� ������������ � ������
	{
		curr=last;
		curr->prev->next=NULL; 
		last=last->prev;
	}
	else if ((z!=0)&&(z!=size-1))	///���� ��������� �������, ������� �� �������� �� ������, �� ���������.
	{
		for(int i=0;i<z;i++)
			curr=curr->next;
	curr->prev->next=curr->next;
	curr->next->prev=curr->prev;
	}
	size--;
	delete curr;
}

float List::get(int z)	/// @get - ������� ��������� ������ �������� � �������� i
{
	elem *curr=first;
	for(int i=0;i<z;i++)		///���������� �������� � �������� z
		curr=curr->next;
	return(curr->val);
}

/// @function main - �������, ������� �������� ������ ����� � ���������
void main()
{
	List list;
	int c=0,num=0;
	float val=0;
	bool Flag=true;
	cout<<"Press button : 1 - add element; 2 - delete element; 3 - show all elements; 4 - exit.\n\n"; 
	while(Flag)
	{
		cout<<"Choose action: ";
		cin>>c;					///���������� ��� ������ ��������
		switch(c)
		{
		case 1:						///���������� ������ ��������
			{
				cout<<"Enter a value\n";
				cin>>val;			///���� ���� ������ ������ ��������
				cout<<"Enter an index\n";
				cin>>num;			///���� ������� ������ ��������
				if ((num<0)||(num>list.getsize())) cout<<"Incorrect index.\n"; ///�������� ������������ ��������� �������
				else list.add(val,num);		///���������� �������� � ������
				cout<<endl;
				break;
			}
		case 2:						///�������� ��������
			{
				cout<<"Enter an index\n";
				cin>>num;			///���� ������� ���������� �������
				if ((num<0)||(num>=list.getsize())) cout<<"Incorrect index.\n"; ///�������� ������������ ��������� �������
				else list.del(num);		///�������� �������� �� ������
				cout<<endl;
				break;
			}
		case 3:						///����� �� ����� ����������� ������
			{
				cout<<"Elements: ";
				if (list.getsize()==0) cout<<"List is empty"; ///���������, ���� ������ ����
				else
				for(int i=0;i<list.getsize();i++)
					cout<<list.get(i)<<" ";	///������������ ����� �� �����
				cout<<endl<<endl;
				break;
			}
		case 4: Flag=false; break;			///�����
		default: cout<<"Incorrect value.\n"; ///������������ ��������
		}
	}
}