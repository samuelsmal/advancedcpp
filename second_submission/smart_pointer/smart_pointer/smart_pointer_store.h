#ifndef smart_pointer_smart_pointer_store_h
#define smart_pointer_smart_pointer_store_h

//  TODO: Should handle the assignement of a raw pointer differently.
//    The obj shouldn't be deleted. Only when created by the wrapper.
//    Still assignement should be possible.

namespace pointer {
  namespace detail {
    
    class SmartPointerStore {
      unsigned count;
      
    public:
      void addRef() {++count;}
      unsigned releaseRef(){return --count;}
      
      // Only for the assignment:
      unsigned counter () {return count;}
    };
    

  }
}

#endif /* smart_pointer_smart_pointer_store_h */