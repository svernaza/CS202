/*
  Sam Vernaza
  CS202
  Project_3
*/
#include "agency.h"

/*
Agency::Agency()
{
}
*/
/*
  SetAgency:
    Takes the filename given and opens the ifstream for reading. This will
    sequentially read the names of the file and all car inventory. Storing the
    contents of the file into the struct members and objects of the car class.
*/
bool Agency::SetAgency(char *fileName, Car *rentalCar_ptr, Agency *agencyPtr)
{
  //recall that the agencyPtr is pointing to this members SetAgency()
  //meaning it has access to the all the members of this particular struct.
  //open a file to read from.
  ifstream fileIn;
	fileIn.open(fileName);

	if(fileIn)
	{
    //for accessing the SetCar function inside of the class.
    //need this at a later time to read in the rental car information.
		while(fileIn && !fileIn.eof())
		{
      //create a temporary zip array to read in the char zipcode
      //assign a tempzip pointer to access elements and for simple
      //assignment of the values.
      char tempZip[5];
      char *tempZip_ptr = tempZip;

      //point to the zipcode of the struct
      int *zipcode_ptr = agencyPtr->zipcode;

      int i = 0;
      while (i < 3)
      {
        //works
        cout << "What's the name of the agency?" << endl;
        fileIn >> name;
        //fileIn.ignore(100, ' ');

        //works
        cout << "What's the zipcode?" << endl;
        fileIn >> tempZip;
        cout << "Zipcode: " << tempZip << endl;
        fileIn.ignore(100, '\n');

        //assign the pointer to the front of the array.
        char *tempZip_ptr = tempZip;
        cout << *tempZip_ptr << endl;
        int k = 0;
        while (k < 5)
        {
          cout << "Value in tempZip_ptr is: " << *tempZip_ptr- '0' << endl;
          (*zipcode_ptr++) = (*tempZip_ptr++) - '0';
          ++k;
        }

        if(*zipcode_ptr <= 0)
          cout << "Didn't work!" << endl;
        cout << "Zipcode is now: " << *zipcode_ptr << endl;
        //needs to be fixed
  			int j = 0;
  			while(j < 5)
  			{
          //pointing to the first rental cars SetCar function
          //pass the current position of the object file
          rentalCar_ptr->SetCar(fileIn);
          //go to the next rentalCar SetCar function
          ++rentalCar_ptr;
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
