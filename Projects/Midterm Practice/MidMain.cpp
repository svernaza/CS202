#include <iostream>
#include <cctype>
using namespace std;
//helper functions
char * myStrCpy(char * dest, const char * src);
int myStrCmp(const char * str1, const char * str2);
size_t myStrLen(const char * str);
void intCpy(int * dst, const int * src, int size);

int main()
{
  const char * oldStr = "ABCD";
  char dest[50];

  cout << "Testing the String Copy I mad" << endl;
  char * newStr = myStrCpy(dest, oldStr);

  cout << "newStr: " << newStr << endl;
  cout << "dest: " << dest << endl;

  cout << "Testing myStrCmp" << endl;
  int ret = myStrCmp(dest, "AbcD");
  if(ret < 0)
    cout << "Left one doesn't match" << endl;
  if(ret > 0)
    cout << "Right one doesn't match" << endl;
  if(!ret)
    cout << "Equal!" << endl;

  cout << "Testing myStrLen" << endl;
  cout << "Length of dest is: " << myStrLen(dest);



  return 0;
}

char * myStrCpy(char * dest, const char * src)
{
  char * beg = dest;
  while((*dest++ = *src++));
  return beg;
}

int myStrCmp(const char * str1, const char * str2)
{
  int ret;
  while(*str1 && *str1++ == *str2++)
  ;
    return (*str1 - *str2);
}

size_t myStrLen(const char * str)
{
  int cnt = 0;
  while(*str++)
    ++cnt;
  return cnt;
}

void intCpy(int * dst, const int * src, int size)
{
  while(--size >= 0)
    *dest++ = *src++;
}

int intCmp(const int * arr1, const int * arr2, int size)
{
  int res = 0;
  while(--size >= 0)
  {
    res = (*arr1++ - *arr2++)
    if(res)
      return res;
  }
  return 0;
}

void intPrint(std::ostream& os, const int * arr, int size)
{
  while(--size >=0)
    os << *arr++;
}
