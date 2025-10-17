FROM ros:jazzy-ros-core

RUN apt-get update && \
    apt-get install -y \
    git \
    nano \
    python3 \
    python3-pip \
    python3-venv \
    ros-jazzy-demo-nodes-cpp \
    ros-jazzy-foxglove-bridge \
    ros-jazzy-tf2-ros && \
    clang-tidy && \
    apt-get clean

RUN curl -L https://github.com/bazelbuild/bazelisk/releases/download/v1.27.0/bazelisk-linux-amd64 -o bazelisk && \
    mv bazelisk /usr/local/bin/bazelisk && \
    chmod +x /usr/local/bin/bazelisk && \
    ln -s /usr/local/bin/bazelisk /usr/local/bin/bazel

COPY .devcontainer/bazel_completion.bash /etc/bash_completion.d/bazel_completion.bash

COPY .devcontainer/.bashrc /root/.bashrc
