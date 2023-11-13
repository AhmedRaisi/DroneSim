FROM ubuntu:18.04 as env

RUN groupdel dialout

# Install necessary packages including wget
RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    libssl-dev \
    zlib1g-dev \
    dos2unix \
    rsync \
    doxygen \
    graphviz \
    libc6-dbg \
    valgrind \
    git \
    wget

# Remove the existing CMake
RUN apt-get remove --purge --auto-remove cmake

# Download and unpack the latest version of CMake
RUN wget https://github.com/Kitware/CMake/releases/download/v3.21.0/cmake-3.21.0.tar.gz
RUN tar -xzvf cmake-3.21.0.tar.gz

# Install the new version of CMake
WORKDIR /cmake-3.21.0
RUN ./bootstrap
RUN make
RUN make install

# Return to the previous working directory
WORKDIR /

ARG USER_ID
ARG GROUP_ID
ARG DEP_DIR
ARG SRC_DIR

ENV DEP_DIR=/${DEP_DIR}
RUN echo ${DEP_DIR}
ENV SRC_DIR=/${SRC_DIR}
RUN echo ${SRC_DIR}

RUN addgroup --gid $GROUP_ID user
RUN adduser --disabled-password --gecos '' --uid $USER_ID --gid $GROUP_ID user

RUN mkdir -p ${SRC_DIR}
WORKDIR ${SRC_DIR}
RUN git clone https://github.com/dtorban/CppWebServer.git CppWebServer
RUN mkdir -p ${SRC_DIR}/CppWebServer/build
RUN git clone https://github.com/google/googletest.git gtest
RUN mkdir -p ${SRC_DIR}/gtest/build
WORKDIR ${SRC_DIR}/CppWebServer/build
RUN cmake -DCMAKE_INSTALL_PREFIX=${DEP_DIR} ..
RUN make install -j
WORKDIR ${SRC_DIR}/gtest/build
RUN cmake -DCMAKE_INSTALL_PREFIX=${DEP_DIR} ..
RUN make install -j

RUN find ${install_dir} -type d -exec chmod 775 {} \;
RUN find ${install_dir} -type f -exec chmod 664 {} \;

RUN mkdir -p /home/user
WORKDIR /home/user/repo

USER user
