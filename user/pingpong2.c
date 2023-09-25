//
// Created by kharl on 15.09.2023.
//
#include "kernel/types.h"
#include "kernel/syscall.h"
#include "user/user.h"

#define SUCCESS 0
#define EXCHANGES_AMOUNT 5000
#define TICK_RATE 10

uint64 benchmark() {
  int p1[2], p2[2];
  pipe(p1);
  pipe(p2);

  int start;
  if (fork() != 0) {
    close(p1[0]);
    close(p2[1]);
    char ping[1] = "-";

    start = uptime();
    for (int i = 0; i < EXCHANGES_AMOUNT; i++) {
      write(p1[1], ping, 1);
      read(p2[0], ping, 1);
    }
    wait(NULL);

    close(p1[1]);
    close(p2[0]);
  } else {
    close(p1[1]);
    close(p2[0]);
    char pong[1];

    for (int j = 0; j < EXCHANGES_AMOUNT; j++) {
      read(p1[0], pong, 1);
      write(p2[1], pong, 1);
    }
    close(p1[0]);
    close(p2[1]);
    exit(SUCCESS);
  }

  return (uint64)(EXCHANGES_AMOUNT * TICK_RATE / (uptime() - start));
}

int main(void) {
  printf("-- Benchmark started --\n");

  uint64 sum = 0;
  const int repeats = 5;
  for (int i = 0; i < repeats; ++i) {
    uint64 cur = benchmark();
    printf("#%d iteration: %d exchanges per second\n", i + 1, cur);
    sum += cur;
  }
  printf("\nAvg: %d exchanges per second\n", (uint64)(sum / repeats));

  printf("-- Benchmark ended --\n");
  exit(SUCCESS);
}