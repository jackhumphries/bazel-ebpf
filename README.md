<h2>Compile eBPF programs with Bazel</h2>

This repository contains the necessary scripts to compile eBPF programs,
generate skeleton headers from those eBPF programs, and compile the
corresponding userspace programs for Linux, all with Bazel.

<h4>Linux Version</h4>

The scripts in this repository target Linux 5.13. To target a different version
of Linux, open the `WORKSPACE` file, locate the Linux repository entry, and
update the tag to the one corresponding to the version of Linux you want to
target.

<h4>vmlinux.h</h4>

The vmlinux.h header in this repository is empty. You must replace vmlinux.h
with one derived from your own kernel vmlinux binary or the targets in this
repository will not build successfully.

<h4>Build Instructions</h4>

To build the targets in this repository, follow these instructions:

1. Install Bazel by following the instructions in the [Bazel Installation
   Guide](https://docs.bazel.build/versions/main/install.html).

2. Install the dependencies needed to compile eBPF programs and libbpf:
```
sudo apt update
sudo apt install libcap-dev libelf-dev libbfd-dev zlib1g-dev
```

Ensure that Clang and LLVM are installed as well. The scripts in this repository
expect Clang to be called `clang` though if it has another name (e.g.,
`clang-11`), then update `bpf.bzl` accordingly.

3. Replace vmlinux.h with one derived from your own kernel vmlinux binary.

4. Compile the eBPF program, generate the skeleton header from the eBPF
   program, and compile the corresponding userspace program:
```
bazel build -c opt :all
```

The eBPF object code, the skeleton header, and the userspace program are located
in the `bazel-bin` directory.
