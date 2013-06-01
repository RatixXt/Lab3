/**
\file code_list.cpp Реализация двусвязного списка 

@author Щербаков Алексей ИУ8-23
@brief Реализация двусвязного списка

*/

#include <iostream>
using namespace std;

///Класс элементов списка

class elem
{
public:
	float val;					///Значение элемента
	elem *prev;					///Указатель на предыдущий элемент
	elem *next;					///Указатель на следующий элемент
};

/// Класс список
class List
{
private:
	elem *first;					///Указатель на первый элемент списка
	elem *last;					///Указатель на последний элемент списка
	int size;					///Кол-во элементов списка
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


int List::getsize()	/// @function getsize - Функция получения кол-ва элементов 
{
	return size;
}


void List::add(float x, int z)	/// @function add - Функция добавления элемента на место с индексом i, входящих параметров - 2 @param x - Значение нового элемента @param i - индекс места *////
{
	elem *newelem=new elem;
	newelem->val=x;
	if (size==0)					/// Для пустого списка
	{
		newelem->prev= NULL;
		newelem->next= NULL;
		first=newelem;
		last=newelem;
	}

	else if (z==0)					///Добавить элемент в начало
	{
		newelem->prev=NULL;
		newelem->next=first;
		first->prev=newelem;
		first=newelem;
	}
	else if (z==size)				///Добавить элемент в конец
	{
		newelem->prev=last;
		newelem->next=NULL;
		last->next=newelem;
		last=newelem;
	}
	else						///Остальные случаи
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

void List::del(int z)	/// @function del - Функция удаления элемента с индексом i
{
	elem *curr=first;
	if((z==0)&&(z!=size-1))		///Если удаляется первый элемент, который не является единственным в списке
	{				
		curr->next->prev= NULL;
		first=first->next;
	}
	else if((z==size-1)&&(z!=0))	///Если удаляется последний элемент, который не является единственным в списке
	{
		curr=last;
		curr->prev->next=NULL; 
		last=last->prev;
	}
	else if ((z!=0)&&(z!=size-1))	///Если удаляется элемент, который не является ни первым, ни последним.
	{
		for(int i=0;i<z;i++)
			curr=curr->next;
	curr->prev->next=curr->next;
	curr->next->prev=curr->prev;
	}
	size--;
	delete curr;
}

float List::get(int z)	/// @get - Функция получения данных элемента с индексом i
{
	elem *curr=first;
	for(int i=0;i<z;i++)		///Нахождение элемента с индексом z
		curr=curr->next;
	return(curr->val);
}

/// @function main - Функция, которая является точкой входа в программу
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
		cin>>c;					///Переменная для выбора действия
		switch(c)
		{
		case 1:						///Добавление нового элемента
			{
				cout<<"Enter a value\n";
				cin>>val;			///Ввод поля данных нового элемента
				cout<<"Enter an index\n";
				cin>>num;			///Ввод индекса нового элемента
				if ((num<0)||(num>list.getsize())) cout<<"Incorrect index.\n"; ///Проверка корректности введённого индекса
				else list.add(val,num);		///Добавление элемента в список
				cout<<endl;
				break;
			}
		case 2:						///Удаление элемента
			{
				cout<<"Enter an index\n";
				cin>>num;			///Ввод индекса удаляемого элмента
				if ((num<0)||(num>=list.getsize())) cout<<"Incorrect index.\n"; ///Проверка корректности введённого индекса
				else list.del(num);		///Удаление элемента из списка
				cout<<endl;
				break;
			}
		case 3:						///Вывод на экран содержимого списка
			{
				cout<<"Elements: ";
				if (list.getsize()==0) cout<<"List is empty"; ///Сообщение, если список пуст
				else
				for(int i=0;i<list.getsize();i++)
					cout<<list.get(i)<<" ";	///Поэлементный вывод на экран
				cout<<endl<<endl;
				break;
			}
		case 4: Flag=false; break;			///Выход
		default: cout<<"Incorrect value.\n"; ///Некорректное действие
		}
	}
}