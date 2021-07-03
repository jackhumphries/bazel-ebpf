load("bpf.bzl", "bpf_program")
load("bpf.bzl", "bpf_skeleton")

# The eBPF program.
bpf_program(
    name = "bpf",
    src = "bpf.c",
    hdrs = [
        "vmlinux.h",
    ],
    bpf_object = "bpf.o",
)

# The skeleton header file generated from the eBPF program.
bpf_skeleton(
    name = "bpf_skel",
    bpf_object = ":bpf",
    skel_hdr = "bpf.skel.h",
)

# The userspace program.
cc_binary(
    name = "main",
    srcs = [
        "main.cc",
        "bpf.skel.h",
    ],
    linkopts = [
        "-lelf",
        "-lz",
    ],
    deps = [
        "@linux//:libbpf",
    ],
)
