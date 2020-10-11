#include <bits/stdc++.h>
using namespace std;

void input(string& rsLine)
{
  int nSize;
  cin >> nSize >> rsLine;
}

int calcMinChgDir(const string& cnrsLine)
{
  int nCumlSum = 0;
  for (int nx = 1; nx < cnrsLine.size(); ++nx)
    if (cnrsLine[nx] == 'E')  nCumlSum++;

  int nMinSum = nCumlSum;
  for (int nx = 1; nx < cnrsLine.size(); ++nx)
  {
    if (cnrsLine[nx - 1] == 'W')  ++nCumlSum;
    if (cnrsLine[nx]     == 'E')  --nCumlSum;

    nMinSum = min(nMinSum, nCumlSum);
  }
  return nMinSum;
}
    
int main()
{
  string sLine;
  
  input(sLine);
  cout << calcMinChgDir(sLine) << endl;

  return 0;
}
