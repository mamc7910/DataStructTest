#include <iostream>
#include <fstream>
using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
  int tempArray[100];
  int index;
  if (numEntries == 0)
  {
    myArray[0] = newValue;
  }
  else
  {
    for (int i = 0; i < numEntries; i++)
    {
      if (i == 0 && newValue < myArray[0])
      {
        index = 0;
      }
      else
      {
        if ((myArray[i] <= newValue && (myArray[i + 1] >= newValue || myArray[i + 1] == 0)))
        {
          index = i;
        }
      }
      for (int k = 0; k < i; k++)
      {
        tempArray[k] = myArray[k];
      }
      tempArray[index] = newValue;
      for (int j = 0; j < numEntries; j++)
      {
        tempArray[j + 1] = myArray[j];
      }
      for (int i = 0; i < numEntries + 1; i++)
      {
        myArray[i] = tempArray[i];
      }
    }
  }
  return numEntries + 1;
}

int main(int argc, char const *argv[])
{
  string filename;
  filename = argv[1];
  ifstream myfilestream;
  myfilestream.open(filename);
  if (myfilestream.is_open())
  {
    int i = 0;
    string line;
    int Array[100];
    for (int i = 0; i < 100; i++)
    {
      Array[i] = -1;
    }
    while (getline(myfilestream, line))
    {
      int n = stoi(line);
      i = insertIntoSortedArray(Array, i, n);
      for (int j = 0; j < i; j++)
      {
        cout << Array[j] << ", ";
      }
      cout << endl;
    }
  }
  else
  {
    cout << "Failed to open the file." << endl;
  }
}
