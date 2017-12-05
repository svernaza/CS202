
#include "book.h"
using namespace std;

const int LIBRARY_N_BOOKS = 1000;
class Library
{
  friend ostream& operator<<(ostream& os, const Library & srcLib);
public:
  Library(const char * name);

  void SetName(const char * name);
  const char * GetName() const;

  Book * FindOpenSpot();
  Book * operator[](const char * title);
  Book& operator[](int index);

  bool RentBook(int index, const char * name);
  bool operator+(const Book& srcBook);

private:
    char m_name[STR_MAX];
    Book m_inventory[LIBRARY_N_BOOKS];
};
