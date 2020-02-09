#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnSeqB)
{
  int nSeqBSiz;
  cin >> nSeqBSiz;
  rvnSeqB.resize(nSeqBSiz - 1);

  for (int& rnSeqB : rvnSeqB)
    cin >> rnSeqB;
}
  
int fnMaxValueGet(const vector<int>& cnrvnSeqB)
{
  vector<int> vnSeqA(cnrvnSeqB.size() + 1, 100001);

  for (int i = 0; i < cnrvnSeqB.size(); i++)
  {
    if (cnrvnSeqB[i] < vnSeqA[i])
      vnSeqA[i] = cnrvnSeqB[i];
    if (cnrvnSeqB[i] < vnSeqA[i + 1])
      vnSeqA[i + 1] = cnrvnSeqB[i];
  }

  int nSum = accumulate(begin(vnSeqA), end(vnSeqA), 0);
  return nSum;
}
  
int main()
{
  vector<int> vnSeqB;

  fnInput(vnSeqB);
  cout << fnMaxValueGet(vnSeqB) << endl;

  return 0;
}
