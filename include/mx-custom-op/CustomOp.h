#pragma once

#include <string>
#include <map>
#include <tvm/runtime/packed_func.h>

namespace mx_custom_op {

using tvm::runtime::TVMArgs;

using TVMDict = std::map<std::string, TVMArgs*>;

class CustomOp {
public:
  virtual int Forward(TVMDict kwargs) = 0;
  virtual int Backward(TVMDict kwargs) = 0;
};

}
