#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

string searching(string nameBook)
{
	ifstream in_file("TextFile.txt");

	if (!in_file)
	{
		cerr << "Couldn't open the file" << endl;
		exit(1);
	}

	string line;
	string word;

	while (getline(in_file, line))
	{
		istringstream iss(line);
		iss >> word;
		if (iss && word == nameBook)
		{
			cout << "We have it in store" << endl;
		}
		else {
			cout << "Sorry, we don't a book with that namne" << endl;
		}
	}
}



int main()
{

	int book = 0;
	string names;
	char stop{};

	cout << "=======Welcome to Our ChatBot========" << endl;
	cout << "Hello This is Sajad's book store. please choose one of the options below to start the ChatBot" << endl;
	
	while(stop == 'q')
	{
		switch(book)
		{
			cout << "What kind of book are you looking for? " << endl;
			cout << "Romance - 1" << endl;
			cout << "Horror - 2" << endl;
			cout << "Comedy - 3\n" << endl;
			cout << "End Chat - 3\n" << endl;

			cout << "> ";
			cin >> book;

		case 1:
		{
			cout << "Name of the book ";
			cin >> names;
			searching(names);
			break;
		}
		case 2:
		{
			cout << "Name of the book ";
			cin >> names;
			searching(names);
			break;
		}
		case 3:
		{
			cout << "Name of the book ";
			cin >> names;
			searching(names);
			break;
		}
		case 'q':
		case 'Q':
		{
			stop = 'q';
			break;
		}
		default:
			cout << "Invalid Choice, please choose a correct option" << endl;
			break;
		}
	}
	
}