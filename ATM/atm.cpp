#include <iostream>
#include <fstream>
#include "main.h"


struct UserData 
{
	int user_id;
	string name;
	int pin;
	double account_balance;
};

// Comparator function for sorting UserData objects by name
bool compareByName(const UserData& a, const UserData& b) {
    return a.name < b.name;
}

// Binary search function to find a user by name
int binarySearch(const vector<UserData>& users, const string& target) {
    int left = 0;
    int right = users.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (users[mid].name == target) {
            return mid; // User found at index mid
        }
        else if (users[mid].name < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; // User not found
}

int main()
{
	std::cout<<"-------------------------------\n\t\tATM\n-------------------------------\n";
	std::cout<<"WELCOME!\n";
	std::fstream file("list.txt");
	if (!file.is_open())
	{
		std::err << "ERROR!" << std::endl;
		return 1;
	}

	vector<UserData> users;
	int user_id;
	string name;
	int pin;
	double account_balance;

	while (file >> user_id >> name >> pin >> account_balance)
	{
		users.push_back({user_id, name, pin, account_balance});
	}
	file.close();

	std::cout<< "Enter Username: ";
	std::cin >> name;
	int index = binarySearch(users, name);

	if (index != -1)
	{
		std::cout << "User ID: " << users[index].user_id << std::endl;
	}
	else
	{
		std::cout << "User not Found" << std::endl;
	}

	return (0);
}
