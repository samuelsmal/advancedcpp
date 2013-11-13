//  pset_persister.h
//  Persisters for use with pvector.
//  General persister followed by customized ones.

//#include <complex>

template <typename T>
struct PSetPersister {
  static void readInData(std::ifstream& ifs, std::set<T>& v) {
    std::istream_iterator<T> input {ifs};
    std::istream_iterator<T> sentinel {};

    if (ifs) {
      for (; input != sentinel; ++input) v.insert(*input);
    }
  }

  static void writeOutData(std::ofstream& ofs, std::set<T>& v) {
    typename std::set<T>::const_iterator b_itr = v.begin(), e_itr = v.end();

    if (ofs) {
      if (b_itr != e_itr) {
        ofs << *b_itr++;
      }

      while (b_itr != e_itr) {
        ofs << std::endl << *b_itr++;
      }
    }
  }
};

// Will not work since complex has no operator<
/*
template <>
struct PSetPersister<std::complex<int>> {
  static void readInData(std::ifstream& ifs, std::set<std::complex<int>>& v) {
    int real, imag;

    char komma;

    while (ifs.good()) {
      ifs >> real >> komma >> imag;
      v.insert(std::complex<int>{real, imag});
    }
  }

  static void writeOutData(std::ofstream& ofs, std::set<std::complex<int>> v) {
    std::set<std::complex<int>>::const_iterator b_itr = v.begin(), e_itr = v.end();

    if (ofs) {
      if (b_itr != e_itr) {
        ofs << b_itr->real() << ", " << b_itr->imag();
        ++b_itr;
      }

      while (b_itr != e_itr) {
        ofs << std::endl << b_itr->real() << ", " << b_itr->imag();
        ++b_itr;
      }
    }
  }
};
*/
