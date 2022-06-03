#include <bits/stdc++.h>
using namespace std;

void input(string& rsTarget)
{
  cin >> rsTarget;
}

int parseString(string sTarget)
{
  const vector<string> cnvsWord = {"dream", "dreamer", "erase", "eraser"};
  int nBgn, nEnd;
  nBgn = sTarget.size();

  while ( nBgn )
  {
    bool bRslt = false;
    nEnd = nBgn;

    for (int nx = 0; nx < cnvsWord.size(); ++nx)
    {
      nBgn = nEnd - cnvsWord[nx].size();
      if (nBgn < 0) continue;

      if (sTarget.substr(nBgn, cnvsWord[nx].size() ) == cnvsWord[nx])
      {
        bRslt = true;
        break;
      }
    }
    if ( !bRslt ) return 0;
  }
  return 1;
}

int main()
{
  string sTarget;
  
  input(sTarget);
  if (parseString(sTarget)) cout << "YES" << endl;
  else                      cout << "NO"  << endl;

  return 0;
}
