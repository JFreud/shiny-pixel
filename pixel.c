#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>


int main() {
  int fd = open("pixel.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  float r,g,b;
  if (fd < 0) {
    printf("bad\n");
    printf("%s\n", strerror(errno));
  }
  char line[1000];
  int i = 0;
  int j = 0;
  sprintf(line, "P3\n750\n750\n255\n");
  write(fd, line, strlen(line));
  for(j = 0;j < 750; j++) {
    for(i = 0;i < 750; i++) {
      if ((pow(i, 2) + pow(j, 2)) < pow(500, 2)) {
        r = sqrt(i * j);
        g = sqrt(i / (j + 1));
      }
      else {
        r = i + j;
        g = i - j;
      }
      b = (int)sqrt(i) * (int)(sqrt(j) + 1);
      // printf("hi\n");
      r = abs((int)r) % 255;
      g = abs((int)g) % 255;
      b = abs((int)b) % 255;
      sprintf(line, "%d %d %d ", (int)r, (int)g, (int)b);
      // printf("hi\n");
      // printf("%s\n", append);
      write (fd, line, strlen(line));
    }
    write (fd, "\n", 1);
  }
  // free(line);
  close(fd);
  return 0;
}
