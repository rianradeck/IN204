// Part 4: Geometry
// I did not finished this
// https://perso.ensta-paris.fr/~bmonsuez/Cours/doku.php?id=in204:tds:sujets:td1:part4

#include <bits/stdc++.h>

class Point {
private:
    int _x, _y;

public:
    Point(int x, int y) : _x(x), _y(y) {
    }

    int getX() const {
        return _x;
    }

    int getY() const {
        return _y;
    }
};

class Segment {
private:
    Point _p1, _p2;

public:
    Segment(Point& p1, Point& p2) : _p1(p1), _p2(p2) {
        if (p1.getX() > p2.getX()) {
            std::swap(_p1, _p2);
            std::cout << "SWAP\n";
        }
    }

    Point getP1() const {
        return _p1;
    }

    Point getP2() const {
        return _p2;
    }

    bool contains(Point p) const {
        int maxX = std::max(_p1.getX(), _p2.getX());
        int minX = std::min(_p1.getX(), _p2.getX());
        int maxY = std::max(_p1.getY(), _p2.getY());
        int minY = std::min(_p1.getY(), _p2.getY());
        if (p.getX() < minX or maxX < p.getX())
            return false;
        if (p.getY() < minY or maxY < p.getY())
            return false;

        return std::abs((p.getX() - _p1.getX()) * (_p2.getY() - _p1.getY())) ==
               std::abs((p.getY() - _p1.getY()) * (_p2.getX() - _p1.getX()));
    }

    bool intersects(Segment s) const {
        return contains(s.getP1()) || contains(s.getP2()) || s.contains(_p1) ||
               s.contains(_p2);
    }
};

class Frac {
private:
    int _num, _den;

public:
    Frac(int num, int den) : _num(num), _den(den) {
    }

    int getNum() const {
        return _num;
    }

    int getDen() const {
        return _den;
    }

    Frac operator+(Frac f) const {
        return Frac(_num * f._den + f._num * _den, _den * f._den);
    }

    Frac operator-(Frac f) const {
        return Frac(_num * f._den - f._num * _den, _den * f._den);
    }

    Frac operator*(Frac f) const {
        return Frac(_num * f._num, _den * f._den);
    }

    Frac operator/(Frac f) const {
        return Frac(_num * f._den, _den * f._num);
    }
};

class Vector {
private:
    Frac _magnitude;
    Point _direction;

public:
    Vector(Frac magnitude, Point direction)
        : _magnitude(magnitude), _direction(direction) {
    }
    Vector(Point p)
        : _magnitude(
              Frac(std::sqrt(p.getX() * p.getX() + p.getY() * p.getY()), 1)),
          _direction(p) {
    }

    Frac norm2() const {
        return _magnitude * _magnitude;
    }
};

class Line {
private:
    Point _p;
    Vector _v;

public:
    Line(Point p1, Point p2)
        : _p(p1),
          _v(Vector(Point(p2.getX() - p1.getX(), p2.getY() - p1.getY()))) {
    }
    Line(Point p, Vector v) : _p(p), _v(v) {
    }

    Point getPoint() const {
        return _p;
    }

    Vector getVector() const {
        return _v;
    }
};