/**
\file code_list.cpp ���������� ������� � ������� ������������ �������.

@author �������� ������� ��8-23
@brief ���������� ������� � ������� ������������ �������.
*/

#include <iostream>
using namespace std;

///�������
class Queue
{
	private:
	float arr[10];	///������, ���������� �������� �������. 
	int first;	///������ ������� ��������
	int last;	///������ ���������� ��������
	public:
	int size;	///���-�� ��������� �������
	Queue()	///�����������
	{
		for(int i=0;i<10;i++)
		arr[i]=0;
		first=0;
		last=0;
		size=0;
	}
	void push(float a);	///@function - ���������� ������ �������� � ����� �������
	void pop();	/// @function - �������� �������� �� ������ �������
	float get();	/// @function - ��������� ������� ��������
	};

	void Queue::push(float a)
	{
		if (size!=0) last++;
		if (last==10) last=0;	///���� ��������� ����� �������, �� �������� ����������� � ������ (���� ��������� ������)
		arr[last]=a;	///���������� ��������
		size++;
	}

	void Queue::pop()
	{
	arr[first]=0;	///�������� (���������) ��������
	first++;
	if (first==10) first=0;
	size--;
	if(size==0) last=first;
	}

	float Queue::get()
	{
	return arr[first];
	}


	void main()
	{
	Queue Q;
	int c=0;
	float val=0;
	bool Flag=true;
	cout<<"Press button : 1 - add element; 2 - delete element; 3 - get the first element; 4 - exit.\n\n"; //��������� � ��������� ���������
	while(Flag)
	{
		cout<<"Choose action: ";
		cin>>c;	
	switch(c)
	{
	case 1: ///���������� ������ ��������
		{
			cout<<"Enter a value\n";
			cin>>val;	///���� �������� ������ ��������
			Q.push(val);	///���������� �������� � �������
			cout<<endl;
			break;
		}

	case 2: ///�������� ��������
	{
		if (Q.size==0) cout<<"You can't delete element: queue is empty\n"; ///���������, ���� ������� �����
		else Q.pop();	///�������� ��������
		cout<<endl;
		break;
	}
	case 3: ///����� �� ����� ������� �������� �������
	{
		cout<<"The first element: ";
		if (Q.size==0) cout<<"Queue is empty"; ///���������, ���� ������� �����
		else cout<<Q.get();	///����� ������� ��������
		cout<<endl<<endl;
		break;
	}
	case 4: Flag=false; break;	///�����
	default: cout<<"Incorrect value.\n";	///���������, ���� ������� ������������ �������� �� ����� ������ ��������
	}
	}
}