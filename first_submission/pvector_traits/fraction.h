 //
//  fraction.h
//  Fraction
//
//  Created by s0991462 on 9/24/13.
//  Copyright (c) 2013 SVB. All rights reserved.
//

#ifndef __Fraction__Fraction__
#define __Fraction__Fraction__

#include <iostream>

class Fraction {
    int _counter, _denom;

public:

    Fraction& operator= (const Fraction& that)
    {
        _counter = that.counter();
        _denom = that.denom();
        return *this;
    }
    Fraction(const Fraction& that) :
        _counter(that.counter()),
        _denom(that.denom()) {}
    Fraction(int c, int d) :_counter(c), _denom(d) {}
    Fraction() :_counter(0), _denom(1) {}
    ~Fraction() {}

    int counter() const {return _counter;}
    void counter(const int c) {_counter = c;}
    int denom() const {return _denom;}
    void denom(const int d) {_denom = d;}

    Fraction& reduce();
    Fraction reduce(Fraction f);

    Fraction& operator+= (const Fraction f) {
        _counter = _counter * f.denom() + _denom * f.counter();
        _denom *= f.denom();
        return *this;
    }
    Fraction& operator-= (const Fraction f) {
        _counter = _counter * f.denom() - _denom * f.counter();
        _denom *= f.denom();
        return *this;
    }
    Fraction& operator*= (const Fraction f) {
        _counter *= f.counter();
        _denom *= f.denom();
        return *this;
    }
    Fraction& operator/= (const Fraction f) {
        _counter *= f.denom();
        _denom *= f.counter();
        return *this;
    }
};

inline Fraction operator+(Fraction lhs, const Fraction rhs) {
    lhs += rhs;
    return lhs;
}

inline Fraction operator-(Fraction lhs, const Fraction rhs) {
    lhs -= rhs;
    return lhs;
}

inline Fraction operator*(Fraction lhs, const Fraction rhs) {
    lhs *= rhs;
    return lhs;
}

inline Fraction operator/(Fraction lhs, const Fraction rhs) {
    lhs /= rhs;
    return lhs;
}

inline bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return (lhs.counter() * rhs.denom()) == (rhs.counter() * rhs.denom());
}
inline bool operator!=(const Fraction& lhs, const Fraction& rhs) {return !operator==(lhs,rhs);}
inline bool operator< (const Fraction& lhs, const Fraction& rhs) {
    return (lhs.counter() * rhs.denom()) < (rhs.counter() * rhs.denom());
}
inline bool operator> (const Fraction& lhs, const Fraction& rhs) {return  operator< (rhs,lhs);}
inline bool operator<=(const Fraction& lhs, const Fraction& rhs) {return !operator> (lhs,rhs);}
inline bool operator>=(const Fraction& lhs, const Fraction& rhs) {return !operator< (lhs,rhs);}

inline std::ostream& operator<< (std::ostream& stream, const Fraction& Fraction) {
    return stream << Fraction.counter() << "/" << Fraction.denom();
}


// Should throw an error...
inline std::istream& operator>> (std::istream& stream, Fraction& obj) {
  int c, d;
  char t;
  stream >> c >> t >> d;
  obj.counter(c);
  obj.denom(d);
  return stream;
}

#endif /* defined(__Fraction__Fraction__) */
