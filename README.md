# Template_repo
Basic template repo for projects using bazel, cpp and python with linting and other functionalities.
Everything including the cpp toolchain is hermetic, the linters use the same binaries pulled by the bazel toolchain and does not depend on anything from the host system!

## Build
Build everything using
```
bazel build //...
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

## Sources
- [ruff bazel](https://github.com/philipuvarov/bazel-ruff)
- [bazel llvm](https://github.com/bazel-contrib/toolchains_llvm)
- [clang-tidy bazel](https://github.com/erenon/bazel_clang_tidy)
- [clang-format bazel](https://github.com/oliverlee/bazel_clang_format)
- [bazel compile command extractor](https://github.com/hedronvision/bazel-compile-commands-extractor) which makes vscode clangd extension work right

## What's done
- [x] hermetic cpp toolchain llvm
- [x] hermetic cpp linting and formatting
- [x] hermetic python and ruff linting + formatting
- [x] setup aliases to make everything easier to check and run
- [x] get the clangd vscode toolchain to work with bazel

## Next Steps
- [ ] renovate bot
- [ ] add bazel ros2