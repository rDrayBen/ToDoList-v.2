#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "di.hpp"
namespace di = boost::di;
using namespace std;


class IToDoList {
protected:
	virtual void RemoveAllNotes() = 0;
	virtual vector <string> FindNotesWithWord(const string note_to_find) = 0;
	virtual void Show() = 0;
	virtual void RemoveOneNote(int your_choice) = 0;
};

class UncomplitedList : public IToDoList {
public:
	UncomplitedList(string pathForUncomplited) {
		this->pathForUncomplited = pathForUncomplited;
	}
	vector <string> FindUncomplitedResults;
	vector <string> saveUncomplitedNotes;


	void RemoveAllNotes() override;


	string AddNoteToUncomplited(string newnote);

	void Show() override;


	vector <string> FindNotesWithWord(const string note_to_find) override;


	vector <string> SaveAllUncomplitedNotes();


	void RemoveOneNote(int your_choice) override;
private:

	string pathForUncomplited;
};


class ComplitedList : public IToDoList {
public:
	ComplitedList(string pathForComplited) {
		this->pathForComplited = pathForComplited;
	}
	vector <string> FindComplitedResults;
	vector <string> saveComplitedNotes;


	void RemoveAllNotes() override;


	void AddNoteToComplited(int note_to_add, vector <string> savedUncomplitedNotes);

	void Show() override;


	vector <string> FindNotesWithWord(const string note_to_find) override;


	vector <string> SaveAllComplitedNotes();


	void RemoveOneNote(int your_choice) override;
private:

	string pathForComplited;
};


class ToDoList : public UncomplitedList, public ComplitedList {
public:
	ToDoList() : UncomplitedList(pathForUncomplited), ComplitedList(pathForComplited) {}


	void Print(int action);

private:

	string pathForUncomplited = "Notes for ToDoList(Uncompleted).txt";
	string pathForComplited = "Notes for ToDoList(Complited).txt";
};

class UI {
public:
	void SetCursorVisibility(bool show, short size);
	void SetCursorPosition(short x, short y);
	void SetActiveTextColor();
	void SetInactiveTextColor();
protected:
	short menu_size = 10;
	char Cursor;
};