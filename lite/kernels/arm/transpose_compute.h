// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <algorithm>
#include <vector>
#include "lite/core/kernel.h"
#include "lite/operators/transpose_op.h"

namespace paddle {
namespace lite {
namespace kernels {
namespace arm {

// Transpose
class TransposeCompute : public KernelLite<TARGET(kARM), PRECISION(kFloat)> {
 public:
  using param_t = operators::TransposeParam;
  void PrepareForRun() override;
  void Run() override;
  void ReInitWhenNeeded() override;

  virtual ~TransposeCompute() = default;

 private:
  bool need_trans = false;
  bool trans_mat = false;
  int _trans_num;
  int _trans_w;
  int _trans_h;
  DDim last_shape_;
  std::vector<int> _new_steps;
  std::vector<int> _old_steps;
};

// Transpose2
class Transpose2Compute : public TransposeCompute {
 public:
  virtual ~Transpose2Compute() = default;
};

}  // namespace arm
}  // namespace kernels
}  // namespace lite
}  // namespace paddle
