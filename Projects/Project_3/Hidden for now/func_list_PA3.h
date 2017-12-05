/*
  Sam Vernaza
  CS202
  .h file for useful functions created
*/

#ifndef FUNC_LIST_PA3_H
#define FUNC_LIST_PA3_H

//prototypes
void greeting();
void exitMessage();
void getName(char name[]);
void clearScreen();
char correct(char name[]);
void printUnordered(char name_table[][8]);
bool read3D(char file_name[], char name_table[][8]);
bool write3D(char file_name[], char name_table[][8]);

//reads the conents from the file to the stock and store them.
bool readFrom(char file_name[], struct car stock[5]);

//write to the file_name given using the information in the stock
bool writeTo(struct car stock[5]);

//my implementation of strcpy()
char *myStrCpy(char *destination, const char *source);

//my implementation of strcmp
int	mystrcmp(const char *str1, const char *str2);

//copies the entire contents of the car struct
bool structCopy(struct car &stockDest, struct car &stockSrc);

//takes two structs and swaps the contents using my C-string copy function
bool swapCar(struct car *stockA, struct car *stockB);

//sorts the contents of the stock based on price per day
bool sortAscending(struct car stock[5]);

//print all of the items in the struct
void printAll(struct car stock[5]);

//lists all of the available cars after being given the days.
bool availableCars (int days, struct car stock[5]);

//guides user through selection process
bool carSelection(int days, struct car stock[5]);

//prints a single struct item
void printCar(struct car stock);

//struct definitions
struct car {
	int year;
	char make [MAX];
	char model [MAX];
	float price;
	bool available;
};

#endif
