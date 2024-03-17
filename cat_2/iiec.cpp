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
			cout << "Enter Voter's Details"<<endl;
			cout<<"First Name:"<<endl;
			getline(cin, first_name);
			cout<<"Middle Name:"<<endl;
			getline(cin, middle_name);
			cout<<"Surname:"<<endl;
			getline(cin, surname);
			cout<<"Date Of Birth: (dd-mm-yyyy)"<<endl;
			getline(cin, DOB);
			cout<<"National ID Number:";
			getline(cin, national_ID);
			cout<<"Polling Station\n";
			getline(cin, polling_stn);
		}

		void save(const string& filename)
		{
			ofstream file("voters.txt", ios::app);

			if (file.is_open())
			{
				file<<voter_ID<<"\t"<<national_ID<<"\t"<<surname<<","<<first_name<<" "<<middle_name<<"\t"<<DOB<<"\t"<<polling_stn;
				file.close();
			}
			else
			{
				cerr<< "Error opening file!\n";
			}

		}

		static int getVoterID(const string& filename)
		{
			int highestID = 0;
			string line;
			ifstream inputFile("voters.txt");

			if (inputFile.is_open())
			{
				while(getline(inputFile, line))
				{
					int currentID = stoi(line.substr(0, line.find(",")));
					highestID = max(highestID, currentID);
				}
				inputFile.close();
			}
			return highestID+1;
		}

		void display(const string& filename)
		{
			
			string line;
			ifstream inputFile("voters.txt");
			
			if (inputFile.is_open())
			{
				while(getline(inputFile, line))
				{
					cout<<line<<endl;
				}
				inputFile.close();
			}
		}		
};

//Main 
int main ()
{
	Voter myVoter;
	int numVoters;
	string choice;

	cout<<"CHOOSE OPERATION:"<<endl;
	cout<<"1.REGISTER NEW VOTER(S)\n2.DISPLAY LIST OF VOTERS\n";
	getline(cin, choice);

	cout<<"Enter the numebr of Voters\n";
	cin>>numVoters;

	if (choice == "1")
	{
		for (int i=0; i < numVoters; i++)
		{
			myVoter.insert();
			myVoter.save("voters.txt");
		}
	}
	else if (choice == "2")
	{
		myVoter.display("voters.txt");
	}
	else
	{
		cout<<"Enter the correct choice"<<endl;
	}
	return (0);
}
