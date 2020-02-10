#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsTarget)
{
  cin >> rsTarget;
}

int fnParse(string sTarget)
{
  const vector<string> cnvsWord{"dream", "dreamer", "erase", "eraser"};
  int ixBgn, ixEnd;
  ixBgn = sTarget.size();

  while (ixBgn)
  {
    bool bReslt = false;
    ixEnd = ixBgn;
    for (int i = 0; i < cnvsWord.size(); i++)
    {
      ixBgn = ixEnd - cnvsWord[i].size();
      if (ixBgn < 0)  continue;

      if (sTarget.substr(ixBgn, cnvsWord[i].size()) == cnvsWord[i])
      {
        bReslt = true;
        break;
      }
    }
    if (!bReslt)  return 0;
  }
  return 1;
}

int main()
{
  string sTarget;
  
  fnInput(sTarget);
  if (fnParse(sTarget)) cout << "YES" << endl;
  else                  cout << "NO"  << endl;

  return 0;
}
