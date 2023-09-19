cc_test(
    name = "mindmath.test",
    srcs = glob(["src/*.cpp"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//mindmath:mindmath",
        "@googletest//:gtest_main"
    ],
)