# Template_repo
Basic template repo for projects using bazel, cpp and python with linting and other functionalities

Build everything using
```
bazel build //...
```

Contains the ruff linter for python
```
bazel run ruff check /workspaces/template_repo
```

Has clang-tidy for cpp linting
```
bazel run clang_tidy
```
