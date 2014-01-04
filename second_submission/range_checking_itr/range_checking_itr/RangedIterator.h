//
//  RangedIterator.h
//  range_checking_itr
//
//  Created by Samuel von Bausznern on 04.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//
//  This is a iterator wrapper, which checks for out-of-bounds erros.
//  I find it very hard to think through. Lots of pointer arithmetics.

#ifndef range_checking_itr_RangedIterator_h
#define range_checking_itr_RangedIterator_h

#include <exception>
#include <stdexcept>
#include <iterator>

template <typename Itr>
class RangedIterator {
  const Itr begin, end;
  Itr current_position;
  
  using value_type = typename std::iterator_traits<Itr>::value_type;
  using pointer    = typename std::iterator_traits<Itr>::pointer;
  using reference  = typename std::iterator_traits<Itr>::reference;
  
public:
  RangedIterator(Itr b, Itr e)
    : begin{b}, end{e}, current_position{b} {}
  
  RangedIterator(Itr b, Itr e, Itr pos)
    : begin{b}, end{e}, current_position{pos} {}
  
  RangedIterator& operator++() {
    if (current_position != end) {
      current_position++;
      return *this;
    } else {
      throw std::out_of_range("Out of bounds error (Overshot)!");
    }
  }
  
  RangedIterator& operator++(int) {
    RangedIterator old (begin, end, current_position);
    operator++();
    return *this;
  }
  
  RangedIterator& operator--() {
    if (current_position != begin) {
      current_position--;
      return *this;
    } else {
      throw std::out_of_range("Out of bounds error (Undershot)!");
    }
  }
  
  RangedIterator& operator--(int) {
    RangedIterator old (begin, end, current_position);
    operator--();
    return *this;
  }
  
  value_type operator*() {
    return *current_position;
  }
  
  pointer operator->() {
    return &*current_position;
  }
  
  friend inline bool operator==(const RangedIterator<Itr>& lhs, const RangedIterator<Itr>& rhs);
  friend inline bool operator!=(const RangedIterator<Itr>& lhs, const RangedIterator<Itr>& rhs);
};

template <typename Itr>
inline bool operator==(const RangedIterator<Itr>& lhs, const RangedIterator<Itr>& rhs) {
  return lhs.begin == rhs.begin
    && lhs.end == rhs.end
    && lhs.current_position == rhs.currentposition;
}

template <typename Itr>
inline bool operator!=(const RangedIterator<Itr>& lhs, const RangedIterator<Itr>& rhs) {
  return !(lhs == rhs);
}


#endif
