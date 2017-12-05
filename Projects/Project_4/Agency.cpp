#include "Agency.h"

//default constructor for the class Agency
Agency::Agency()
{
  m_name = NULL;
  m_zip = 0;
}

/*
  ReadAllData:
    The purpose of this function is to instantiate all of the reads from
    a file. This will store all of the data from the file into its proper
    variable values. This will kind of act like a one stop shop while invoking
    many different functions while reading.
*/
bool Agency::ReadAllData(const char *fileName)
{
  ifstream fileReaderOpen;
  fileReaderOpen.open(fileName);

  cout << "File Opened" << endl;
  if(fileReaderOpen && !fileReaderOpen.eof())
  {
	  int i = 0;
    char temp[5];
    fileReaderOpen.get(temp, MAX_CHAR_SIZE, ' ');
    cout << "Read File" << endl;
    //fileReaderOpen >> temp;
    if(!SetName(temp))
      return false;

    //change to my implementation
    char tempZip [5];
    fileReaderOpen >> tempZip;
    m_zip = atoi(tempZip);

    cout << "converted tempZip" << endl;
    Car *inventory_p = m_inventory;
    while(!fileReaderOpen.eof() && inventory_p != NULL)
    {
        //read in the year
      fileReaderOpen >> temp;
      if(!inventory_p->SetYear(atoi(temp)))
        return false;

      cout << "Passed SetYear" << endl;
      //read in the make
      fileReaderOpen >> temp;
      if(!inventory_p->SetMake(temp))
        return false;

      //read in the model
      fileReaderOpen >> temp;
      if(!inventory_p->SetModel(temp))
        return false;

        cout << "Passed SetModel" << endl;
      //read in the base price
      //explicit type cast after conversion to int
      fileReaderOpen >> temp;
      float f = atof(temp);
      if(!inventory_p->SetBasePrice(f))
        return false;

      cout << "Passed SetBasePrice" << endl;
      //read in sensor as is, the set sensor function will take care of
      //the brackets entered
      fileReaderOpen >> temp;
      if(!inventory_p->SetSensor(temp))
        return false;

      cout << "Passed SetSensor" << endl;

      bool result = false;
      fileReaderOpen >> temp;
      //if the available value is a 1, assign true, otherwise it's false.
      i = atoi(temp);
      if(i == 1)
        result = true;
      if(!inventory_p->SetAvailability(i))
        return false;
      cout << "Passed SetAvailability" << endl;
      //implement a set owner function


      cout << "Entering setOwner" << endl;
      if(fileReaderOpen.peek() == '\n')
        inventory_p->SetOwner("None");
      else
	  {
		fileReaderOpen >> temp;
        inventory_p->SetOwner(temp);
	  }

    }
  }
      //now from here I will need to call all of the members to set data read
      //from the input file
  else
    return false;
return true;
}

/*
  GetName:
    GetName will return the value of m_name to the calling routine
*/
char * Agency::GetName()
{
  return m_name;
}

/*
  SetName:
    SetName will take the filestream pointer passed into it to read in
    the name from the external file. After reading in the name to a temp
    variable, a deep copy is performed to store the value read in to the
    m_name.
*/
bool Agency::SetName(const char * agencyName)
{
    cout << "In set name" << endl;
    if(strlen(agencyName) > MAX_CHAR_SIZE)
      return false;

    m_name = new char[strlen(agencyName) + 1];
    strcpy(m_name, agencyName);
    cout << "Exiting SetName" << endl;
    return true;
}

bool Agency::SetZip(const int srcZip)
{
  if(srcZip < 0)
    return false;
  m_zip = srcZip;
  return true;

}
