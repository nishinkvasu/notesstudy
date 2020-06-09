#include <algorithm>  // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;
using std::abs;

bool greater(int a, int b)
{
  if(a > b)
    return true;
  else
  {
    return false;
  }
  
}

bool lesser(int a, int b)
{
  if(a < b)
    return true;
  else
    {
      /* code */
      return false;
    }
    
}

bool modgreater(int a, int b)
{
  if(abs(a) > abs(b))
    return true;
  return false;
}
// Sample code to demonstrate sort library function
int main()
{
  //showing example of vector sort
  vector<int> a{-5, 6, -3, 2, 9, -1};
  auto b = a;
  // sort without a sort function - ascending
  sort(a.begin(), a.end());
  for (auto i : a)
    cout << i << " ";
  cout<<"\n Original Array \n";
  a = b;
  for (auto i : a)
    cout << i << " ";

  cout<<"\n ";
  //sort with greater sort function
  sort(a.begin(),a.end(),greater);
  for (auto i : a)
    cout << i << " ";

  a = b;
  cout<<"\n ";
  //sort with lesser sort function
  sort(a.begin(),a.end(),lesser);
  for (auto i : a)
    cout << i << " ";

  a = b;
  cout<<"\n ";
  //sort with modgreater sort function
  sort(a.begin(),a.end(),modgreater);
  for (auto i : a)
    cout << i << " ";
}