#include <iostream>
#include <string>
#include <vector>
#include "FubctionsHeader.h"
#include <conio.h>
#include <Windows.h>
#include "di.hpp"


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

namespace di = boost::di;
using namespace std;

//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 


string Menu[] = {
	"Menu: ",
	"Add note",
	"Find note",
	"Remove one note",
	"Remove all notes",
	"Add note to complited",
	"Find note complited",
	"Remove note from complited",
	"Remove all complited",
	"Exit"
};


int main()
{
	ToDoList lst;
	UI user;
	system("color 01");
	user.SetCursorVisibility(false, 100);
	system("title ToDoList");

	short choise = 0;
	short menu_size = 10;

	/*Beep(400, 1000);*/

	while (true) {
		system("cls");

		cout << "Uncomplited tasks: " << endl;
		lst.Print(10);
		cout << "\n" << "===========================================" << "\n\n";

		cout << "Complited tasks: " << endl;
		lst.Print(11);
		cout << endl;

		
		int x = 80, y = 1;
		user.SetCursorPosition(x, y);
		for (int i = 0; i < menu_size; i++)
		{
			if (i == choise) user.SetActiveTextColor();
			else user.SetInactiveTextColor();

			user.SetCursorPosition(x, y++);
			cout << Menu[i] << endl;
		}
		char Cursor = _getch();
		if (Cursor == -32) Cursor = _getch();
		

		switch (Cursor) {
		case UP:
			if (choise>1) choise--;
			break;
		case DOWN:
			if (choise<menu_size-1) choise++;
			break;
		case ENTER: 
			if (choise == 9) return 0;
			system("cls");
			lst.Print(choise);
			system("pause");
		}

	}

	return 0;

}

/*

*/