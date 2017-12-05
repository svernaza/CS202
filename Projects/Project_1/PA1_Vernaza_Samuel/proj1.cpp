/*
  Sam Vernaza
  CS202
  Project #1
*/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

//prototypes
void get_name(char name[]);
void clear_screen();
char correct(char name[]);
void print_unordered(char name_table[][8]);
bool read_from(char file_name[], char name_table[][8]);
bool write_to(char file_name[], char name_table[][8]);

size_t MAX = 50;

int main()
{
	char file_name[MAX];
	char name_table [10][8];
	char answer;

  //main greetings for the beginning of the program
	cout << "Greetings! Before we continue, I'll need some additional info."
	<< endl;
  //stores the file name
	get_name(file_name);
	cout << "The name of your file is " << file_name << endl;
  //error check values, if not correct, then it needs to be repeated
	answer = correct(file_name);
	if(answer != 'Y')
	{
		while(answer != 'Y')
		{
			cout << "Sorry about that..." << endl;
			get_name(file_name);
			answer = correct(file_name);
		}
	}
  //Open a file and read from it.
	cout << "I'll open a file for data entry called, " << file_name << endl;
  if(read_from(file_name, name_table))
    cout << "Data input successful" << endl;

  if(write_to(file_name, name_table))
    cout << "Data write successful" << endl;

  cout << "Here's what's in the file in unsorted order" << endl;
  print_unordered(name_table);

	return 0;
}

/*
 get_name:
	pre: expects a character entry from the user
	post: will have assigned an array to the variable name
*/
void get_name(char name[])
{
	//clear_screen();
	cout << "What's the name of the file you'd like to store? (remember .txt)"
  << endl;
	cin.get(name, MAX, '\n');
	cin.ignore(100, '\n');
	if(strlen(name) > MAX)
	{
		while(strlen(name) > MAX)
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
    This may or may not be used.
*/
void clear_screen()
{
	int i = 0;
	while(++i < 100)
		cout << '\n';
}

/*
	correct:
		pre: Passes the most recently entered name into f(x);
		user verifies the entry is correct.
		post: Return Y or N char for correct and incorrect answers, respectively.
*/
char correct(char name[])
{
	char answer = 'X';
	cout << "You entered, " << name << ". Is this correct? (Y/N)" << endl;
	cin >> answer;
	cin.ignore();
	answer = toupper(answer);
	return answer;
}


/*
  read_from:
    reads from an external data file and stores the contents into the
    name_table array for storage holding in the local variable. This local
    variable will later be used to write to the external data file.
    1 returned is a success, 0 returned is fail.
*/
bool read_from(char file_name[], char name_table[][8])
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
  write_to:
    Writes data to external data files by using the stored values in the
    name_table array, filled by the read_from function early described.
    1 returned means a success, 0 is a failure.
*/
bool write_to(char file_name[], char name_table [][8])
{
  ofstream name_out;
  cout << "Now for the file name to write out to, please enter it!" << endl;
  get_name(file_name);
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
    cout << "Success!" << endl;
    name_out.close();
    return true;
	}
	else
  {
		cout << "File couldn't be opened!" << endl;
	  name_out.close();
    return false;
  }
}

/*
  print_unordered:
    Prints the data entered into the file in unsorted order
*/
void print_unordered(char name_table[][8])
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
