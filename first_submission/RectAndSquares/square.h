#ifndef SQUARE_H
#define SQUARE_H


class Square
{
  public:
    virtual unsigned int length() { return _length; }
    virtual void length(unsigned int val) { _length = val; }
  protected:
  private:
    unsigned int _length;
};

#endif // SQUARE_H
