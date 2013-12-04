//
//  main.cpp
//  template_merge
//
//  Created by Samuel von Bausznern on 04.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//
//  For this exercise I used the coding style from the STL.
//  It's basically a reproduction of the STL implementation.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <cstdlib>
#include <algorithm>

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

void vector_test(const std::size_t num_of_items) {
    std::vector<int> v1, v2, dst;
    
    // fill the vectors
    for (std::size_t idx = 0; idx < num_of_items; ++idx) {
        v1.push_back(std::rand()%num_of_items);
        v2.push_back(std::rand()%num_of_items);
    }
    
    // sort
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    
    // output v1
    std::cout << "   v1: ";
    sam::copy(v1.begin(), v1.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    
    // output v2
    std::cout << "   v2: ";
    sam::copy(v2.begin(), v2.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    
    // merge
    sam::merge(v1.begin(), v1.end(),
               v2.begin(), v2.end(),
               std::back_inserter(dst));
    
    // output
    std::cout << "v_dst: ";
    std::copy(dst.begin(), dst.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

void list_test(const std::size_t num_of_items) {
    std::list<int> l1, l2, ldist;
    
    for (std::size_t idx = 0; idx < num_of_items; ++idx) {
        l1.push_back(std::rand()%num_of_items);
        l2.push_back(std::rand()%num_of_items);
    }
    
    // output l1
    std::cout << "   l1: ";
    std::copy(l1.begin(), l1.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    
    // output l2
    std::cout << "   l2: ";
    sam::copy(l2.begin(), l2.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    
    // merge
    sam::merge(l1.begin(), l1.end(),
               l2.begin(), l2.end(),
               std::back_inserter(ldist));
    
    // output
    std::cout << "l_dst: ";
    sam::copy(ldist.begin(), ldist.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

void mixed_test(const std::size_t num_of_items) {
    std::list<int> l;
    std::vector<int> v;
    std::set<int> s;
    
    for (std::size_t idx = 0; idx < num_of_items; ++idx) {
        l.push_back(std::rand()%num_of_items);
        v.push_back(std::rand()%num_of_items);
    }
    
    // output l
    std::cout << "    l: ";
    sam::copy(l.begin(), l.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    
    // output v
    std::cout << "    v: ";
    sam::copy(v.begin(), v.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    
    // merge
    sam::merge(l.begin(), l.end(),
               v.begin(), v.end(),
               std::inserter(s, s.begin()));
    
    // output
    std::cout << "    s: ";
    sam::copy(s.begin(), s.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

int main(int argc, const char * argv[])
{
    const std::size_t items = 10;
    std::srand(std::time(0));
    
    std::cout << "Vector test" << "\n";
    vector_test(items);
    std::cout << "List test" << "\n";
    list_test(items);
    std::cout << "Mixed test" << "\n";
    mixed_test(items);
    
    return 0;
}

