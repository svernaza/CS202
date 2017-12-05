/*
  Sam Vernaza
  CS202
  Project_3
*/

/*
  rentalAgency.cpp:
    This is the implementation file for the struct.
*/

#include "rentalAgency.h"

/*
  getAgency:
    Takes the filename given and opens the ifstream for reading. This will
    sequentially read the names of the file and all car inventory. Storing the
    contents of the file into the struct members and objects of the car class.
*/
void setAgency(char *fileName)
{
  ifstream fileIn;
	fileIn.open(fileName);

	if(fileIn)
	{
		while(fileIn && !fileIn.eof())
		{
      int i = 0;
      while (i < AGENCY_MAX)
      {
        cout << "What's the name of the agency?" << endl;
        fileIn >> rentalAgency_ptr[i]->name;
        //fileIn.ignore(100, ' ');

        cout << "What's the zipcode?" << endl;
        fileIn >> rentalAgency_ptr[i]->zipcode;
        //fileIn.ignore(100, '\n');

  			int j = 0;
  			while(j < 5)
  			{
          fileIn >> rentalAgency_ptr[i]->inventory[j].getCar(fileIn);
  				++j;
  			}
        ++i;
      }
		}
    cout << "\nRead complete!" << endl;
    fileIn.clear();
    fileIn.close();
    return true;
	}
	else
  {
		cout << "\nCouldn't open file!" << endl;
    fileIn.clear();
    fileIn.close();
    return false;
  }
}

bool getAgency(rentalAgency_ptr &agency, char *agencyName);
/*
void setZip();
bool getZip(rentalAgency_ptr &agency, int zipcode);
void setInventory();
bool getInventory(rentalAgency_ptr &agency);
*/
