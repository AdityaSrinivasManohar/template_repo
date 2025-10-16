"""Ruff module extension for linting Python code."""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# buildifier: disable=unused-variable
def _ruff_ext_impl(ctx):
    ruff_version = "0.14.0"
    http_archive(
        name = "ruff-linux",
        build_file_content = 'exports_files(["ruff"])',
        strip_prefix = "ruff-x86_64-unknown-linux-gnu",
        sha256 = "28fe06f700caf99eee235f90e6e349f48b7f9a4b0d42e3ee5b3686f9259649a3",
        urls = [
            "https://github.com/astral-sh/ruff/releases/download/{0}/ruff-x86_64-unknown-linux-gnu.tar.gz".format(ruff_version),
        ],
    )

ruff = module_extension(implementation = _ruff_ext_impl)
