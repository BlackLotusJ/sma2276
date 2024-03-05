#include <iostream>
using namespace std;
//Progrma to find the maen of two numbers
class Stat
{
	private:
		int a, b, c;
	public:
		void set(int x, int y)
		{
			a = x;
			b = y;
		}
			
		void sum(int a, int b)
		{
			c = a + b;
			cout << "SUM =" << c << endl;
		}
};

int main()
{
	Stat st;
	st.sum(10, 20);
	return (0);
}
