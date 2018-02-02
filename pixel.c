#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>


int main() {

  int fd = open("pixel.ppm", O_CREAT | O_WRONLY | 0666);
  char * line = malloc(1000);
  char * append = malloc(10);
  int i = 0;
  line = "P3\n500 500\n255\n";
  write(fd, line, sizeof(line));
  for(;i < 255; i++) {
    line = "0 255 ";
    sprintf(append, "%d", 4);
    printf("%s\n", append);
    line = strcat(line, append);
    printf("%s\n", line);
    write (fd, line, sizeof(line));
  }
  free(line);
  free(append);
  close(fd);
  return 0;
}
