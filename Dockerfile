FROM alpine:latest AS builder
MAINTAINER Hasan Zahid

RUN apk update \
 && apk add --no-cache \
      cmake \
      make \
      gcc \
      g++ \
      musl-dev

WORKDIR /app
COPY . .

RUN mkdir build
WORKDIR /app/build

RUN cmake .. && \
    cmake --build . && \
    cp ghostComm /tmp/ghostComm

FROM alpine:latest
MAINTAINER Hasan Zahid

WORKDIR /app
COPY --from=builder /tmp/ghostComm .

RUN apk add --no-cache \
      libstdc++ \
      libgcc

ENTRYPOINT [ "./ghostComm" ]