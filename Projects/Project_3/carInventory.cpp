/*
  Sam Vernaza
  CS202
  Project_3
*/

#include "carInventory.h"
/*
  car:
    default constructor initializes the variables
*/
Car::Car()
{
  m_year = NULL;
  m_make = NULL;
  m_model = NULL;
  m_price = 0;
  m_available = false;
}

/*
  car:
    initializing parameter list for the constructor
*/
/*
Car::Car(int y, char *mak, char *mod, int p, bool a)
{
  m_year = y;

  myStrCpy(m_make, mak);
  myStrCpy(m_model, mod);
  m_price = p;
  m_available = a;
}
*/

/*
  setCar:
    Reads in the m_year, m_make, m_model, m_price, and availability of a car.
    This is read in from an external data file and stores the contents
    in the data members of the object.
*/
bool Car::SetCar(ifstream &fileIn)
{
  if(!fileIn)
  {
    cout << "The file isn't open!" << endl;
    return false;
  }

  if(fileIn)
  {
      //for reading in variables
      char temp_year[5];
      char temp_make[25];
      char temp_model[25];

      cout << "Setting year of this vehicle" << endl;
			   fileIn >> temp_year;
      fileIn.ignore(100 , '\n');

      cout << "Setting make of this vehicles" << endl;
      m_make = new char[25];
      fileIn.get(m_make, 25, ' ');
			//fileIn.ignore(100, '\n');

      cout << "Setting model of this vehicles" << endl;
      fileIn >> m_model;

      cout << "Setting price of this vehicle to rent" << endl;
      fileIn >> m_price;
      //fileIn.ignore(100, '\n');

      cout << "Setting availability" << endl;
      fileIn >> m_available;
      //fileIn.ignore(100, '\n');
      cout << endl << endl;

      cout << "\nRead for a single car is complete!" << endl;
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
