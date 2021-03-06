//
//  main.cpp
//  pointers
//
//  Created by Samuel von Bausznern on 27.12.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#include <iostream>

#include "smart_pointer.h"
#include "dumb_pointer.h"

using namespace std;
using namespace pointer;

class DummyObject {
public:
  int variable;
  
  DummyObject(int i) : variable(i) {}
  
  void memberFunction () {
    cout << "dummy object with variable " << variable << endl;
  }
};

void SmartPointerTest() {
  cout << "Smart pointer test" << endl;
  
  DummyObject *o1 = new DummyObject(1);
  DummyObject *o2 = new DummyObject(2);
  
  SmartPointer<DummyObject> p(o1);
  cout << p.counter() << endl;
  
  SmartPointer<DummyObject> q(p);
  
  cout << p.counter() << " " << q.counter() << endl;
  
  SmartPointer<DummyObject> r(o2);
  cout << r.counter() << endl;
  
  q = r;
  
  SmartPointer<DummyObject> s(new DummyObject(3));
  
  cout << p.counter() << endl;
  cout << q.counter() << endl;
  cout << r.counter() << endl;
  cout << s.counter() << endl;
  
  cout << "p:" << p->variable << endl;
  cout << "q:" << q->variable << endl;
  cout << "r:" << r->variable << endl;
  cout << "s:" << s->variable << endl;
  
  p->variable *= -1;
  q->variable *= -1;
  r->variable *= -1;
  s->variable *= -1;
  
  p->memberFunction();
  q->memberFunction();
  r->memberFunction();
  s->memberFunction();
}

void DumbPointerTest() {
  cout << "Dumb pointer test" << endl;
  
  DummyObject *o1 = new DummyObject(1);
  
  DumbPointer<DummyObject> dp1 (o1);
  DumbPointer<DummyObject> dp2 (dp1);
  
  dp1->memberFunction();
  dp2->memberFunction();
  
  DumbPointer<DummyObject> dp3 (new DummyObject(2));
  
  dp3->memberFunction();
  
  dp3.deletePointee();
  delete o1;
  
}

int main(int argc, const char * argv[])
{
  SmartPointerTest();
  DumbPointerTest();
  return 0;
}

