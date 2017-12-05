/*
  Sam Vernaza
  CS202
  Project_3
*/

Car::Car()
{
  m_year = NULL;
  m_make = NULL;
  m_model = NULL;
  m_price = NULL;
  m_available = false;
}

//Create an explicit constructor

/*
  SetCar():
    Reads the data from an external data file and sets the value of the car
    object.
*/
bool Car::SetCar(ifstream &readFile)
{
  //if readFile is open, then read from the file and store the contents of
  //the car
  if(readFile)
  {
    char temp[20];
    char *tempPtr = temp;

    cout << "Reading the year" << endl;
    fileIn.get(temp, 20, ' ');
    //now assign the year to the year pointer
    //do I need a temp + 1 size of array?
    m_year = new int[strlen(temp)]
    int i = 0;
    while (i++ < strlen(temp))
      (*m_year++) = (*tempPtr++) - '0';

      //remember cout << dec << *pointer; to display decimal value of pointer
      //display pointers while incrementing *(ptr++)

    cout << "Reading the make" << endl;
    fileIn.get(temp, 20, ' ');
    fileIn.ignore(100, ' ');
    //now assign the read to the m_make array
    m_make = new char [strlen(temp) + 1];
    myStrCpy(m_make, temp);
    cout << "The value in make is now: " << m_make << endl;

    cout << "Reading the model" << endl;
    fileIn.get(temp, 20, ' ');
    fileIn.ignore(100, ' ');
    //now assign the read to the m_make array
    m_model = new char [strlen(temp) + 1];
    myStrCpy(m_model, temp);
    cout << "The value in model is now: " << m_model << endl;

    cout << "Reading the price" << endl;
    fileIn.get(temp, 20, ' ');
    //now assign the year to the year pointer
    int i = 0;
    while (i++ < strlen(temp))
      (*++) = (*tempPtr++) - '0';







  }

  else
    return false;

}
