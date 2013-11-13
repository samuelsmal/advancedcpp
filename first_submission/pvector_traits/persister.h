//  persister.h
//  Persisters for use with pvector.
//  General persister followed by customized ones.

#include <complex>

template <typename T>
struct Persister {
  static void readInData(std::ifstream& ifs, std::vector<T>& v) {
    std::istream_iterator<T> input {ifs};
    std::istream_iterator<T> sentinel {};

    if (ifs) {
      for (; input != sentinel; ++input) v.push_back(*input);
    }
  }

  static void writeOutData(std::ofstream& ofs, std::vector<T>& v) {
    typename std::vector<T>::const_iterator b_itr = v.begin(), e_itr = v.end();

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

// A custom complex parser. It will allow a different format: real, imag
template <>
struct Persister<std::complex<int>> {
  static void readInData(std::ifstream& ifs, std::vector<std::complex<int>>& v) {
    int real, imag;

    char komma;

    while (ifs.good()) {
      ifs >> real >> komma >> imag;
      v.push_back({real, imag});
    }
  }

  static void writeOutData(std::ofstream& ofs, std::vector<std::complex<int>> v) {
    typename std::vector<std::complex<int>>::const_iterator b_itr = v.begin(), e_itr = v.end();

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
