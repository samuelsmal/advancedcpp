#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"


class Rectangle : public Square
{
  public:
    virtual unsigned int width() { return _width; }
    virtual void width(unsigned int val) { _width = val; }
  protected:
  private:
    unsigned int _width;
};

#endif // RECTANGLE_H
