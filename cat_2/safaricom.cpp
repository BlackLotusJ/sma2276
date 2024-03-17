#include <iostream>
#include <string>
using namespace std;

/*
 *Subscriber class
 * Stores subscriber name, phone number (with leading zero added in constructor), and airtime amount.
 */
class Subscriber
{
	private:
		string subscriber_name,phone_no;
		double airtime_amount;
		int bonus_points;
	public:
		Subscriber(const string &name, const string &phone_no, double airtime_amount)
			:name(name), phone_no("0" + phone_no), airtime() {}

		//compute_bonuspoints uses const to  indicate it does not modify the objects state
		int compute_bonuspoints() const
		{
			if (airtime_amount >= 2000.00)
				return (500);
			else if (airtime_amount >= 1000.00)
				return (300);
			else if (airtime_amount >= 500.00)
				return (100);
			else if (airtime_amount >= 100.00)
				return (50);
			else
				return (0);
		}

		/*Displays the reward message
		 * Uses 'const' since it does not modify the objects state but only outputs the data
		*/
		void displayMessage() const
		{
			int points = compute_bonuspoints();
			cout << name <<": (PHONE NO:" << phone_no"): AWARDED "<<points<<" BONGA POINTS. STAY WITH SAFARICOM. THE BETTER OPTION!" << endl;
		}

};

//Driver Code
int main()
{
	string name, phoneNumber;
	double airtime;
	
	cout << "Enter subscriber name: ";
	getline(cin, name);
	cout << "Enter phone number (without leading zero): ";
	getline(cin, phoneNumber);
	cout << "Enter airtime amount: ";
	cin >> airtime;
	
	Subscriber subscriber(name, phoneNumber, airtime);
	subscriber.displayRewardMessage();
	return (0);
}
