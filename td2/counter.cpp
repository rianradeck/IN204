#include "counter.hpp"

unsigned MyCounter::getCounter() const {
    return counter;
}

unsigned MyCounter::getMax() const {
    return max;
}

void MyCounter::increment() {
    counter++;
    if (counter > max)
        counter = 0;
}

void MyCounter::reset() {
    counter = 0;
}

void MyCounter::set(unsigned value) {
    counter = (value <= max) ? value : counter;
}

void MyCounter::setMax(unsigned value) {
    if (counter >= value)
        counter = 0;
    max = value;
}

MyCounter::~MyCounter() {
    std::cout << "Deleting (" << counter << ", " << max << ")\n";
}

void MyCounter::print() {
    std::cout << "Counter: " << counter << "/" << max << "\n";
}

void MyBiDiCounter::increment(unsigned value) {
    counter = (counter + value) % (max + 1);
}

void MyBiDiCounter::decrement() {
    counter = (counter > 0) ? counter - 1 : max;
}

void MyBiDiCounter::print() {
    std::cout << "BiDi Counter: " << counter << "/" << max << "\n";
}

void MyAdvCounter::increment() {
    counter = std::min(max, counter + 1);
}

void MyAdvCounter::print() {
    std::cout << "Adv Counter: " << counter << "/" << max << "\n";
}