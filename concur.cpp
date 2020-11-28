#include <thread>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int main()
{
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<> dist(1, 1000);
  std::vector<std::thread> threads;

  for (const auto& str: {"Enjoy\n", "My\n", "Ass\n"}) {
    std::chrono::milliseconds duration(dist(eng));
    
    threads.emplace_back([str, duration]() {
      std::this_thread::sleep_for(duration);
      std::cout << str;
    });
  }

  for (auto& t: threads)
    t.join();

  return 0;
}