//
//  manipulator.h
//  manipulators
//
//  Created by Samuel von Bausznern on 08.01.14.
//  Copyright (c) 2014 Samuel von Bausznern. All rights reserved.
//

#ifndef manipulators_manipulator_h
#define manipulators_manipulator_h

using namespace std;

class manipulator {
public:
  static ostream& scientific(ostream& s) {
    s.setf(ios_base::scientific, ios_base::floatfield);
    return s;
  }
  
  static ostream& reset(ostream& s) {
    s.unsetf(ios_base::scientific);
    return s;
  }
  
  static ostream& prec_float(ostream& s) {
    s.precision(10);
    return s;
  }
};

#endif
