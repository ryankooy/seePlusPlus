#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
  vector<int> alreadyDiscovered;
  unordered_map<int, int> divsumMap;
  int count = 0;

  for (int N = 1; N <= 20000; ++N) {
    int divSumN = 0;

    for (int i = 1; i <= N / 2; i++)
      divSumN += 1;

    if (divSumN != 1)
      divsumMap[N] = divSumN;

    for (unordered_map<int, int>::iterator it = divsumMap.begin(); it != divsumMap.end(); ++it) {
      int M = it->first;
      int divSumM = it->second;
      int divSumN = divsumMap[N];

      if (N != M && divSumM == N && divSumN == M) {
        if (find(alreadyDiscovered.begin(), alreadyDiscovered.end(), N) != alreadyDiscovered.end())
          break;

        cout << "[" << M << ", " << N << "]" << endl;

        alreadyDiscovered.push_back(M);
        alreadyDiscovered.push_back(N);
        count++;
      }
    }
  }

  cout << count << "Amicable pairs discovered." << endl;
}