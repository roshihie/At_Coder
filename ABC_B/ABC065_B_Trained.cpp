#include <bits/stdc++.h>
using namespace std;

struct StTrain
{
  StTrain() :
    m_nNext(0), m_nDone(false)
  { }

  int  m_nNext;
  bool m_nDone;
};

void fnInput(vector<StTrain>& rvoTrain)
{
  int nSize;
  cin >> nSize;

  StTrain oTrain;
  rvoTrain.resize(nSize, oTrain);
  
  for (int n = 0; n < nSize; n++)
    cin >> rvoTrain[n].m_nNext;
}

int fnTrain(vector<StTrain>& rvoTrain)
{
  int nCnt = 0;
  int n = 0;
  while (true)
  {
    nCnt++;
    if (rvoTrain[n].m_nDone)       return -1;

    rvoTrain[n].m_nDone = true;
    if (rvoTrain[n].m_nNext == 2)  return nCnt;
 
    n = rvoTrain[n].m_nNext - 1;
  }
}
    
int main()
{
  vector<StTrain> voTrain;
  
  fnInput(voTrain);
  int nRslt = fnTrain(voTrain);
  cout << nRslt << endl;

  return 0;
}
