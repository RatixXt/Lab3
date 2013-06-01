/**
\file stack_code.cpp Реализация стека при помощи массива.

@author Щербаков Алексей ИУ8-23
@brief Реализация стека при помощи массива.
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int* stack = new int[5]; /// Динамический массив из 5 элементов
int sp = 0;


void stack_push(int num)	/// @functiom - Добавить элемент в стек, 1 входящий параметр @param num параметр-значение элемента стека
	{
		stack[sp] = num;
		sp++;
	}

int stack_pop() /// @function - Забрать элемент из стека
	{
		sp--;	
		return (stack[sp-1]);
	}

int stack_top () /// @function - Вывести верхний элемент стека
	{
		return stack[sp-1];
	}
/// @function main  Функция, которая является точкой входа в программу
int main()
	{
		int c; bool Flag = true; int num = 0;
		while (Flag)
		{
			cout << "\nEnter the command for Stack: \n1) push\n2) pop\n3) top\n4) exit\n";
			cin >> c;
			switch(c) {
			case 1: /// Добавить элемент
				{
					cout <<"\tEnter the pushed value: ";
					
					cin >> num;
					stack_push(num);
					break;
				}
			case 2: /// Удалить элемент
				{
					cout << "Poped = " << stack_pop() << endl;
					break;
				}

			case 3:
				{
					cout << "Top = " << stack_top() << endl; /// Вывести верхний элемент
					break;
				}
			case 4: 
				{
					cout << "Finished!" << endl; Flag = false; break; ///Выход
				}
			default: ///В случае неверного ввода
				{
					cout<<"No such command"<< endl; break;
				}
			}
		}	
	return 0;
}