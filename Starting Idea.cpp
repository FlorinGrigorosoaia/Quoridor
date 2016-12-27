#include <iostream>
using namespace std;

int main()
{
	char input = 'A';
	while (input != 'q') {
		cout << "Pentru a juca in doi apasati tasta t" << '\n';
		cout << "Pentru a iesi apasati tasta q" << '\n';
		cin >> input;
		if (input == 't')
			cout << "Ati ales sa jucati in 2" << '\n';
			// + functie 'play1vs1'
	}
}