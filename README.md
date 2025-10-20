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

One of the issues now is that it uses the host systems clang, but if you use a c++ toolchain in bazel then follow https://github.com/erenon/bazel_clang_tidy?tab=readme-ov-file#use-a-non-system-clang-tidy