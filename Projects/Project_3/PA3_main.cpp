/*
  Sam Vernaza
  CS202
  Project_3
*/
#include "agency.h"

//prototypes
void greeting();
void displayMenu();

int main()
{
  int choice = 0;
  bool exit = true;
  char fileName[25];

  //assign agency pointer to the first rental
  Agency rentalAgency[3];
  Agency *agencyPtr = rentalAgency;

  Car rentalCar[5];
  //point the rental car ptr to the rental car array of inventory
  Car *rentalCar_ptr = (*agencyPtr).rentalCar;

  //introduction
  greeting();
  //display all of the options
  displayMenu();

  while(exit != false)
  {
    cin >> choice;

    switch(choice)
    {
      case 1:
        getName(fileName);
        int i = 0;
        while(i < 3)
        {
          //points to the first rentalAgency's SetAgency member
          //sends the first index of the rentalCar array for assigning
          //the values of the rentalCar array.
          agencyPtr->SetAgency(fileName, rentalCar_ptr, agencyPtr);
          //increment to the next agency when finished setting the first.
          ++agencyPtr;
          ++i;
        }

      //case 6:
        exit = false;
    }
    //ask for fileName
  }
  return 0;
}

void greeting()
{
  cout << "Hello! Welcome to the car rental program.\n";
  cout << "The purpose of this program is to assist in storing, searching\n";
  cout << " , and finding the best prices across all of our competitors.\n";
  cout << "Let's get started!" << endl;
  cout << endl << endl;
}

void displayMenu()
{
  cout << "Here is the list of available options for the program: \n";
  cout << "Car Rental Menu Options:\n";
  cout << "--------------------------\n";
  cout << "1. Read from a file\n";
  cout << "2. Display All.\n";
  cout << "3. Rental Cost\n";
  cout << "4. Highest Priced Rental\n";
  cout << "5. Print Available Inventory\n";
  cout << "6. Exit\n";

  cout << "Please input your choice!\n";
}
