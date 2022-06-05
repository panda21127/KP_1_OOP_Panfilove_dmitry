#include <iostream>
#include <exception>
#include "Vector.h";
using namespace std;

int onlyNumbers()
{
	int a;
	cout << "Please input number" << endl;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		throw 1;
	}
	return a;
};

int main()
{
	using namespace std;
	int N;
	int flag = 0;
	while (flag == 0)
	{
		flag = 1;
		try
		{
			N = onlyNumbers();
		}
		catch (...)
		{
			cout << "Wrong" << endl;
			flag = 0;
		};
	}
	Vector <int> v1(N);
	for (int i = 0;i < N;i++)
	{
		cout << "Element number " << i + 1<<": ";
		cin >> v1[i];
	}
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	cout << v1 << endl;
	v1[1] = v1[0];
	cout << v1 << endl;
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.Delete(2);
	cout << v1 << endl;	
	v1[2] = v1.begin();
	v1[3] = v1.end();
	cout << v1.begin() << endl;
	cout << v1.end() << endl;
	cout << v1 << endl;
	v1.pop_back();
	cout << v1 << endl;

return 0;
}