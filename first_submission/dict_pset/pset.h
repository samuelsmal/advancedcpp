// pset.h
// Persistent set.
// Saves the set in a [filename] file.

// Not that a simple
/*
template <typename T>
class pset : public std::set<T> {
 private:
  std::string filename

 public:
  ...
*/
// With overwriting the special methods would have been quicker...

#ifndef PSET_H
#define PSET_H

#include <set>
#include <string>
#include <fstream>
#include <iterator>
#include <initializer_list>
#include <utility>

#include "pset_persister.h"

export
template <typename T,                // T models the type of the set.
          typename P = PSetPersister<T>> // P Models the type of the persister (see read and write).
class pset {
  private:
    typedef P persister;
    typedef typename std::set<T>::iterator iterator;
    typedef typename std::set<T>::const_iterator const_iterator;

    std::string filename;
    std::set<T> s;

    void readSet();
    void writeSet();

  public:
    pset(std::string fname) : filename {fname}, s {} {
      readSet();
    };
    ~pset() {
      writeSet();
    };

    size_t size() {
      return s.size();
    }

    bool empty() {
      return s.empty();
    }

    size_t count(const T& key) const {
      return s.count(key);
    }

    void clear() {
      s.clear();
    }

    void erase(iterator pos) {
      s.erase(pos);
    }

    void erase(iterator first, iterator last) {
      s.erase(first, last);
    }

    size_t erase(const T& key) {
      return s.erase(key);
    }

    std::pair<iterator, bool> insert (const T& value) {
      return s.insert(value);
    }

    void insert (typename std::initializer_list<T> iList) {
      s.insert(iList);
    }
/* TODO: Make this work. Solution: Install gcc 4.8.
    std::pair<iterator, bool> emplace(T&& arg) {
      return s.emplace(arg);
    }*/

    typename std::set<T>::iterator find (const T& key) {
      return s.find(key);
    }

    typename std::set<T>::const_iterator find (const T& key) const {
      return s.find(key);
    }

    typename std::set<T>::iterator begin() {
      return s.begin();
    }

    typename std::set<T>::iterator end() {
      return s.end();
    }

    typename std::set<T>::const_iterator begin() const {
      return s.begin();
    }

    typename std::set<T>::const_iterator end() const {
      return s.end();
    }
};

#include "_pset.impl"

#endif // PSET_H
