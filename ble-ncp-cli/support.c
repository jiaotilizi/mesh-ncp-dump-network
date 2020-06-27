#include <time.h>
#include <stdint.h>

void millisleep(uint32_t ms) {
  struct timespec remaining, duration;
  duration.tv_sec = ms / 1000;
  duration.tv_nsec = (ms - 1000*duration.tv_sec) * 1000000;
  do {
    nanosleep(&duration,&remaining);
  } while (remaining.tv_sec || remaining.tv_nsec);
}
