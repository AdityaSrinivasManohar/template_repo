# Template_repo
Basic template repo for projects using bazel, cpp and python with linting and other functionalities

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

## Other important scripts
For vscode clangd extension to work properly please run
```
bazel run @hedron_compile_commands//:refresh_all
bazel run //tools/lint:setup_clangd
```
The above scripts generate the `compile_commands.json` file as well as the symlinks the clang config and executable to be picked up by the extension