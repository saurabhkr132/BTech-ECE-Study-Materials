/*********************************************************************
 * main program for BFS/DFS Search on a graph specified in adjacency
 * list notation. Gets input and output file names from the user and
 * prints the traversals in the output file
 ********************************************************************/

#include "Graph.h"
#include "utils.h"

using namespace std;

int addEdges(Graph*, int, string&);


int main()
{
	ifstream iFile;
	ofstream oFile;

	string iFileName,oFileName,readLine;
	int i=0,j=0,nVertices,mEdges,testCases=0,totalEdges=0;
	int prematureEnd=0,foundError=0,failedTestCases=0;
	Graph *myG;

	cout << "Please enter the input file name: ";
	cin >> iFileName;
	cout << "Please enter the output file name: ";
	cin >> oFileName;

	iFile.open(iFileName.c_str(),ios::in);
	oFile.open(oFileName.c_str(),ios::out);

	if (!(iFile.is_open() && oFile.is_open())) // Validate file open
	{
		cout << "Error opening input / output file! " << endl;
		exit (-1);
	}

	while (!iFile.eof())
	{
		getline(iFile,readLine) ;
		// Checks first line for n,m 
		if ((readLine.find_last_of (',') != readLine.find_last_of (',')) ||
				(readLine.find_first_of (',') == string::npos ))
		{
			cout << "Incorrect file format! First line should be of the format n,m!" << endl;
			break;
		}
		myG = new Graph;
		testCases++;
		totalEdges=0;
		foundError=0;
		prematureEnd=0;
		nVertices=atoi((readLine.substr(0,readLine.find_first_of(','))).c_str()); //Get n (Before ,)
		mEdges=atoi((readLine.substr(readLine.find_first_of(',')+1)).c_str()); //Get m (After ,)
		oFile << "Test case " << testCases << " - Vertices: " << nVertices << " Edges: " << mEdges << endl;
		for(i=1;i<=nVertices;i++) // Read n adjacency lists for n nodes
		{
			getline(iFile,readLine);
			trimSpaces(readLine); //Trim leading and trailing spaces
			if (!isNumeric(readLine)) //Check if adjacency list contains invalid characters
			{
				if ((readLine.find("$")!=string::npos) || (readLine.find("$$")!=string::npos))
				{ // $ => End of test cases before n lines
					cout << "Premature end of test case " << testCases << "!!" << endl;
					oFile<< "Premature end of test case " << testCases << "!!" << endl;
					prematureEnd=1;
				}
				else
				{ // Other character => Invalid. Skip lines till next case (Till $ is seen)
					cout << "Adjacency lists should contain only numbers and spaces!! ";
					cout << "Found: " << readLine << " in test case " << testCases;
					cout << ". Skipping lines till next test case!" << endl;
					oFile << "Adjacency lists should contain only numbers and spaces!! ";
					oFile << "Found: " << readLine << " in test case " << testCases;
					oFile << ". Skipping lines till next test case!" << endl;
					while((readLine.find_first_of('$') == string::npos) || iFile.eof())
					{
						getline(iFile,readLine);
					}
					prematureEnd=1;
				}
				foundError=1;
				break;
			}
			myG->addMainNode(i); //Add a main node if all previous validations are okay
			totalEdges+=addEdges(myG,i,readLine); // Keep a count of number of edges
		}
		if ((totalEdges != mEdges) && (foundError==0))
		{
			cout << "Mismatch between number of edges specified and read for test case ";
			cout <<  testCases <<"!" << endl;
			cout << "\tExpected " << mEdges << " Found " << totalEdges << endl;
			oFile<< "Mismatch between number of edges specified and read for test case ";
			oFile<<  testCases <<"!" << endl;
			oFile<< "\tExpected " << mEdges << " Found " << totalEdges << endl;
			foundError=1;
		}
		if (prematureEnd==0) getline(iFile,readLine); //If premature end, $ was alread seen
		if ((readLine.find("$") == string::npos) && (readLine.find("$$") == string::npos))
		{ // After reading n adjacency lists, we should see a $ or $$. If not, report error
			cout << "Test case separator not found at expected line for test case ";
			cout << testCases << "! Check number of nodes and adjacency lists! ";
			cout << "Skipping lines till next test case! Found " << readLine << endl;
			oFile<< "Test case separator not found at expected line for test case ";
			oFile<< testCases << "! Check number of nodes and adjacency lists! ";
			oFile<< "Skipping lines till next test case! Found " << readLine << endl;
			while((readLine.find_first_of('$') == string::npos) && (!iFile.eof()))
			{
				getline(iFile,readLine);
			}
			foundError=1;
		}
		if (foundError == 0) // Process only if all validations were ok
		{
			oFile << "********* Starting BFS *********" << endl;
			myG->BFS(oFile);
			oFile << "**** Starting DFS Recursive ****" << endl;
			myG->DFSRecursive(oFile);
			oFile << "**** Starting DFS Iterative ****" << endl;
			myG->DFSIterative(oFile);
		}
		else
		{
			failedTestCases++;
		}
		oFile << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		delete myG;
		if ((readLine == "$$")||iFile.eof()) 
		{	
			cout << "End of test cases! Processed " << testCases << " cases. " << endl;
			cout << "Failed test cases: " << failedTestCases << endl; 
			oFile<< "End of test cases! Processed " << testCases << " cases. " << endl;
			oFile<< "Failed test cases: " << failedTestCases << endl;
			break;
		}
	}
	iFile.close();
	oFile.close();

	return 0;
}


int addEdges(Graph* myGraph, int mainNodeNum, string &readLine)
{
	int startPosition = 0, nextSpacePosition = 0, tempNodeVal=0, edgeCount=0;
	while(nextSpacePosition != string::npos)
	{
		if (readLine.length() == 0) break;
		nextSpacePosition = readLine.find(' ',startPosition);
		if (nextSpacePosition == string::npos)
		{
			//		cout << " Node: " << readLine.substr(startPosition) << endl;
			tempNodeVal=atoi((readLine.substr(startPosition)).c_str());
			myGraph->addAdjListNode(mainNodeNum,tempNodeVal);
			edgeCount++;
		}
		else
		{
			//		cout << " Node: " << readLine.substr(startPosition,nextSpacePosition) << endl;
			tempNodeVal=atoi((readLine.substr(startPosition,nextSpacePosition)).c_str());
			myGraph->addAdjListNode(mainNodeNum,tempNodeVal);
			edgeCount++;
		}
		startPosition = nextSpacePosition+1;

	} 
	return edgeCount;

}

