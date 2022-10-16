#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvSeq)
{
  int sizSeq;
  cin >> sizSeq;
  rvSeq.resize(sizSeq);

  for (int& rSeq : rvSeq)
    cin >> rSeq;
}

int calcMaxRect(const vector<int>& crvSeq)
{
  int maxRect = 0;

  for (int left = 0; left < (int)crvSeq.size(); ++left)
  {
    int height = crvSeq[left];

    for (int right = left; right < (int)crvSeq.size(); ++right)
    {
      height = min( height, crvSeq[right] );
      maxRect = max( maxRect, (right - left + 1) * height );
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
