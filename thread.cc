// Copyright 2010 Yunrang Inc. All Rights Reserved.
// Author: quj@yunrang.com (Jing Qu)

#include "thread.h"
#include <assert.h> 

namespace base {

void Thread::Start() {
  pthread_attr_t attr;
  assert(pthread_attr_init(&attr) == 0);
  assert(
      pthread_attr_setdetachstate(
          &attr,
          joinable_ ? PTHREAD_CREATE_JOINABLE : PTHREAD_CREATE_DETACHED) ==
      0);

  int result = pthread_create(&tid_, &attr, &ThreadRunner, this);
  assert(result == 0);

  assert(pthread_attr_destroy(&attr) == 0);
  started_ = true;
}

void Thread::Join() {
  assert(joinable_);
  int result = pthread_join(tid_, NULL);
  assert(result == 0);
}

}  // namespace base
