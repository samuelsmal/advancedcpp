//
//  dumb_pointer.h
//  pointers
//
//  Created by Samuel von Bausznern on 28.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//
//  Additional wrapper. Nothing more. Dumb as it gets.

#ifndef pointers_dumb_pointer_h
#define pointers_dumb_pointer_h

namespace pointer {

template <typename T> // T models the pointee.
class DumbPointer {
  typedef T* StoredType;
  typedef T* PointerType;
  typedef T& ReferenceType;
  
  StoredType pointee;
  
public:
  explicit DumbPointer(StoredType obj) : pointee(obj) {};
  
  DumbPointer(const DumbPointer<T>& another) : pointee(another.pointee) {};
  
  DumbPointer& operator=(const DumbPointer<T>& dp) {
    pointee = dp.pointee;
  }
  
  
  // Either that or a cast. Which would be even dumber.
  void deletePointee() {
    delete pointee;
  }
  
  ReferenceType operator*()  const {return *pointee;}
  PointerType   operator->() const {return pointee;}
  
};
  
}

#endif
