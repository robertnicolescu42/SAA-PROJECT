#include <iostream>
using namespace std;

int st_size;

struct Task
{
	string name;
	int memory_use;
	int var_number;
	Task* next;

}*start = NULL;

void push(string _name, int _memory_use, int _var_number)
{
	Task* p = start;
	start = new Task;
	start->name = _name;
	start->memory_use = _memory_use;
	start->var_number = _var_number;

	start->next = p;
}

int pop(string _name, int &_memory_use, int &_var_number)
{
	if (start)
	{
		_name = start->name;
		_memory_use = start->memory_use;
		_var_number = start->var_number;
		/*
		cout << "name: " << _name;
		cout << "\nmemory use: " << _memory_use;
		cout << "\nvar number: " << _var_number;
		*/
		Task* t = start;
		start = start->next; 
		delete t;
		return 1;
	}
	else
		return 0;
}

void AddNode()
{
	cout << "--------------------------------------\n";
	st_size++;
	string name;
	int memory_use;
	int var_number;

	cout << "The name of the task is: ";
	cin >> name;

	cout << "The memory used by the task is: ";
	cin >> memory_use;

	cout << "The number of local variables is: ";
	cin >> var_number;

	push(name, memory_use, var_number);

	cout << "\nThe node was added successfully!\n";
	cout << "--------------------------------------";
}

void RemoveNode()
{
	cout << "--------------------------------------\n";
	if (start == NULL)
	{
		cout << "\nThe stack is empty !\n"; return;
	}

	st_size--;
	string name;
	int memory_use;
	int var_number;

	pop(name, memory_use, var_number);

	cout << "\nThe node was removed successfully!\n";
	cout << "--------------------------------------";
}


void Display()
{
	//trebuie sa numar cate noduri sunt si sa afisez toata stiva
	if (start == NULL)
	{
		cout << "\nThe stack is empty !\n"; return;
	}
	cout << "--------------------------------------";
	cout << "\nThe stack size is: " << st_size << endl;

	cout << "\nThe stack is: \n";
	while(start)
	{
		cout << "Name of the task: " << start->name << '\n';
		cout << "Used memory by the task: " << start->memory_use << '\n';
		cout << "Number of local variables: " << start->var_number << "\n\n";

		start = start->next;
	}
	cout << "--------------------------------------";
}

int main()
{
	int choice;
	while (1) {
		cout << "\nWhat do you want to do?\n";
		cout << "1. Add node\n";
		cout << "2. Remove node\n";
		cout << "3. Display the number of nodes and the stack\n";
		cout << "4. Exit\n";

		cout << "\nchoice = "; cin >> choice;

		switch (choice)
		{
		case 1: AddNode();
			break;
		case 2: RemoveNode();
			break;
		case 3: Display();
			break;
		case 4: return 0;
		default: return 0;
		}
	}
}