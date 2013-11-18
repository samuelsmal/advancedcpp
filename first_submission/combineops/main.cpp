#include <iostream>
#include <functional>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

// Note:
// unary_function is deprecated in C++11. Its functionality has been made obsolete by std::function.

template <typename BinOp, typename Op1, typename Op2>
class combineops_t :
  public unary_function<typename Op1::argument_type, typename BinOp::result_type> {
  protected:
    BinOp o;
    Op1 o1;
    Op2 o2;
  public:
    combineops_t(BinOp binop, Op1 op1, Op2 op2) : o(binop), o1(op1), o2(op2) {}
    typename BinOp::result_type operator()(const typename Op1::argument_type &x) {
      return o(o1(x),o2(x));
    }
};

struct concatLowerToUpper : public binary_function<std::string, std::string, std::string> {
  std::string operator()(const std::string& a, const std::string& b) {
    return a + b;
  }
};

struct toUpper : public unary_function<std::string, std::string> {
  std::string operator()(const std::string& s) {

    string tmp(s);

    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);

    return tmp;
  }
};

struct toLower : public unary_function<std::string, std::string> {
  std::string operator()(const std::string& s) {
    string tmp(s);

    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

    return tmp;
  }
};

int main()
{
  concatLowerToUpper strBinOp;
  toUpper toUpperObj;
  toLower toLowerObj;

  combineops_t<concatLowerToUpper, toLower, toUpper> foo(strBinOp, toLowerObj, toUpperObj);

  string a = "MixEDCASESssss";
  cout << foo(a) << endl;
  return 0;
}
