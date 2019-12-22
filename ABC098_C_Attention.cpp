#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsLine)
{
  int nSize;
  cin >> nSize;
  cin >> rsLine;
}

int fnAttention(const string& cnrsLine)
{
  int nCumlSum = 0;
  for (int i = 1; i < cnrsLine.size(); i++)
    if (cnrsLine[i] == 'E')  nCumlSum++;

  int nMinSum = nCumlSum;
  for (int i = 1; i < cnrsLine.size(); i++)
  {
    if (cnrsLine[i - 1] == 'W')  nCumlSum++;
    if (cnrsLine[i]     == 'E')  nCumlSum--;

    nMinSum = min(nMinSum, nCumlSum);
  }
  return nMinSum;
}
    
int main()
{
  string sLine;
  
  fnInput(sLine);
  cout << fnAttention(sLine) << endl;

  return 0;
}
