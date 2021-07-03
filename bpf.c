#include "vmlinux.h"

// libbpf headers
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

SEC("raw_tracepoint/sys_enter")
int bpf_prog(struct bpf_raw_tracepoint_args *ctx) {
  return 0;
}
