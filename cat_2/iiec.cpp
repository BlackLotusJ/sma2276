#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Voter class
class Voter
{
	private:
		string first_name, middle_name, surname, polling_stn, DOB;
		int voter_ID; 
		string national_ID;
	public:
		void insert()
		{
			cout << "Enter Name"<<endl;
			cout<<"First Name:";
			getline(cin, first_name);
			cout<<"\nMiddle Name:";
			getline(cin, middle_name);
			cout<<"\nSurname:";
			getline(cin, surname);
			cout<<"Date Of Birth: (dd-mm-yyyy)"<<endl;
			getline(cin, DOB);
			cout<<"National ID Number:";
			getline(cin, national_ID);
			cout<<"Polling Station\n";
			getline(cin, polling_stn);
		}

		void save(const string &filename)
		{
			ofstream file("voters.txt", ios::app);

			if (file.is_open())
			{
				file<< voter_ID<<"\t"<<surname<<","<<first_name<<" "<<middle_name<<"\t"<<national_ID<<"\t"<<polling_stn;
				file.close()
			}
			else
			{
				cerr<< "Error opening file!\n";
			}

		}

		static int getVoterID(const string &filename)
		{
			int highestID = 0;
			string line;
			ifstream inputFile("voters.txt");

			if (inputFile.is_open())
			{
				while(getline("voters.txt", line))
				{
					int currentID = stoi(line.subtr(0, line.find(",")));
					highestID = max(highestID, currentID);
				}
				inputFile.close();
			}
			return highestID+1;
		}

		void display(const string &filename)
		{
			
			string line;
			ifstream inputFile("voters.txt");
			
			if (inputFile.is_open())
			{
				while(getline(inputFile, line))
				{
					cout<<line<<endl:
				}
				inputFile.close();
			}
		}		
};

//Main 
int main ()
{
	int numVoters;
	string choice;

	cout<<"CHOOSE OPERATION:"<<endl;
	getline(cin, choice);

	cout<<"Enter the numebr of Voters\n";
	cin>>numVoters;

	if (choice = "1")
	{
		for (int i=0; i < numVoters; i++)
		{
			Voter myVoter;
			myVoter.insert();
			myVoter.save("voters.txt");
		}
	}
	else if (choice = "2")
	{
		myVoter.display("voters.txt");
	}
	else
	{
		cout<<"Enter the correct choice"<<endl;
	}
	return (0);
}
