# syntax=docker/dockerfile:1

FROM python:3-alpine
WORKDIR /usr/src/app
COPY . .
ENV zmienna=1
CMD [ "python", "-m", "http.server" ]


//https://docs.docker.com/get-started/workshop/02_our_app/
//https://docs.docker.com/compose/gettingstarted/