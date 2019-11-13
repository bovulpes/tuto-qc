#!/bin/bash

WORKDIR=/<your-favourite-directory/qctuto

docker run -it --rm -v $WORKDIR:$WORKDIR -e DISPLAY -v $XAUTHORITY:$HOME/.Xauthority --net=host qctuto

