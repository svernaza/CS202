/*
  Samuel Vernaza
  CS202
  Program 2
*/

#include "PA2_Vernaza_Samuel.h"

/*
  greeting:
    This is a nice little greeting users will get upon initiating the program.
    Nothing more special than a nice warm message!
*/
void greeting()
{
  cout << "Hello! Thank you for choosing our car rental services for your\n";
  cout << "next holiday vacation. We're thrilled to have you and would like\n";
  cout << "to offer you our full range of services. Before we can do that \n";
  cout << "we'll need some information from you. Let's get started! " << endl;
}

/*
 getName:
	pre: expects a character entry from the user
	post: will have assigned an array to the variable name
*/
void getName(char name[])
{
	cout << "\nWhat's the name of your file? (remember .txt)\n";
	cin.get(name, FILE_MAX, '\n');
	cin.ignore(100, '\n');
	if(strlen(name) > FILE_MAX)
	{
		while(strlen(name) > FILE_MAX)
		{
			cout << "Invalid entry. Try again:";
			cin.get(name, MAX, '\n');
			cin.ignore(100, '\n');
		}
	}
	return;
}

/*
	clear_screen:
		Clears the screen for more readible data entry if needed
*/
void clearScreen()
{
	int i = 0;
	while(++i < 100)
		cout << '\n';
}

/*
	correct:
		Passes the most recently entered name into f(x). user verifies the entry
    is correct. Return Y or N char for correct and incorrect answers,
    respectively.
    Not used in Program_2
*/
char correct(char name[])
{
	char answer = 'X';
	cout << "\nYou entered, " << name << ". Is this correct? (Y/N)" << endl;
	cin >> answer;
	cin.ignore();
	answer = toupper(answer);
	return answer;
}

/*
    read3D:
    reads from an external data file and stores the contents into the
    name_table array for storage holding in the local variable. This local
    variable will later be used to write to the external data file.
    1 returned is a success, 0 returned is fail.
    Not used in Project_2.
*/
bool read3D(char file_name[], char name_table[][8])
{
  ifstream name_in;
	name_in.open(file_name);

	if(name_in)
	{
		while(name_in && !name_in.eof())
		{
			int i = 0;
			while(i < 10)
			{
					name_in.get(name_table[i], 8, '\n');
					name_in.ignore(100, '\n');
				++i;
			}
		}
    cout << "Success!" << endl;
    name_in.clear();
    name_in.close();
    return true;
	}
	else
  {
		cout << "Couldn't open file!" << endl;
    name_in.clear();
    name_in.close();
    return false;
  }
}

/*
  write3D:
    Writes data to external data files by using the stored values in the
    name_table array, filled by the read function early described.
    1 returned means a success, 0 is a failure.
    Not used in Project_2.
*/
bool write3D(char file_name[], char name_table [][8])
{
  ofstream name_out;
  cout << "\nNow for the file name to write out to, please enter it!" << endl;
  getName(file_name);
	name_out.open(file_name);

	if(name_out)
	{
		int i = 0;
		while(i < 10)
		{
			int j = 0;
			while (j < 8)
				name_out << name_table[i][j++];
      name_out << endl;
      ++i;
		}
    cout << "\nSuccess!" << endl;
    name_out.close();
    return true;
	}
	else
  {
		cout << "\nFile couldn't be opened!" << endl;
	  name_out.close();
    return false;
  }
}

/*
  printUnordered:
    Prints the data entered into the file in unsorted order
    Not used in Program_2.
*/
void printUnordered(char name_table[][8])
{
  int i = 0;
  while(i < 10)
  {
      int j = 0;
      while(j < 8)
        cout << name_table[i][j++];
      cout << endl;
      ++i;
  }
  return;
}

