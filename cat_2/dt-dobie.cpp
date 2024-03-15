#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Vehicle
{
	private:
		string model, make, engine_no;
		double sale_price;
		int profit;
	public:
		void setVehicle(double s, string mk, string mdl,string eng_no)
		{
			sale_price = s;
			make = mk; 
			model =mdl;
			engine_no = eng_no;
		}
		void getProfit(double sale_price)
		{
			profit = 0.15*sale_price;
			cout<< profit << endl;
		}

};

int main()
{
	double s, profit;
	string mk, mdl, eng_no;
	Vehicle myVehicle;

	cout<<"ENTER VEHCLE DETAILS"<<endl;
	cout<<"Make:"<<endl;
	getline(cin, mk);
	cout<<"Model:"<<endl;
	getline(cin, mdl);
	cout<<"Engine No:"<<endl;
	getline(cin, eng_no);
	cout<<"Sale Price:"<<endl;
	cin>>s;
	
	myVehicle.setVehicle(s,mk,mdl,eng_no);
	cout<<"The profit is: "<<endl;
	myVehicle.getProfit(s);

	return (0);
}
