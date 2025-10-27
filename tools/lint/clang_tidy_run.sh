#!/usr/bin/env bash
set -e

cd "$BUILD_WORKSPACE_DIRECTORY"
bazel build //example/... --config clang-tidy