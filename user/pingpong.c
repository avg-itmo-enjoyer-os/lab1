//
// Created by kharl on 12.09.2023.
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define SUCCESS 0

int main(int argc, char **argv) {
  int pipe_ends[2];
  pipe(pipe_ends);

  if (fork() == 0) {
    char msg[16];
    read(pipe_ends[0], msg, 5);
    printf("%d: got message %s", getpid(), msg);
    write(pipe_ends[1], "pong\n", 5);
    exit(SUCCESS);
  } else {
    write(pipe_ends[1], "ping\n", 5);
    wait(NULL);
    char msg[16];
    read(pipe_ends[0], msg, 5);
    printf("%d: got message %s", getpid(), msg);
  }

  exit(SUCCESS);
}