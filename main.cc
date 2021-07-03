#include <iostream>

// libbpf headers
#include <bpf/bpf.h>
#include <bpf/libbpf.h>

// skeleton header
#include "bpf.skel.h"

int main(int argc, char* argv[]) {
  std::cout << "Hello world!" << std::endl;

  return 0;
}
