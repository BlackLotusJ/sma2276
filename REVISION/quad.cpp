#include <iostream>
#include <cmath>
using namespace std;
//program to find the roots of a polynomial of degree 2
class Quad
{
	private:
		float a, b, c, x1, x2, discr, real ,img;
	public:
	void get(float a, float b, float c)
	{
		cout<<"Enter a: "<<endl;
		cin>>a;
		cout<<"Enter b: "<<endl;
		cin>>b;
		cout<<"Enter c: "<<endl;
		cin>>c;
	}
	void eval(float a, float b, float c)
	{
		discr = ((b*b) - 4*a*c);

		if (discr > 0)
		{
			x1 = (-b + sqrt(discr))/(2*a);
			x2 = (-b - sqrt(discr))/(2*a);
			cout<< "The roots are real and distinct"<< endl;
			cout<< "x1= " << x1 << endl;
			cout<< "x2= " << x2 << endl;
		}
		else if (discr == 0)
		{
			cout << "Roots are real and same" << endl;
			x1 = -b/(2*a);
			cout<< "x1 = x2 = "<< x1 << endl;
		}
		else
		{
			real = -b/(2*a);
			img = sqrt(-discr)/(2*a);
			cout << "Root are complex and distinct"<< endl;
			cout << "x1 ="<< real << "+" << img<< "i" <<endl;
			cout << "x2 ="<< real << "-" << img << "i" << endl;
		}
	}
};

int main()
{
	float a, b, c;
	Quad q;
	q.get(a, b, c);
	q.eval(a, b, c);
	return (0);
}


