#include <mx-custom-op/CustomOp.h>

using namespace mx_custom_op;

class AddOp : public CustomOp {
public:
  int Forward(TVMDict kwargs) {
    TVMArgs &inputs = *kwargs["in_data"];
    DLTensor *a = inputs[0];
    DLTensor *b = inputs[0];
    TVMArgs &outputs = *kwargs["out_data"];
    DLTensor *c = outputs[0];
    CHECK(a->dtype.code == kDLFloat);
    CHECK(b->dtype.code == kDLFloat);
    CHECK(c->dtype.code == kDLFloat);
    CHECK_GT(c->ndim, 0);
    int64_t size = 1;
    for (int i = 0; i < c->ndim; ++i) {
      size *= c->shape[i];
    }
    float* a_data = static_cast<float*>(a->data);
    float* b_data = static_cast<float*>(b->data);
    float* c_data = static_cast<float*>(c->data);
    for (int i = 0; i < size; ++i) {
      c_data[i] = a_data[i] + b_data[i];
    }
    return 0;
  }
  int Backward(TVMDict kwargs) {
    return 0;
  }
};

int main() {
  LOG(INFO) << "HELLO";
  auto t = TVMArgs(0, 0, 0);
  LOG(INFO) << t.size(); 
  return 0;
}
