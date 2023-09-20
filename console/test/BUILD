cc_test(
    name = "mindmath.console.test",
    srcs = glob(["src/*.cpp"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//console:mindmath.console.internal",
        "@googletest//:gtest_main"
    ],
)