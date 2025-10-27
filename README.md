# Template_repo
Basic template repo for projects using bazel, cpp and python with linting and other functionalities.
Everything including the cpp toolchain is hermetic, the linters use the same binaries pulled by the bazel toolchain and does not depend on anything from the host system!

## Build
Build everything using
```
bazel build //...
```

Havent written any tests yet but to test everything
```
bazel test //...
```

## Ros 2
Comes with the [rules_ros](https://github.com/mvukov/rules_ros2). Some simple debugging tools have aliases such as
```
bazel run ros2_topic
bazel run ros2_bag
```

To run some simple examples
```
bazel run //example/python:py_talker

# In another terminal run 
bazel run //example/cpp:cpp_listener
```

## Linting
Contains the ruff linter for python
```
bazel run ruff check /workspaces/template_repo
bazel run ruff format /workspaces/template_repo
```

Has clang-tidy for cpp linting
```
bazel run clang_tidy
```

Buildifier for bazel linting
```
bazel run buildifier_check
bazel run buildifier_fix
```

## Other important comments
For vscode clangd extension to work properly please run
```
bazel run @hedron_compile_commands//:refresh_all
bazel run //tools/lint:setup_clangd
```
The above scripts generate the `compile_commands.json` file as well as the symlinks the clang config and executable to be picked up by the extension

The clangd extension does not show any formatting errors when working on the file, but whenever you save it auto formats the file!

I did not use [rules_lint](https://github.com/aspect-build/rules_lint) cause it had a lot of overhead with aspect and I found easier ways to set things up.

## Adding/updating deps
### For python
Simply add stuff to the [requirements.in](third_party/python/requirements.in) file and follow the instructions in this [doc](third_party/python/README.md)

### For cpp
Follow the same structure as the eigen module. Hopefully there is a bazel module that can easily be used, if not you will have to use a git_override rule.

## Sources
- [ruff bazel](https://github.com/philipuvarov/bazel-ruff)
- [bazel llvm](https://github.com/bazel-contrib/toolchains_llvm)
- [clang-tidy bazel](https://github.com/erenon/bazel_clang_tidy)
- [clang-format bazel](https://github.com/oliverlee/bazel_clang_format)
- [bazel compile command extractor](https://github.com/hedronvision/bazel-compile-commands-extractor) which makes vscode clangd extension work right
- [rules_ros2](https://github.com/mvukov/rules_ros2)

## What's done
- [x] bazel autocomplete
- [x] hermetic cpp toolchain llvm
- [x] hermetic cpp linting and formatting
- [x] hermetic python and ruff linting + formatting
- [x] setup aliases to make everything easier to check and run
- [x] get the clangd vscode toolchain to work with bazel
- [x] renovate bot
- [x] add bazel ros2
