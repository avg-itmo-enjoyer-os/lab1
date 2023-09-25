//
// Created by kharl on 16.09.2023.
//

#include "kernel/types.h"
#include "kernel/syscall.h"
#include "user/user.h"

#define SUCCESS 0

int main(void) {
  printf("Available pages: %d\n", get_free_pages());
  printf("Available mem: %d bytes\n", get_free_mem());

  exit(SUCCESS);
}