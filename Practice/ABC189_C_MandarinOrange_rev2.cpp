#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvSeq)
{
  int sizSeq;
  cin >> sizSeq;
  rvSeq.resize(sizSeq);

  for (int& rseq : rvSeq)
    cin >> rseq;
}

int calcMaxRect(const vector<int>& crvSeq)
{
  int maxRect = 0;

  for (int left = 0; left < (int)crvSeq.size(); ++left)
  {
    int minQty = crvSeq[left];

    for (int right = left; right < (int)crvSeq.size(); ++right)
    {
      minQty = min( minQty, crvSeq[right] );
      maxRect = max( maxRect, minQty * (right - left + 1));
    }
  }
  return maxRect;
}
  
int main()
{
  vector<int> vSeq;

  input(vSeq);
  cout << calcMaxRect(vSeq) << endl;

  return 0;
}
