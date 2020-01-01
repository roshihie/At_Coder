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
    bool bRslt = false;
    ixEnd = ixBgn;
    for (int i = 0; i < cnvsWord.size(); i++)
    {
      ixBgn = ixEnd - cnvsWord[i].size();
      if (ixBgn < 0)  ixBgn = 0;

      if (sTarget.substr(ixBgn, cnvsWord[i].size()) == cnvsWord[i])
      {
        bRslt = true;
        break;
      }
    }
    if (!bRslt)  return 0;
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

