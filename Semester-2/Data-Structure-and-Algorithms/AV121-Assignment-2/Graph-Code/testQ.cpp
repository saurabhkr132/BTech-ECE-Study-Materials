#include <iostream>
#include <fstream>
#include "Q.h"
using namespace std;

int main()
{
	ifstream iFile;
	ofstream oFile;
	string iFileName,oFileName,readLine;
	char readVal[100];

	int i=0,j=0,adjacencyList[10][20][20],nVertices,mEdges;
	Q myQ;

	cout << "Please enter the input file name: ";
	cin >> iFileName;
	cout << "Please enter the output file name: ";
	cin >> oFileName;
	
	iFile.open(iFileName.c_str(),ios::in);
	oFile.open(oFileName.c_str(),ios::out);
	
	while (!iFile.eof())
	{
		getline(iFile,readLine) ;
		/*if ((readLine.find_first_of('\n') < readLine.find_first_of(',')) || 
		    (readLine.find_last_of (',') != readLine.find_last_of (',')) ||
		    (readLine.find_first_of (',') == string::npos ))
		{
			cout << "Incorrect file format! First line should be of the format n,m!" << endl;
			break;
		}*/
		
		nVertices = atoi(readLine.c_str());
		oFile << "This is a test!";
	//	for (i=0; i<nVertices; i++)
	//	{
	//		//cout << "Test" << endl;	
	//	}
		myQ.enQ(nVertices);
		//i++;
	}
	cout << "My Q is:" << endl;
	myQ.printQ();
	
	cout << "After deQing: " <<  myQ.deQ() << endl;
	cout << "New Q:" << endl;
	myQ.printQ();
	cout << "******************************" << endl;
	
	myQ.enQ(22);
	cout << "After enQing 22: " << endl;
	cout << "New Q:" << endl;
	myQ.printQ();
	cout << "******************************" << endl;
	
	cout << "After deQing: " <<  myQ.deQ() << endl;
	cout << "New Q:" << endl;
	myQ.printQ();
	cout << "******************************" << endl;
	
	cout << "After deQing: " <<  myQ.deQ() << endl;
	cout << "New Q:" << endl;
	myQ.printQ();
	cout << "******************************" << endl;


	return 0;
}
