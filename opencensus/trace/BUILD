# OpenCensus C++ Trace library.
# See ../../README.md for details.
#
# Copyright 2017, OpenCensus Authors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

licenses(["notice"])  # Apache 2.0

package(default_visibility = ["//visibility:private"])

cc_library(
    name = "trace",
    srcs = [
        "internal/annotation.cc",
        "internal/attribute_list.cc",
        "internal/attribute_value.cc",
        "internal/attribute_value_ref.cc",
        "internal/event_with_time.h",
        "internal/link.cc",
        "internal/local_span_store.cc",
        "internal/local_span_store_impl.cc",
        "internal/message_event.cc",
        "internal/running_span_store.cc",
        "internal/running_span_store_impl.cc",
        "internal/sampler.cc",
        "internal/span.cc",
        "internal/span_context.cc",
        "internal/span_data.cc",
        "internal/span_exporter.cc",
        "internal/span_exporter_impl.cc",
        "internal/span_id.cc",
        "internal/span_impl.cc",
        "internal/status.cc",
        "internal/trace_config.cc",
        "internal/trace_config_impl.cc",
        "internal/trace_id.cc",
        "internal/trace_options.cc",
    ],
    hdrs = [
        "attribute_value_ref.h",
        "exporter/annotation.h",
        "exporter/attribute_value.h",
        "exporter/link.h",
        "exporter/local_span_store.h",
        "exporter/message_event.h",
        "exporter/running_span_store.h",
        "exporter/span_data.h",
        "exporter/span_exporter.h",
        "exporter/status.h",
        "internal/attribute_list.h",
        "internal/local_span_store_impl.h",
        "internal/running_span_store_impl.h",
        "internal/span_exporter_impl.h",
        "internal/span_impl.h",
        "internal/trace_config_impl.h",
        "internal/trace_events.h",
        "internal/trace_params_impl.h",
        "sampler.h",
        "span.h",
        "span_context.h",
        "span_id.h",
        "status_code.h",
        "trace_config.h",
        "trace_id.h",
        "trace_options.h",
        "trace_params.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_absl//absl/base:core_headers",
        "@com_google_absl//absl/base:endian",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/time",
        "//opencensus/common/internal:random_lib",
    ],
)

# Tests
# ========================================================================= #

cc_test(
    name = "annotation_test",
    srcs = ["internal/annotation_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/strings",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "attribute_value_ref_test",
    srcs = ["internal/attribute_value_ref_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/strings",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "attribute_value_test",
    srcs = ["internal/attribute_value_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/strings",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "link_test",
    srcs = ["internal/link_test.cc"],
    deps = [
        ":trace",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "local_span_store_test",
    srcs = ["internal/local_span_store_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/synchronization",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "running_span_store_test",
    srcs = ["internal/running_span_store_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/synchronization",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "sampler_test",
    srcs = ["internal/sampler_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/time",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "span_test",
    srcs = ["internal/span_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/synchronization",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "span_id_test",
    srcs = ["internal/span_id_test.cc"],
    deps = [
        ":trace",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "span_options_test",
    srcs = ["internal/span_options_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/synchronization",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "span_context_test",
    srcs = ["internal/span_context_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/types:span",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "span_exporter_test",
    srcs = ["internal/span_exporter_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/time",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "status_test",
    srcs = ["internal/status_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/strings",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "trace_config_test",
    srcs = ["internal/trace_config_test.cc"],
    deps = [
        ":trace",
        "@com_google_absl//absl/time",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "trace_options_test",
    srcs = ["internal/trace_options_test.cc"],
    deps = [
        ":trace",
        "@com_google_googletest//:gtest_main",
    ],
)

# Benchmarks
# ========================================================================= #
#
cc_binary(
    name = "span_benchmark",
    testonly = 1,
    srcs = ["internal/span_benchmark.cc"],
    linkopts = ["-pthread"],  # Required for absl/synchronization bits.
    linkstatic = 1,
    deps = [
        ":trace",
        "@com_google_benchmark//:benchmark",
    ],
)

cc_binary(
    name = "span_id_benchmark",
    testonly = 1,
    srcs = ["internal/span_id_benchmark.cc"],
    linkopts = ["-pthread"],  # Required for absl/synchronization bits.
    linkstatic = 1,
    deps = [
        ":trace",
        "@com_google_benchmark//:benchmark",
    ],
)
