//
//  smart_pointer.h
//  smart_pointer
//
//  Created by Samuel von Bausznern on 27.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//
//  This is my smart pointer or shared pointer.
//  It uses reference counting to keep track of the different shareholders.
//
//  I'm not satisfied with the implementation. For starters it's too greedy.
//  It should only take ownership when assigned with a new object.
//  Like SmartPointer<ObjType> sp (new ObjType());
//  Not  SmartPointer<ObjType> sp (pointer to already instantiated obj);
//

#ifndef smart_pointer_smart_pointer_h
#define smart_pointer_smart_pointer_h

#include <cstddef>

#include "smart_pointer_store.h"

namespace pointer {
  
template <typename T> // T models the Object
class SmartPointer {
  typedef T* StoredType;
  typedef T* PointerType;
  typedef T& ReferenceType;
  
  StoredType pointee; // Data
  
  detail::SmartPointerStore* store;
  
public:
  //  This is to prevent a memory leak in the process of object instantiation.
  //  Learned from GoingNative14 Stephan T. Lavavej's "Don't help the compiler lecture"
  SmartPointer() : pointee(nullptr), store(nullptr) {}
  
  SmartPointer(StoredType ptr) : SmartPointer() {
    pointee = ptr;
    store = new detail::SmartPointerStore();
    store->addRef();
  }
  
  SmartPointer(const SmartPointer<T>& sp) : pointee(sp.pointee), store(sp.store) {
    store->addRef();
  }
  
  SmartPointer& operator=(const SmartPointer<T>& sp) {
    if (this != &sp) {
      if (store->releaseRef() == 0) {
        delete store;
        delete pointee;
      }
      
      pointee = sp.pointee;
      store = sp.store;
      store->addRef();
    }
    
    return *this;
  }
  
  ~SmartPointer() {
    if (pointee != nullptr) {
      if (store->releaseRef() == 0) {
        delete store;
        delete pointee;
      }
    }
  }
  
  ReferenceType operator*()  const {return *pointee;}
  PointerType   operator->() const {return pointee;}
  
  // Only for the assignement.
  unsigned counter() {
    if (pointee == nullptr) {
      return 0; // but should throw something
    }
    return store->counter();
  }
  
};
  
}
#endif