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
