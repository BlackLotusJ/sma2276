#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Book
{
	private:
		double price;
		int book_no, copies;
		string author, title;
	public:
		//prompt the user to insert details
		void insert()
		{
			cout<<"ENTER BOOK DETAILS:"<<endl;
			cout<<"Author:";
			getline(cin, author);
			cout<<"Title:";
			getline(cin, title);
			cout<<"Price:";
			cin>>price;
			cout<<"Number of Copies";
			cin>>copies;
		}

		//save the inserted details
		void save(const string& filename)
		{
			//open file for appending as csv
			ofstream file("inventory.txt", ios::app);
			if (file.is_open())
			{
				file <<title<<","<<author<<","<<price <<","<<copies<<endl;
				file.close();
			}
			else
			{
				cerr<< "Error opening file!"<<endl;
			}
		}

		//Display the inventory
		void display(const string& filename)
		{
			ifstream inputFile("inventory.txt");

			if (inputFile.is_open())
			{
				string line;
				while (getline(inputFile, line))
				{
					cout<<line<<endl;
				}
				inputFile.close();
			}
			else
			{
				cerr<< "Erorr opening file!"<<endl;
			}
		}

};

//Main Function
int main()
{
	string choice;
	Book myBook;

	cout<<"ENTER CHOICE:"<<endl;
	cout<<"1.Enter new book"<<endl;
	cout<<"2.Show Inventory"<<endl;
	getline(cin, choice);

	if (choice == "1")
	{
		myBook.insert();
		myBook.save("inventory.txt");
	}
	else if (choice == "2")
	{
		myBook.display("inventory.txt");
	}
	else
	{
		cout<<"Enter another number"<<endl;
	}

	return (0);
}
