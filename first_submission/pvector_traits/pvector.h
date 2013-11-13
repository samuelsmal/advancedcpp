#ifndef PVECTOR_H
#define PVECTOR_H

#include <vector>
#include <string>
#include <fstream>
#include <iterator>

#include "persister.h"

export
template <typename T,                // T models the type of the vector.
          typename P = Persister<T>> // P Models the type of the persister (see read and write).
class pvector {
  private:
    typedef P persister;
    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    std::string filename;
    std::vector<T> v;

void readVector();
void writeVector();/*
    void readVector() {
      std::ifstream ifs{filename};
      if(!persister::readInData(ifs, v)) {
        std::cerr << "Error in reading data." << std::endl;
      }
    }
    void writeVector() {
      std::ofstream ofs{filename};
      if (!persister::writeOutData(ofs, v)) {
        std::cerr << "Error in writing data." << std::endl;
      }
    }*/

  public:
    pvector(std::string fname) : filename {fname}, v {} {
      readVector();
    };
    ~pvector() {
      writeVector();
    };

    void push_back(const T &el) {
      v.push_back(el);
    }

    void pop_back() {
      if (v.size() > 0)
        v.pop_back();
    }

    size_t size() {
      return v.size();
    }

    bool empty() {
      return v.empty();
    }

    const T& back() const {
      return v.back();
    }

    T& operator[] (size_t i) {
      return v.at(i);
    }

    const T& operator[] (size_t i) const {
      return v.at(i);
    }

    typename std::vector<T>::iterator begin() {
      return v.begin();
    }

    typename std::vector<T>::iterator end() {
      return v.end();
    }

    typename std::vector<T>::const_iterator begin() const {
      return v.begin();
    }

    typename std::vector<T>::const_iterator end() const {
      return v.end();
    }
};

#include "_pvector.impl"

#endif // PVECTOR_H
