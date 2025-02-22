/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <jni.h>

extern jclass jRuntimeException_class;

namespace facebook {
namespace imagepipeline {

void safeThrowJavaException(JNIEnv*, jclass, const char*);

} }

#define THROW_AND_RETURN_IF(condition, message)                         \
  do {                                                                  \
    if (condition) {                                                    \
      facebook::imagepipeline::safeThrowJavaException(                  \
          env,                                                          \
          jRuntimeException_class,                                      \
          message);                                                     \
      return;                                                           \
    }                                                                   \
  } while (0)

#define THROW_AND_RETURNVAL_IF(condition, message, return_value)        \
  do {                                                                  \
  if (condition) {                                                      \
      facebook::imagepipeline::safeThrowJavaException(                  \
          env,                                                          \
          jRuntimeException_class,                                      \
          message);                                                     \
      return return_value;                                              \
    }                                                                   \
  } while (0)

#define RETURN_IF_EXCEPTION_PENDING                                     \
  do {                                                                  \
    if (env->ExceptionCheck()) {                                        \
      return;                                                           \
    }                                                                   \
  } while (0)

#define RETURNVAL_IF_EXCEPTION_PENDING(return_value)                    \
  do {                                                                  \
    if (env->ExceptionCheck()) {                                        \
      return return_value;                                              \
    }                                                                   \
  } while (0)

#endif /* _EXCEPTIONS_H_ */
