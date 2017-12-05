/*
  Sam Vernaza
  CS202
  Project_3
  External functions
*/

/*
  Implementation file for all of the external functions used in my program.
  That is all of the files used outside of the ADT.
*/

#include "ext_func.h"

/*
 getName:
	pre: expects a character entry from the user
	post: will have assigned an array to the variable name
*/
void getName(char *fileName)
{
  cout << "inside get name!" << endl;
	cout << "\nWhat's the name of your file? (remember .txt)\n";
	cin >> fileName;
	//cin.ignore(100, '\n');
	if(strlen(fileName) > 25)
	{
		while(strlen(fileName) > 25)
		{
			cout << "Invalid entry. Try again:";
      cin >> fileName;
			//cin.get(fileName, 25, '\n');
			cin.ignore(100, '\n');
		}
	}
}

/*
  myStrCpy:
    This will take two arrays/string literal whatever you want to call them.
    and copy each individual character from the source to the destination
    array. Just as the implementation for the standard c library does, this
    will return the beginning back to the calling routine.
*/
char *myStrCpy(char *dest, const char *src)
{
	char	*beg;

	beg = dest;
	while ((*dest++ = *src++))
          ;
  return (beg);
}

/*
  mystrcmp:
    My implementation of the strcmp function. Takes two constant strings passed
    into the function. The function then compares the value of the first funct
    so long as two conditions hold. The first string doesn't lose value.
    The second sting and the first string are equal. If there is a difference
    less than 0, 0, or greater than 0 as the standard in the C-library suggests.
*/
int	mystrcmp(const char *str1, const char *str2)
{
	while ((unsigned char)*str1 &&
		((unsigned char)*str1 == (unsigned char)*str2))
	{
		++str1;
		++str2;
	}
	return (*(unsigned char*)str1 - *(unsigned char*)str2);
}
