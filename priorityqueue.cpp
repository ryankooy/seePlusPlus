#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int main()
{
  // Priority queue.
  priority_queue<pair<int, string>> pq;

  pq.push(make_pair(3, "Clear drains"));
  pq.push(make_pair(4, "Feed cat"));
  pq.push(make_pair(5, "Make tea"));
  pq.push(make_pair(1, "Solve RC tasks"));
  pq.push(make_pair(2, "Tax return"));

  while (!pq.empty()) {
    cout << pq.top().first << ", " << pq.top().second << endl;
    pq.pop();
  }

  cout << '\n';

  // Heap queue.
  vector<pair<int, string>> pq2;

  pq2.push_back(std::make_pair(3, "Clear drains"));
  pq2.push_back(std::make_pair(4, "Feed cat"));
  pq2.push_back(std::make_pair(5, "Make tea"));
  pq2.push_back(std::make_pair(1, "Solve RC tasks"));

  make_heap(pq2.begin(), pq2.end());
  pq2.push_back(make_pair(2, "Tax return"));
  push_heap(pq2.begin(), pq2.end());

  while (!pq2.empty()) {
    cout << pq2[0].first << ", " << pq2[0].second << endl;
    pop_heap(pq2.begin(), pq2.end());
    pq2.pop_back();
  }

  return 0;
}
