/*
 Sam Vernaza
 CS202
 Project_2
*/

/*
 *The purpose of this program is to have stored a number of vehicles available
 for rent in a struct of arrays. These arrays should contain information about
 the vehicles such as, Model Name, Make, Day Rate, Availability and anything
 else specified on the HW assignment.
 all data is linked in .h files with implementation files that match the
 declaration of the prototypes.
*/
#include "PA2_Vernaza_Samuel.h"

int main()
{
	car stock[5];
	char file_name[MAX];
	int days;

	greeting();
	//get the file that we will read all of the data from
	/* Done!*/
	cout << "\nWe'll need the name of the file you'd like to read from" << endl;
	getName(file_name);
	//read_from() will read all of the data in the file and assign
	//the array of structs each individual value
	/* Done! */
	if(!readFrom(file_name, stock))
	{
		cout << "\nThere isn't a file to read" << endl;
		cout << "We will now exit the program" << endl;
		return 0;
	}

	clearScreen();
	//prints all of the data in the array of structs to the main screen
	/* Done! */
	printAll(stock);
	cout << "\nThat looks a bit messy. \nInitiating sorting..." << endl;
	if(!sortAscending(stock))
	{
			cout << "Sorry, but your data doesn't match the format specified";
			cout << " We will now exit the program. Goodbye! " << endl;
			return 0;
	}

	//print out all data for all of the cars to separate output file_name
	cout << "\nInitiating file read..." << endl;
	cout << "\nWe'll need the name of the file you'd like to store to" << endl;
	if(writeTo(stock))
		cout << "Written!" << endl;
	else
	{
		cout << "Error loading..." << endl;
		cout << "We will not be able to store the file" << endl;
		cout << "Exiting" << endl;
		return 0;
	}

		clearScreen();

		//print out all of the data for all of the cars to the terminal
		cout << "Price: Low to High" << endl;
		printAll(stock);

		days = 0;
		cout << "How many days do you want to rent a car for?" << endl;
		cin >> days;

		clearScreen();

		//ask the user how many days they want to rent.
		//print to terminal only the cars that are available, sorted
		//with estimated cost.
		if(!carSelection(days, stock))
		{
			cout << "Sorry, it looks like we're out of stock ";
			cout << "or you entered weren't valid...Goodbye!" << endl;
			return 0;
		}
		exitMessage();
	return 0;
}
