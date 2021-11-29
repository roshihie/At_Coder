#include <bits/stdc++.h>
using namespace std;
using uint = unsigned;

void input(string& rsTarget)
{
  cin >> rsTarget;
}

int parseString(const string& cnrsTarget)
{
  const vector<string> cnvsWord = {"dream", "dreamer", "erase", "eraser"};
  
  int nBgn = cnrsTarget.size();
  
  while ( nBgn )
  {
    bool bRslt = false;
    int nPos;

    for (uint nx = 0; nx < cnvsWord.size(); ++nx)
    {
      nPos = nBgn - cnvsWord[nx].size();
      if (nPos < 0) continue;
      if ( cnrsTarget.substr(nPos, cnvsWord[nx].size() ) == cnvsWord[nx] )
      {
        bRslt = true;
        break;
      }
    }
    if ( !bRslt ) return 0;

    nBgn = nPos;
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
