#include <iostream>

using namespace std;

void prnt(int* a, int* b, int* c);
int main()
{
	int a = 0, b = 5, c = 0;
	prnt(&a, &b, &c);
	cout << a << b << c << endl;
}
void prnt(x, y, z);
int* x, * y, * z;
{
	while (*x < *y)
	{
		++* x;
		*z = *z + *x;
		prnt(x, y, z);
	}
}
