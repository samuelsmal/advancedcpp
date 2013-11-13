#include <vector>
#include <string>
#include <fstream>
#include <iterator>

template <typename T>
class pvector {
  private:
    std::string filename;
    std::vector<T> v;

    void readVector() {
      std::ifstream ifs{filename};

      std::istream_iterator<T> input{ifs};
      std::istream_iterator<T> sentinel{};

      if (ifs) {
        for (; input != sentinel; ++input)
          v.push_back(*input);
      }
    }

    void writeVector() {
      std::ofstream ofs {filename};
      typename std::vector<T>::const_iterator b_itr = v.begin(), e_itr = v.end();

      if (b_itr != e_itr) {
        ofs << *b_itr++;
      }

      while (b_itr != e_itr) {
        ofs << std::endl << *b_itr++;
      }
    }

  public:
    pvector(std::string fname) : filename(fname), v{} {
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
};
