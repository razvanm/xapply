package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "xapply",
    srcs = [
        "dicer.h",
        "fdrights.h",
        "fdwrapper.c",
        "machine.c",
        "machine.h",
        "main.c",
        "main.h",
    ],
    copts = [
        "-DLINUX",
        "-DHOSTOS=160400",
        "-DNEED_CSH_PAD=0",
        "-Wno-expansion-to-defined",
        "-Wno-incompatible-pointer-types",
        "-Wno-format",
    ],
)
