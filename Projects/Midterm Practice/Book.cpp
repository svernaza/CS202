#include "Booh.h"

int Book::s_idegen = 0;

Book::Book(): m_id(++s_idgen);
{
  SetTitle(DFLT_TITLE);
  SetIsbn(DFLT_ISBN);
  Free(); //mark book as free
}

Book::Book(const char * title, const int * isbn,
    const char * renter: m_id(++s_idgen)
{
  SetTitle(title);
  SetIsbn(isbn);
  Free();
  if(strcmp(renter, DFLT_RENTER))
  {
    (*this) + renter;
  }
}

Book::Book(const Book& srcB): m_id(++s_idgen)
{
  SetTitle(srcB.m_title);
  SetIsbn(srcB.m_isbn);ß
  Free(); //custom copy constructor will make book copy but makr new object free
}

Book::~Book()
{

}

Book& Book::operator=(const Book& rhs)
{
  if(this != &rhs)
  {
    SetTitle(rhs.m_title);
    SetIsbn(rhs.m_isbn);
    if(rhs.m_available)
      Free();
    else
      (*this) + rhs.m_renter;
  }
  return (*this);
}

void Book::SetTitle(const char * srcTitle)
{
  if(!srcTitle)
    m_title = DFLT_TITLE;
  myStrCpy(m_title, srcTitle)
}

const char * Book::GetTitle() const
{
  return m_title;
}

void Book::SetIsbn(const int * srcIsbn)
{
  intCpy(m_isbn, srcIsbn);
}

const int * Book::GetIsbn() const
{
  return m_isbn;
}

void Book::SetAvail(bool srcAvail)
{
  m_available = srcAvail;
}

bool Book::GetAvailable() const
{
  return m_available;
}

void Book::SetRenter(char * srcRenter)
{
  myStrCpy(m_renter, srcRenter);
}

const char * Book::GetRenter() const
{
  return m_renter;
}

bool Book::operator+(const char * renter)
{
  if(!m_available || !strcmp(renter, DFLT_RENTER))
  {
    return false;
  }
  else
  {
    strcpy(m_renter, renter);
    m_available = false;
  }
  return true;
}

void Book::Free()
{
  myStrCpy(m_renter, DFLT_RENTER);
  m_available = true;
}

bool Book::Valid() const
{
  if(!strcmp(m_title, DFLT_TITLE) || !intCmp(m_isbn, DFLT_ISBN, ISBN_LEN))
    return false;
  return true;
}

int Book::GetIDGen()
{
  return s_idgen;
}

ostream& Book::operator<< (const ostream& os, const Book& srcBook)
{
  os << srcBook.m_title << "(" << srcBook.m_id << ") ";
  intPrint(os, srcBook.m_isbn, ISBN_LEN);
  if(srcBook.m_available)
    os << "Free for rent";
  else
    os << "Rented to: " << srcBook << srcBook.m_renter;
  return os;
}
