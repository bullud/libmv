// Copyright (c) 2009 libmv authors.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#ifndef LIBMV_MULTIVIEW_STRUCTURE_H_
#define LIBMV_MULTIVIEW_STRUCTURE_H_

#include "libmv/logging/logging.h"
#include "libmv/numeric/numeric.h"

namespace libmv {

class Structure {
 public:
  Structure();
  virtual ~Structure();
};

// The PointStructure class represents a localized 3D point in a
// coordinate frame
class PointStructure : public Structure {
 public:
  PointStructure();
  PointStructure(const Vec4 &coords);
  virtual ~PointStructure();

  const Vec3 coords() const { return Vec3(coords_(0), coords_(1), coords_(2)); }
  void set_coords(const Vec3 &coords)  { coords_ = Vec4(coords(0),
                                                        coords(1),
                                                        coords(2),
                                                        1); 
  }
  const Vec4 &homogeneous_coords() const          { return coords_; }
  void set_homogeneous_coords(const Vec4 &coords) { coords_ = coords; }
 private:
  // Contains the homogeneous position of a structure point
  Vec4 coords_;
};

}  // namespace libmv

#endif  // LIBMV_MULTIVIEW_STRUCTURE_H_
