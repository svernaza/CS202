
#include <iostream>

using namespace std;

const int MAX_CHAR = 255;
const char * DFLT_TITLE = "notitle";
const int ISBN_LEN = 13;
const int DFLT_ISBN [ISBN_LEN] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
const char * DFLT_RENTER = "norenter"

class Book
{
  friend ostream& operator<< (ostream& os, const Book& srcBook);
public:
  Book();
  Book(const char * title = DFLT_TITLE,
      const int * isbn = DFLT_ISBN,
      const char * m_renter = DFLT_RENTER
    );
  Book(const Book& other);
  ~Book();
  Book& operator=(const Book& rhs);
  void SetTitle(const char * srcTitle);
  void SetIsbn(int * srcIsbn);
  const char * GetTitle() const;
  const int * GetIsbn() const;
  bool GetAvailable() const;
  const char * GetRenter() const;
  bool Valid() const;
  bool operator+(const char * renter);
  void Free();

  static int GetIDGen();

private:
  const int m_id;
  char m_title[MAX_CHAR];
  int m_isbn[ISBN_LEN];
  bool m_available;
  char m_renter[MAX_CHAR];
  static int s_idgen;
};
