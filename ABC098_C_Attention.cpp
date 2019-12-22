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
  int nSum = 0;
  for (int i = 1; i < cnrsLine.size(); i++)
    if (cnrsLine[i] == 'E')  nSum++;

  int nMinSum = nSum;
  for (int i = 1; i < cnrsLine.size(); i++)
  {
    if (cnrsLine[i - 1] == 'W')  nSum++;
    if (cnrsLine[i]     == 'E')  nSum--;

    nMinSum = min(nMinSum, nSum);
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
