### To update py deps
Once you update requirments.in, run
```sh
bazel run //utils/python:py_requirements.update
```

This will update the `requirements_lock.txt` which is then read in MODULE.bazel to install the deps.