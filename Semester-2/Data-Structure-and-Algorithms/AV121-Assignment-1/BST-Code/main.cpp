#include <iostream>
#include <stdlib.h>
#include "ui.h"
using namespace std;

int main()
{	
	int userOption=1;
	BST* myTree = new BST;

	while (userOption != 0)	
	{
		userOption = getUserOption();
		cout << endl << endl;
		processOption(userOption, myTree);
	}

	delete myTree;

	return 0;
}
