// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


// This thing is a function mess, please don't hurt me coding Gods.
// also, far from finished, I wanted a lot of functionality for this.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <conio.h>
#include <tuple>
using namespace std;


vector<string> filepathToVector(const string& path);
bool writeToFile(string input);
void logVector(vector<string>& vec);
vector<tuple<string,string>> getFileNameAndPaths(const string& path);
void MENU_editNotebook();
vector<string> MENU_pickNotebook(const string& path);
void LogLineSplit();


int main()
{
	const string path = "C:\\Users\\Nikolai\\Documents\\MAIN\\programming\\apps\\C++\\todo_app\\todo_app\\notes\\";

	bool state = 1;
	while (1 == state)
	{
		vector<string> notebook = MENU_pickNotebook(path);

		cout << endl << endl;
		logVector(notebook);
		cout << endl << endl;

		MENU_editNotebook();

	}

	return 0;
}


void logVector(vector<string>& vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		cout << i << ": " << vec[i] << endl;
	}
}

// i'm returning each line in the .txt document as a string element in a vector
// each entry is one note
vector<string> filepathToVector(const string& path)
{
	vector<string> fileVector;
	string line;
	ifstream file(path);

	if (!file)
	{
		cout << "Failed to open file" << endl;
		return vector<string>();
	}

	while (getline(file, line))
	{
		fileVector.push_back(line);
	}
	file.close();

	return fileVector;
}

vector<tuple<string, string>> getFileNameAndPaths(const string& path)
{
	vector<tuple<string, string>> fileDetails;

	for (const auto& entry : filesystem::directory_iterator(path))
	{
		string fileNames = entry.path().filename().string();
		string filePath  = entry.path().string();
		fileDetails.push_back(make_tuple(fileNames, filePath));
	}
	return fileDetails;
}

bool createNotebook()
{
	return 0;
}


void pickNote(vector<string> notebook)
{
	// {"some text", "some more text", "and so on"}

	cout << " (1) edit  |  (2) Delete  |  (3) Go back " << endl;




}


bool deleteNotebook()
{
	return 0;
}

bool writeToFile(string input)
{
	return 0;
}

vector<string> MENU_pickNotebook(const string& path)
{
	vector<tuple<string, string>> fileNameAndPaths = getFileNameAndPaths(path);

	int i = 1;
	LogLineSplit();
	for (const auto& fileDetails : fileNameAndPaths)
	{
		cout << "#" << i++ << ": " << get<0>(fileDetails) << endl;
		LogLineSplit();
	}
	cout << endl << "Pick a notebook: ";

	char keyPressed{};
	keyPressed = _getch();

	string notebookPath = get<1>(fileNameAndPaths[(keyPressed - '0') - 1]);
	vector<string> notebook = filepathToVector(notebookPath);

	return notebook;
}

void MENU_editNotebook()
{
	cout << " (1) Pick note  |  (2) Rename notebook  |  (3) Delete notebook  |  (4) Go back  |  (0) Quit " << endl;
	cout << "Note: there can be no more than 9 notebooks" << endl;

	char keyPressed{};
	keyPressed = _getch();
}

void LogLineSplit()
{
	cout << "===============================================================" << endl;
}