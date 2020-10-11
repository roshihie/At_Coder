#include <bits/stdc++.h>
using namespace std;

void input(string& rsLine)
{
  int nSize;
  cin >> nSize >> rsLine;
}

int calcMinChgDir(const string& cnrsLine)
{
  int nMinChgDir = 0;

  for (int nx = 1; nx < cnrsLine.size(); ++nx)
    if (cnrsLine[nx] == 'E') ++nMinChgDir;

  int nChgDir = nMinChgDir;

  for (int nx = 1; nx < cnrsLine.size(); ++nx)
  {
    if (cnrsLine[nx - 1] == 'W')  ++nChgDir;
    if (cnrsLine[nx]     == 'E')  --nChgDir;

    nMinChgDir = min(nMinChgDir, nChgDir);
  }
  return nMinChgDir;
}
    
int main()
{
  string sLine;
  
  input(sLine);
  cout << calcMinChgDir(sLine) << endl;

  return 0;
}
