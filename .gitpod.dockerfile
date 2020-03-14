FROM gitpod/workspace-full:latest

LABEL maintainer="vitortorresvt@gmail.com"

USER root

RUN apt-get update -y
RUN apt-get install -y scilab
RUN apt remove --purge openjdk-*-jdk
RUN apt-get install -y openjdk-8-jdk

USER gitpod