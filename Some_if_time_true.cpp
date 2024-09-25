#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;


FILE* read_file()
{
	const char* filename = "my_list.txt";
	FILE* file = fopen(filename, "r");
	if (!file)
	{
		perror("Файл не открылся\n");
		return nullptr;
	}
	else
	{
		cout << "Файл открылся\n";
	}
	return file;
}

void fulfill(FILE* file, string arr [][8])
{
	if (file == nullptr) return;

	char buffer[250];
	int row = 0;
	while (fgets(buffer, sizeof(buffer),file) && row<10)
	{
		char* token = strtok(buffer, "\t\n");
		int col = 0;
		while (token && col <8)
		{
			arr[row][col] = string(token);
			token = strtok(NULL, "\t\n");
			col++;
		}
		row++;
	}
}

void arr_output(string arr[][8])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

int main()
{
	setlocale(0, "");
	string arr[10][8] = {};
	FILE*file =	read_file();
	if (file)
	{
	fulfill(file, arr);
	arr_output(arr);
	fclose(file);
	}
}