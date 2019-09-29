package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "xclate",
    srcs = [
        "fdrights.h",
        "fdrightsrecv.c",
        "fdrightssend.c",
        "fdrightswrapper.c",
        "machine.h",
        "main.c",
        "main.h",
        "mkdtemp.h",
    ],
    copts = [
        "-DLINUX",
        "-DHOSTOS=160400",
        "-DNEED_SETENV=0",
        "-Wno-expansion-to-defined",
        "-Wno-tautological-constant-out-of-range-compare",
    ],
)
