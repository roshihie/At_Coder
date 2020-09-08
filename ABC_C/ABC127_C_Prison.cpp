#include <bits/stdc++.h>
using namespace std;

struct StGate
{
  StGate() : 
    m_nPassLow(0), m_nPassHigh(0) { }

  int m_nPassLow;
  int m_nPassHigh;
};

void input(vector<StGate>& rvoGate)
{
  int  nPassSiz, nGateSiz;
  cin >> nPassSiz >> nGateSiz;
  rvoGate.resize(nGateSiz);

  for (StGate& roGate : rvoGate)
    cin >> roGate.m_nPassLow >> roGate.m_nPassHigh;
}

int countAlmightyPass(const vector<StGate>& cnrvoGate)
{
  int nAlmightyPassLow = 0;
  int nAlmightyPassHigh = 100001;

  for (StGate oGate : cnrvoGate)
  {
    nAlmightyPassLow  = max(nAlmightyPassLow,  oGate.m_nPassLow);
    nAlmightyPassHigh = min(nAlmightyPassHigh, oGate.m_nPassHigh);
  }
  return max(0, nAlmightyPassHigh - nAlmightyPassLow + 1);
}
  
int main()
{
  vector<StGate> voGate;

  input(voGate);
  cout << countAlmightyPass(voGate) << endl;

  return 0;
}
