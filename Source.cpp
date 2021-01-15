#include <iostream>
#include <fstream>
using namespace std;

class Plentie
{
private:
	int* elements = new int;
	int n;
public:

	Plentie ()
	{
	}

	Plentie(int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Введите элемент: ";
			cin >> elements[i];
		}
			
	}
	
	~Plentie()
	{
		delete[] elements;
	}

	friend ostream& operator << (ostream& os, const Plentie& result);

	friend Plentie operator^ (Plentie& left, Plentie& right);
};

ostream& operator << (ostream& os, const Plentie& result)
{
	for (int i = 0; i < result.n; i++)
		os << result.elements[i];
	return os;
}

Plentie operator^(Plentie& left, Plentie& right)
{
	int max;
	if (left.n > right.n)
		max = left.n;
	else
		max = right.n;

	Plentie result;
	for (int i = 0, k = 0; i < left.n; i++)
	{
		for (int j = 0; j < right.n; j++)
			if (left.elements[i] == right.elements[j])
			{
				result.elements[k] = left.elements[i];
				result.n++;
				k++;
			}
	}

	return result;		
}

void main()
{
	int n;
	
	Plentie a, b;
	cout << (a ^ b);
}