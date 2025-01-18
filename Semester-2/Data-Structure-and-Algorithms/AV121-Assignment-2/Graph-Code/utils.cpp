#include <string>
#include <iostream>
#include "utils.h"

bool isNumeric (string inString)
{
	for (int i=0; i< inString.length(); i++)
	{
		if ((inString[i]!=' ') && (!isdigit(inString[i])))
		{
			return false;
		}
	}
	return true;
}

void trimSpaces(string &inString)
{
	size_t startPos = inString.find_first_not_of(" \t");
	size_t endPos  = inString.find_last_not_of(" \t");
	if ((startPos == string::npos) || (endPos == string::npos))
	{
		inString = "";
	}
	else
	{
		inString = inString.substr(startPos,endPos-startPos+1);
	}
}

