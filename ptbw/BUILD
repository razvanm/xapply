package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "ptbw",
    srcs = [
        "fdrights.h",
        "fdwrapper.c",
        "machine.c",
        "machine.h",
        "ptbw.c",
        "ptbw.h",
    ],
    copts = [
        "-DLINUX",
        "-DHOSTOS=160400",
        "-D_GNU_SOURCE",
        "-Wno-deprecated-non-prototype",
        "-Wno-expansion-to-defined",
        "-Wno-implicit-int",
        "-Wno-incompatible-pointer-types",
        "-Wno-unused-but-set-variable"
    ],
)
