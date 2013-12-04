//
//  RangedIterator.h
//  range_checking_itr
//
//  Created by Samuel von Bausznern on 04.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef range_checking_itr_RangedIterator_h
#define range_checking_itr_RangedIterator_h

#include <exception>
#include <stdexcept>

template <typename Itr>
class RangedIterator {
    const Itr begin, end;
    Itr current_position;
    
public:
    RangedIterator(Itr b, Itr e)
    : begin{b}, end{e}, current_position{b} {}
    
    RangedIterator& operator++() {
        if (current_position != end) {
            current_position++;
            return *this;
        } else {
            throw std::out_of_range("Out of bounds error!");
        }
    }
    
    RangedIterator& operator++(int) {
        // What now?
        // RangedIterator old {current_position};
        operator++();
        return *this;
    }
};

#endif
