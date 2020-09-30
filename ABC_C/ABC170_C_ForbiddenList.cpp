#include <bits/stdc++.h>
using namespace std;

void input(int& rnTarget, vector<int>& rvnSeq)
{
  int nSeqSiz;
  cin >> rnTarget >> nSeqSiz;
  rvnSeq.resize(nSeqSiz);

  for (int& rnSeq : rvnSeq)
    cin >> rnSeq;
}

int calcMinNolistNum(int nTarget, const vector<int>& cnrvnSeq)
{
  map<int, int> mpSeq;

  for (int nSeq : cnrvnSeq)
    mpSeq[ nSeq ]++;

  int nMore = nTarget;
  while ( mpSeq[nMore] != 0 )
    ++nMore;

  int nLess = nTarget;
  while ( mpSeq[nLess] != 0 )
    --nLess;

  if ( abs(nTarget - nMore) < abs(nTarget - nLess) )
    return nMore;
  else
    return nLess;
}
  
int main()
{
  int nTarget;
  vector<int> vnSeq ;

  input(nTarget, vnSeq);
  cout << calcMinNolistNum(nTarget, vnSeq) << endl;

  return 0;
}
