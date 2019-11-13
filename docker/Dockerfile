FROM bovulpes/qc-in2p3-tuto:test

WORKDIR /<your-favourite-directory>/qctuto

RUN apt-get install -y make

ARG USER_ID=<uid>
ARG GROUP_ID=<gid>

RUN groupadd -g ${GROUP_ID} qctuto &&\
    useradd -l -u ${USER_ID} -g qctuto qctuto &&\
    install -d -m 0755 -o qctuto -g qctuto /home/qctuto

USER qctuto