/*
  readFrom:
    reads from the file_name passed into the function.
    Stores all of the contents read into the array of structs
    Returns true on success and false otherwise. Error checking occurs
    in client.
*/
bool readFrom(char file_name[], struct car stock[5])
{
  ifstream name_in;
	name_in.open(file_name);

	if(name_in)
	{
		while(name_in && !name_in.eof())
		{
			int i = 0;
			while(i < 5)
			{
          cout << "What is the year of this vehicle?" << endl;
					name_in >> stock[i].year;
          //name_in.ignore(100, '\n');

          cout << "What is the make of this vehicles?" << endl;
          name_in >> stock[i].make;
					//name_in.ignore(100, '\n');

          cout << "What is the model of this vehicles?" << endl;
          name_in >> stock[i].model;

          cout << "What is the price of this vehicle to rent?" << endl;
          name_in >> stock[i].price;
          //name_in.ignore(100, '\n');

          cout << "Is this vehicle available?" << endl;
          name_in >> stock[i].available;
          name_in.ignore(100, '\n');
          cout << endl << endl;
				++i;
			}
		}
    cout << "\nRead complete!" << endl;
    name_in.clear();
    name_in.close();
    return true;
	}
	else
  {
		cout << "\nCouldn't open file!" << endl;
    name_in.clear();
    name_in.close();
    return false;
  }

}

