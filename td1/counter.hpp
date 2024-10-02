#include <iostream>

struct MyCounter {
    MyCounter() : counter(0), max(0) {
    }
    MyCounter(unsigned max) : MyCounter(0, max) {
    }
    MyCounter(unsigned counter, unsigned max) : counter(counter), max(max) {
    }
    MyCounter(MyCounter const& other) : counter(other.counter), max(other.max) {
    }
    ~MyCounter() {
        std::cout << "Deleting (" << counter << ", " << max << ")\n";
    }

    unsigned counter;
    unsigned max;

    unsigned getCounter() const;
    unsigned getMax() const;

    void increment();
    void reset();
    void set(unsigned value);
    void setMax(unsigned value);
};