#include <iostream>

class MyCounter {
protected:
    unsigned counter;
    unsigned max;

public:
    MyCounter() : counter(0), max(0) {
    }
    explicit MyCounter(unsigned max) : MyCounter(0, max) {
    }
    MyCounter(unsigned counter, unsigned max) : counter(counter), max(max) {
    }
    MyCounter(MyCounter const& other) : counter(other.counter), max(other.max) {
    }
    ~MyCounter();

    unsigned getCounter() const;
    unsigned getMax() const;

    void print();
    void increment();
    void reset();
    void set(unsigned value);
    void setMax(unsigned value);
};

class MyBiDiCounter : public MyCounter {
public:
    MyBiDiCounter() : MyCounter() {
    }
    explicit MyBiDiCounter(unsigned max) : MyCounter(max) {
    }
    MyBiDiCounter(unsigned counter, unsigned max) : MyCounter(counter, max) {
    }
    MyBiDiCounter(MyBiDiCounter const& other) : MyCounter(other) {
    }
    // ~MyBiDiCounter(); // Will not inherit the destructor from MyCounter

    using MyCounter::increment;
    void increment(unsigned value);
    void decrement();
    void print();
};

class MyAdvCounter : public MyCounter {
public:
    MyAdvCounter() : MyCounter() {
    }
    explicit MyAdvCounter(unsigned max) : MyCounter(max) {
    }
    MyAdvCounter(unsigned counter, unsigned max) : MyCounter(counter, max) {
    }
    MyAdvCounter(MyAdvCounter const& other) : MyCounter(other) {
    }

    void increment(); // Will override the increment method from MyCounter
    void print();
};

// The solution I would do for II.2 and V.1
// class BaseCounter {
// protected:
//     unsigned counter;
//     unsigned max;

// public:
//     unsigned getCounter() const {
//         return counter;
//     }
//     unsigned getMax() const {
//         return max;
//     }
//     void reset() {
//         counter = 0;
//     }
//     void set(unsigned value) {
//         counter = value;
//     }
//     void setMax(unsigned value) {
//         max = value;
//         if (value > counter)
//             counter = counter % max;
//     }

// protected:
//     BaseCounter() : counter(0), max(0) {
//     }
//     BaseCounter(unsigned theCounter, unsigned theMax)
//         : counter(theCounter), max(theMax) {
//     }
//     BaseCounter(const BaseCounter& anotherCounter)
//         : counter(anotherCounter.counter), max(anotherCounter.max) {
//     }
//     ~BaseCounter() {
//         std::cout << "Destruction: BaseCounter@" << this << std::endl
//     }

//     // This should be in .cpp file
//     void __increment() {
//         if (counter < max)
//             counter = counter + 1;
//         else
//             counter = 0;
//     }
//     void __decrement() {
//         if (counter > 0)
//             counter = counter - 1;
//         else
//             counter = max;
//     }
// };
// class ForwardCounter : public BaseCounter {
// public:
//     void increment() {
//         __increment();
//     }

//     ForwardCounter() : BaseCounter() {
//     }
//     ForwardCounter(const ForwardCounter& aCounter) : BaseCounter(aCounter) {
//     }
//     explicit ForwardCounter(unsigned theMaxValue)
//         : ForwardCounter(0, theMaxValue) {
//     }
//     ForwardCounter(unsigned theCounter, unsigned theMaxValue)
//         : BaseCounter(theCounter, theMaxValue) {
//     }
//     ~ForwardCounter() {
//         std::cout << "Destruction: ForwardCounter@" << this << std::endl
//     }
// };

// class BackwardCounter : public BaseCounter {
// public:
//     void decrement() {
//         __decrement();
//     }

//     BackwardCounter() : BaseCounter() {
//     }
//     BackwardCounter(const BackwardCounter& aCounter) : BaseCounter(aCounter)
//     {
//     }
//     explicit BackwardCounter(unsigned theMaxValue)
//         : BackwardCounter(0, theMaxValue) {
//     }
//     BackwardCounter(unsigned theCounter, unsigned theMaxValue)
//         : BaseCounter(theCounter, theMaxValue) {
//     }
//     ~BackwardCounter() {
//         std::cout << "Destruction: BackwardCounter@" << this << std::endl
//     }
// };

// class BiDiCounter : public BaseCounter {
// public:
//     void increment() {
//         __increment();
//     }
//     void decrement() {
//         __decrement();
//     }

//     BiDiCounter() : BaseCounter() {
//     }
//     BiDiCounter(const BiDiCounter& aCounter) : BaseCounter(aCounter) {
//     }
//     explicit BiDiCounter(unsigned theMaxValue)
//         : BaseCounter(0, theMaxValue) {
//     }
//     BiDiCounter(unsigned theCounter, unsigned theMaxValue)
//         : BaseCounter(theCounter, theMaxValue) {
//     }
//     ~BiDiCounter() {
//         std::cout << "Destruction: BiDiCounter@" << this << std::endl
//     }
// };