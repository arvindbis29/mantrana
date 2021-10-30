FROM alpine:latest

RUN addgroup -S mantrana && adduser -S mantrana -G mantrana

WORKDIR /tmp/mantrana_compilation
COPY . .
RUN apk update && \
    apk add --no-cache qt5-qtbase qt5-qtwebsockets \
                       build-base g++ gcc cmake ninja qt5-qtbase-dev qt5-qtwebsockets-dev && \
    cmake . -B build -G Ninja && \
    cd build && \
    ninja mantrana_server && \
    cd .. && \
    mv build/server/mantrana_server /home/mantrana/mantrana_server && \
    apk del --no-cache build-base g++ gcc cmake qt5-qtbase-dev qt5-qtwebsockets-dev && \
    rm -rf /tmp/mantrana_compilation

WORKDIR /home/mantrana
USER mantrana
VOLUME /home/mantrana/config
ENTRYPOINT ./mantrana_server
