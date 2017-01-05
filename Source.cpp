#include <iostream>
#include "Data Structures and Constants.h"
#include "Functions.h"

using namespace std;

int playingMode;

int main()
{
	initializeMovementArray( movementArray );
	cout << " Pentru a juca in modul vs CPU apasati '0' + ENTER : " << '\n';
	cout << " Pentru a juca in modul 1 vs 1 apasati '1' + ENTER : " << '\n';
	cout << " Pentru a juca in modul 2 vs 2 apasati '2' + ENTER : " << '\n';
	cin >> playingMode;

	if ( playingMode == 1 )
		play1vs1();
	return 0;
}
