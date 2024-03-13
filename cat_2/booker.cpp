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
		void insert()
		{
			cout<<"ENTER BOOK DETAILS:"<<endl;
			cout<<"Author:"<<endl;
			getline(cin, author);
			cout<<"Title:";
			getline(cin, title);
			cout<<"Price:";
			cin>>price;
		}
		void save(const string& filename)
		{
			//open file for appending as csv
			ofstream file("inventory.txt", ios::app);
			if (file.is_open())
			{
				file << title << "," << author << "," << price << endl;
				file.close();
			}
			else
			{
				cerr<< "Error opening file!"<<endl;
			}
		}
};

//Main Function
int main()
{
	Book myBook;

	myBook.insert();
	myBook.save("inventory.txt");
	return (0);
}
