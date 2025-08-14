#include <atomic>
#include <functional>
using namespace std;

class Foo {
    atomic<int> oneprinted{0};
    atomic<int> twoprinted{0};
public:
    Foo() {}

    void first(function<void()> printFirst) {
        printFirst();
        oneprinted.store(1);
    }

    void second(function<void()> printSecond) {
        while (!oneprinted.load()) {}
        printSecond();
        twoprinted.store(1);
    }

    void third(function<void()> printThird) {
        while (!oneprinted.load() || !twoprinted.load()) {}
        printThird();
    }
};
