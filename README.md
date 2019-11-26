# Material for the hands-on session of the "Quantum Computing Days at IN2P3", December 2-3, 2019, IPNO, France

## Before coming to the workshop

In order to do the exercises of the hands-on session, you need a laptop
(PC or Mac) with Linux on it. The software for the exercises (mainly QC
simulators for quantum circuits) together with all the necessary dependencies
will run inside a "docker container" prepared in this purpose. The code
sources for the exercises can be obtained from the git repository:

```bash
https://github.com/bovulpes/tuto-qc.git
```

The first step is to install the Docker Engine on your machine, by choosing
the Community Edition specific to the Linux flavour of your operating system
(you need administrator privileges on your system). Instructions on how to
install it can be found here:

for Ubuntu:
```bash
https://docs.docker.com/install/linux/docker-ce/ubuntu/
```

for CentOS:
```bash
https://docs.docker.com/install/linux/docker-ce/centos/
```

for Fedora:
```bash
https://docs.docker.com/install/linux/docker-ce/fedora/
```

for Debian:
```bash
https://docs.docker.com/install/linux/docker-ce/debian/
```

For MacOS it is a bit more complicated, since you have to create first
a Docker ID (a sort of account), as you can see here:

```bash
https://hub.docker.com/editions/community/docker-ce-desktop-mac
```

The Docker ID could be useful for your if later on you want to create
your own docker images and upload them on the docker hub in order to make
them available to a large audience (they are public).

Once you have the Docker Engine CE installed, pull to your machine the
image for the tutorial with the command:

```bash
docker pull bovulpes/qc-in2p3-tuto:v01
```

Create the working directory for this tutorial with the name "qctuto" somewhere in your favourite directory:

```bash
mkdir <your-favourite-directory>/qctuto
```

and define the environment variable:

```bash
export QCTUTO_HOME=<your-favourite-directory>/qctuto
```

The next command creates a container named "qctuto" starting from the pulled
image "bovulpes/qc-in2p3-tuto:v01", sets the home directory to the value 
defined above and starts a "bash" shell:

```bash
docker run -itd --name qctuto -v $QCTUTO_HOME:$QCTUTO_HOME --net=host bovulpes/qc-in2p3-tuto:v01 /bin/bash
```

With the next command you add inside the container a user/group having the same
identity as your local account:

```bash
docker exec qctuto useradd -u $UID $USER
```

Now you can enter the container in an interactive session:

```bash
docker exec -it --user $USER -w $QCTUTO_HOME qctuto /bin/bash
```

Note: if you get the error about missing option "-w", make sure that the API version of your docker installation is >= 1.35 by checking the output of the command "docker version". If it is not the case, update you docker to a higher version.

You can repeat the command in another terminal and open another session inside
the container.

The support material is on git hub and you can get a copy of it with:

```bash
git clone https://github.com/bovulpes/tuto-qc
```

Then go in the directory:

```bash
cd tuto-qc/qpp-examples
```

and compile the example file by running:

```bash
make
```

If successful, try to execute it:

```bash
./minimal
```

and you should see this output:

```bash
Hello Quantum++!
This is the |0> state:
1
0
```

At the end of the work, close all terminal windows from the "qctuto" container
and then kill the container with the command:

```bash
docker kill qctuto
```

## The simulators

A comprehensive list of (free) simulators can be found here:

```bash
https://quantiki.org/wiki/list-qc-simulators
```

For this tutorial we will use:

```bash
Quantum++ (C++11)
https://github.com/vsoftco/qpp
```

