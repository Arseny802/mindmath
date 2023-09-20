cc_library(
  name = "mindmath.console.internal",
  srcs = glob(["src/printer.cpp"]),
  hdrs = glob(["src/*.h"]),
  visibility = ["//console:__subpackages__"],
  deps = ["//mindmath:mindmath"]
)

cc_binary(
  name = "mindmath.console",
  srcs = glob(["src/main.cpp", "src/*.h"]),
  deps = ["//console:mindmath.console.internal"]
)