#include <bits/stdc++.h>

#include "counter.hpp"

void testMyBiDiCounter() {
    MyBiDiCounter counterA(4);
    // counterA.setMax(4);
    counterA.reset();
    counterA.print();
    for (int i = 0; i < 6; i++) {
        counterA.increment();
        counterA.print();
    }
    for (int i = 0; i < 6; i++) {
        counterA.decrement();
        counterA.print();
    }
}

void testOldIncMethod() {
    MyBiDiCounter bidiCounter1(0, 5);
    for (unsigned i = 0; i <= 5; i++) {
        bidiCounter1.increment();
        bidiCounter1.print();
    }
}

void testNewIncMethod() {
    MyBiDiCounter bidiCounter1(0, 5);
    for (unsigned i = 0; i <= 5; i++) {
        bidiCounter1.increment(5);
        bidiCounter1.print();
    }
}

void testMyAdvCounter() {
    MyAdvCounter incCounter(0, 4);
    for (int i = 0; i < 6; i++) {
        incCounter.increment();
        incCounter.print();
    }
}

void testCounter(MyCounter& unCompteur) {
    for (int i = 0; i < 6; i++) {
        unCompteur.increment();
        unCompteur.print();
    }
    std::cout << "\n";
}

int main() {
    // testNewIncMethod();
    // testOldIncMethod();
    // testMyAdvCounter();
    MyBiDiCounter BiDi(0, 4);
    MyAdvCounter Adv(0, 4);
    testCounter(BiDi);
    testCounter(Adv);
    return 0;
}