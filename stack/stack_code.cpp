/**
\file stack_code.cpp ���������� ����� ��� ������ �������.

@author �������� ������� ��8-23
@brief ���������� ����� ��� ������ �������.
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int* stack = new int[5]; /// ������������ ������ �� 5 ���������
int sp = 0;


void stack_push(int num)	/// @functiom - �������� ������� � ����, 1 �������� �������� @param num ��������-�������� �������� �����
	{
		stack[sp] = num;
		sp++;
	}

int stack_pop() /// @function - ������� ������� �� �����
	{
		sp--;	
		return (stack[sp-1]);
	}

int stack_top () /// @function - ������� ������� ������� �����
	{
		return stack[sp-1];
	}
/// @function main  �������, ������� �������� ������ ����� � ���������
int main()
	{
		int c; bool Flag = true; int num = 0;
		while (Flag)
		{
			cout << "\nEnter the command for Stack: \n1) push\n2) pop\n3) top\n4) exit\n";
			cin >> c;
			switch(c) {
			case 1: /// �������� �������
				{
					cout <<"\tEnter the pushed value: ";
					
					cin >> num;
					stack_push(num);
					break;
				}
			case 2: /// ������� �������
				{
					cout << "Poped = " << stack_pop() << endl;
					break;
				}

			case 3:
				{
					cout << "Top = " << stack_top() << endl; /// ������� ������� �������
					break;
				}
			case 4: 
				{
					cout << "Finished!" << endl; Flag = false; break; ///�����
				}
			default: ///� ������ ��������� �����
				{
					cout<<"No such command"<< endl; break;
				}
			}
		}	
	return 0;
}