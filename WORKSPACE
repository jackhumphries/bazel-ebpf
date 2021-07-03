workspace(name = "com_jack_humphries_bazel_ebpf")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

http_archive(
    name = "rules_foreign_cc",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/99ea7e75c2a48cc233ff5e7682c1a31516faa84b.tar.gz",
    sha256 = "06fb31803fe3d2552f988f3c2fee430b10d566bc77dd7688897eca5388107883",
    strip_prefix = "rules_foreign_cc-99ea7e75c2a48cc233ff5e7682c1a31516faa84b",
)
load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")
rules_foreign_cc_dependencies()

# We clone Linux so that we can use libbpf and bpftool when compiling our eBPF
# programs.
new_git_repository(
    name = "linux",
    remote = "https://github.com/torvalds/linux",
    tag = "v5.13",
    build_file = "//:linux.BUILD",
)