/*
  writeTo:
    Writes to a file once the user specifies which file will be written to.
    This is asked using the getName() and instructs the user from there.
    The name given is returned to the writeTo function and is used to open
    an external data file. The while loop takes care of multiple data entry and
    abides by the rules that we will always recieve 5 cars. Once completed,
    success flag is returned on fail flag.
*/
bool writeTo(struct car stock[5])
{
  if(!stock)
    return false;

  char file_name[FILE_MAX];

  ofstream name_out;
  cout << endl << endl;
  cout << "\nPlease enter the file name you want to write to." << endl;
  getName(file_name);
  name_out.open(file_name);

  if(name_out)
  {
    cout << "\nThe available cars are: " << endl << endl;
    int i = 0;
    while(i < 5)
    {
      name_out << "Car " << i + 1 << ": " << endl;
      name_out << stock[i].year << endl;
      name_out << stock[i].make << endl;
      name_out << stock[i].model << endl;
      name_out << "$" << stock[i].price << "/day " << endl;
      name_out << "In stock: ";
      if(stock[i].available)
        name_out << "Yes" << endl;
      else
        name_out << "Unavailable" << endl;
      name_out << "--------------------------" << endl;
      ++i;
    }
    cout << "File created and data entered" << endl;
    return true;
  }
  else
  {
    cout << "Unable to enter the data" << endl;
    return false;
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

/*
  structCopy:
    Takes the value of the stockSrc and copies all of its contents into the
    stockDest. Passed in by reference to actually alter the contents of the
    struct, yes passing in a pointer is passing by reference. You're actually
    working with the value in memory and altering its contents instantaneously.
    It's much faster to do it this way.
*/
bool structCopy(struct car *stockDest, struct car *stockSrc)
{
    struct car *tempSrc = stockSrc;
    struct car *tempDest = stockDest;

    tempDest->year = tempSrc->year;
    myStrCpy(tempDest->model, tempSrc->model);
    myStrCpy(tempDest->make, tempSrc->make);
    tempDest->price = tempSrc->price;
    tempDest->available = tempSrc->available;
    return true;
}

/*
  swapCar:
    swapCar the integeger values of the array indexes for ascending order sort
*/
bool swapCar(struct car *stockA, struct car *stockB)
{
  if(!stockA && !stockB)
    return false;
  //assign temporary struct pointer
  struct car *temp = new car;
  //have temporary pointer pointing to stockA
  structCopy(temp, stockA);

  //copy stockB to stockA
  if(!structCopy(stockA, stockB))
    {
      cout << "\nDidn't copy!" << endl;
      delete temp;
      return false;
    }

  //copy stockB to stockA
  if(!structCopy(stockB, temp))
  {
    cout << "\nDidn't copy!" << endl;
    delete temp;
    return false;
  }
  delete temp;
  return true;
}

/*
  sortAscending:
    Passed in the car stock array. The stock array is then compared using
    the bubble sort algorithm. For each price that is greater than the previous
    the cars themselves will be pass to the swapCar function where it will
    take care of changing the positions of the cars in need of changing. It
    then returns back to the loop and continues this process until the entire
    array has been sorted.

*/
bool sortAscending(struct car stock [5])
{
  if(!stock)
    return false;

  int j;
  int i = 0;
  while (i < 5-1)
  {
      j = 0;
      while(j < 5-i-1)
      {
        if(stock[j].price > stock[j+1].price)
          swapCar(&stock[j], &stock[j+1]);
        j++;
      }
    i++;
  }
  return true;
}

/*
  printAll:
    prints all of the data inside of the array of structs to the terminal.
    This is for instanteous viewing. Any other lists or cars can be found
    in the file created by the user in the write process.
*/
void printAll(struct car stock[5])
{
  if(!stock)
    return;

  cout << "\nOur car inventory is: " << endl << endl;
  int i = 0;
  while(i < 5)
  {
    cout << "Car " << i + 1 << ": " << endl;
    cout << stock[i].year << endl;
    cout << stock[i].make << endl;
    cout << stock[i].model << endl;
    cout << "$" << stock[i].price << "/day " << endl;
    if(stock[i].available)
      cout << "Yes" << endl;
    else
      cout << "Unavailable" << endl;
    cout << "--------------------------" << endl;
    ++i;
  }
}

void printCar(struct car stock)
{
  cout << stock.year << endl;
  cout << stock.make << endl;
  cout << stock.model << endl;
  cout << stock.price << endl;
  if(stock.available)
    cout << "Available" << endl;
}

/*
  availableCars:
    Passed the number of days the user wants to rent for and the struct of
    arrays. The while loop will cycle through the stock and use the PrintCar()
    iff the stock at that index is available. The function will multiply the
    days of each one of the available stock items and display this as price
    for the vehicle.
*/
bool availableCars (int days, struct car stock[5])
{
  if(days < 0)
    return false;

  cout << "Available cars for " << days << " days:" << endl;
  int i = 0;
  while(i < 5)
  {
    if(stock[i].available)
    {
      cout << "Car " << i+1 << ":" << endl;
      printCar(stock[i]);
      cout << "Price estimate for " << days << " days: ";
      cout << "$" << (stock[i].price * days) << endl;
      cout << "-------------------------------" << endl;
      ++i;
    }
    else
      ++i;
  }
  return true;
}

/*
  carSelection:
    takes the number of days previously entered and the available cars.
    The user will be make their selection based on the car number I give them
    in the display screen. I WILL TAKE CARE OF THE INDEX CALCULATION IN THIS
    FUNCTION. That means if it says car 2, enter 2 into the prompt. I will sub
    n-1 from the input and display the correct car. This function will also
    check for values that range outside of the selection.
*/
bool carSelection(int days, struct car stock[5])
{
  int selection = 0;
  if(days < 0)
    return false;

  cout << "Select the car you're interested in from the list below: " << endl;
  cout << endl;
  availableCars(days, stock);
  cout << "Enter the number of the vehicle you want (e.g. Car 2, input: 2):";
  cin >> selection;
  while(!((selection >= 1) && (selection <= 5)))
  {
    cout << "That is out of range" << endl;
    cout << "Renter your selection" << endl;
    cin >> selection;
  }

  selection -= 1;
  if(stock[selection].available)
  {
    cout << endl << endl;
    cout << "Congratualations, you've successfully rented this vehicle!\n";
    cout << "You're total price is: $";
    cout << (stock[selection].price * days) << endl;
    cout << "One of our agents will reach out to you for payment.\n";
    cout << "Thank you for your business! " << endl;
    cout << endl;
    stock[selection].available = false;
    return true;
  }
  else
  {
    cout << "You've entered an unavailable car..." << endl;
    cout << "Rental session ending..." << endl;
    return false;
  }
}

void exitMessage()
{
  cout << endl << endl;
  cout << "Thank you very much for using our software.\n";
  cout << "We hope that you will use us again in the future for all of \n";
  cout << "your rental needs!\nGoodbye!" << endl;
  cout << "\nSession ended..." << endl;
}
