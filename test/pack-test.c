#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "cn-cbor/cn-cbor.h"

#define ERROR(msg, p) fprintf(stderr, "ERROR: " msg " %s\n", (p));

int main() {
  uint8_t buf[100000];
  ssize_t written;

  //  written = cn_cbor_pack(buf, sizeof(buf), "abc%d%sxyz!\n", 17, "hello");
  written = cn_cbor_pack(buf, sizeof(buf), "ABCD%d%s", 17, "abc");
  if (written >= 0) {
    printf("%.*s", (int)written, buf);
  }
  
  return 0;
}

