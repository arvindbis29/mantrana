FROM alpine:3.9

RUN addgroup -S mantrana && \
        adduser -S mantrana -G mantrana

RUN apk update && \
    apk add --no-cache qt5-qtbase \
                       qt5-qtwebsockets

WORKDIR /tmp/compile
COPY . .
RUN apk add --no-cache build-base \
                       g++ \
                       gcc \
                       cmake \
                       qt5-qtbase-dev \
                       qt5-qtwebsockets-dev && \
    cmake -H. -B build && \
    cmake --build build --target mantrana_server && \
    mv build/server/mantrana_server /home/mantrana/mantrana_server && \
    apk del --no-cache build-base \
                       g++ \
                       gcc \
                       cmake \
                       qt5-qtbase-dev \
                       qt5-qtwebsockets-dev && \
    rm -rf /tmp/compile

WORKDIR /home/mantrana
USER mantrana
VOLUME /home/mantrana/config
ENTRYPOINT ./mantrana_server