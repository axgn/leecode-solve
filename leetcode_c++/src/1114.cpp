#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;

class Foo {
  mutex mtx1, mtx2;
  condition_variable cv1, cv2;
  bool firstReady, secondReady;

public:
  Foo() {
    firstReady = false;
    secondReady = false;
  }

  void first(function<void()> printFirst) {
    {
      lock_guard<mutex> lock(mtx1);
      firstReady = true;
      printFirst();
    }
    cv1.notify_one();
  }

  void second(function<void()> printSecond) {
    unique_lock<mutex> lock(mtx1);
    cv1.wait(lock, [this] { return firstReady; });
    {
      lock_guard<mutex> lock(mtx2);
      secondReady = true;
      printSecond();
    }
    cv2.notify_one();
  }

  void third(function<void()> printThird) {
    unique_lock<mutex> lock(mtx2);
    cv2.wait(lock, [this]() { return secondReady; });
    printThird();
  }
};
