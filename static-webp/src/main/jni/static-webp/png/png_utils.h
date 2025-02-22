/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef _PNG_UTILS_H_
#define _PNG_UTILS_H_

namespace facebook {
namespace imagepipeline {
namespace png {

#include <png.h>

/**
 * RAII wrapper for png_struct and png_info which are basic libpng
 * structures that require destruction.
 */
class PngStructGuard {
 public:
  /**
   * Create PngStructGuard initializing it with pointer to png_struct
   */
  PngStructGuard(png_structp pngStructP)
    : pngStructP_(pngStructP), pngInfoP_(nullptr) {}

  /**
   * Release libpng resources.
   */
  ~PngStructGuard() {
    png_destroy_write_struct(&pngStructP_, &pngInfoP_);
  }

  /**
   * Associate png_info with the guard.
   */
  void setInfoPtr(png_infop pngInfoP) { pngInfoP_ = pngInfoP; }

 private:
  png_structp pngStructP_;
  png_infop pngInfoP_;
};

} } }

#endif /* _PNG_UTILS_H_ */
