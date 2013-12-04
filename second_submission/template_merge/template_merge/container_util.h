//
//  container_util.h
//  template_merge
//
//  Created by Samuel von Bausznern on 04.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef template_merge_container_util_h
#define template_merge_container_util_h

namespace sam {
    
    // I use 'class' instead of 'typename' to hint to the user,
    // that a class is expected and not a basic type like int.
    
    template <class InputIt, class OutPutItr>
    OutPutItr copy(InputIt first, InputIt last, OutPutItr target) {
        for (; first != last; ++target, ++first) {
            *target = *first;
        }
        return target;
    }
    
    // InputIt1 must meet the requirements of InputIterator.
    // InputIt2 must meet the requirements of InputIterator.
    // OutputIt must meet the requirements of OutputIterator.
    template <class InputItr1,
    class InputItr2,
    class OutputItr>
    OutputItr merge(InputItr1 first_begin, InputItr1 first_end,
                    InputItr2 second_begin, InputItr2 second_end,
                    OutputItr target_begin) {
        for (; first_begin != first_end; ++target_begin) {
            if (second_begin == second_end) {
                return sam::copy(first_begin, first_end, target_begin);
            }
            // To preserve order, if there's any.
            if (*second_begin < *first_begin) {
                *target_begin = *second_begin++;
            } else {
                *target_begin = *first_begin++;
            }
        }
        
        return sam::copy(second_begin, second_end, target_begin);
    }
    
}

#endif
