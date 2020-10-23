#pragma once
#include <iostream>
using namespace std;

int len(const char *arr)
{
  int i = 0;
  while (arr[i] != '\0')
  {
    i++;
  }
  return i;
}

void deepCopy(char *&dest, const char *src)
{
  // create memory
  int l = 0;
  if (src)
  {
    l = len(src);
    dest = new char[l + 1]{'\0'};
  }

  // copy memory
  for (int i = 0; i < l; i++)
  {
    dest[i] = src[i];
  }
}

bool isStrEqual(const char *str1, const char *str2)
{
  if (len(str1) != len(str2))
  {
    return false;
  }
  else
  {
    for (int i = 0; str1[i] != '\0'; i++)
    {
      if (str1[i] != str2[i])
      {
        return false;
      }
    }
    return true;
  }
}

// empties a string any string
void clearStr(char *str)
{
  if (str)
  {
    for (int i = 0; str[i] != '\0'; i++)
    {
      str[i] = '\0';
    }
  }
}

// bool readRecord(ifstream& in, char record[]){
//     in.getline(record, '\0');
//     return true;
// }