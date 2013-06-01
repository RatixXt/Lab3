/**
\file code_list.cpp Реализация очереди с помощью циклического массива.

@author Щербаков Алексей ИУ8-23
@brief Реализация очереди с помощью циклического массива.
*/

#include <iostream>
using namespace std;

///Очередь
class Queue
{
	private:
	float arr[10];	///Массив, содержащий элементы очереди. 
	int first;	///Индекс первого элемента
	int last;	///Индекс последнего элемента
	public:
	int size;	///Кол-во элементов очереди
	Queue()	///Конструктор
	{
		for(int i=0;i<10;i++)
		arr[i]=0;
		first=0;
		last=0;
		size=0;
	}
	void push(float a);	///@function - Добавление нового элемента к конец очереди
	void pop();	/// @function - Удаление элемента из начала очереди
	float get();	/// @function - Получение первого элемента
	};

	void Queue::push(float a)
	{
		if (size!=0) last++;
		if (last==10) last=0;	///Если достигнут конец массива, он начинает заполняться с начала (если позволяет размер)
		arr[last]=a;	///Добавление элемента
		size++;
	}

	void Queue::pop()
	{
	arr[first]=0;	///Удаление (обнуление) элемента
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
	cout<<"Press button : 1 - add element; 2 - delete element; 3 - get the first element; 4 - exit.\n\n"; //Подсказка о возможных действиях
	while(Flag)
	{
		cout<<"Choose action: ";
		cin>>c;	
	switch(c)
	{
	case 1: ///Добавление нового элемента
		{
			cout<<"Enter a value\n";
			cin>>val;	///Ввод значения нового элемента
			Q.push(val);	///Добавление элемента в очередь
			cout<<endl;
			break;
		}

	case 2: ///Удаление элемента
	{
		if (Q.size==0) cout<<"You can't delete element: queue is empty\n"; ///Сообщение, если очередь пуста
		else Q.pop();	///Удаление элемента
		cout<<endl;
		break;
	}
	case 3: ///Вывод на экран первого элемента очереди
	{
		cout<<"The first element: ";
		if (Q.size==0) cout<<"Queue is empty"; ///Сообщение, если очередь пуста
		else cout<<Q.get();	///Вывод первого элемента
		cout<<endl<<endl;
		break;
	}
	case 4: Flag=false; break;	///Выход
	default: cout<<"Incorrect value.\n";	///Сообщение, если введено некорректное значение на этапе выбора действия
	}
	}
}