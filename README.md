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
docker pull bovulpes/qc-in2p3-tuto:test
```

You can check it with the command:

```bash
docker images
```

Create the working directory for this tutorial with the name "qctuto" in
your favourite directory:

```bash
cd <your-favourite-directory>
mkdir qctuto
```

then go there and clone the git repository:

```bash
cd <your-favourite-directory>/qctuto
git clone https://github.com/bovulpes/tuto-qc
```

The first step is to create a second image from the one pulled down as explained
above, by adding a layer which provides the same user identification inside the
docker container as in your local account. In order to do this, change to the
directory "tuto-qc/docker" and replace in the file Dockerfile the <uid> and
<gid> by the two values given by the Linux command "id". Change also the value
of WORKDIR in Dockerfile and runx.sh according to the previous step.

After doing this, execute the script:

```bash
./build.sh     
```

(be sure it has the executable flag set) or simply run the command:

```bash
docker build -t qctuto .     
```
(there is a point at the end!). Now you can launch a container from the
"qctuto" image by executing the script:

```bash
./runx.sh     
```
(or simply run the command inside it) and you are inside the container,
starting in the directory

```bash
<your-favourite-directory>/qctuto
```

If you have already cloned the git repository, go in the directory:

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

If you want to open several terminal windows from the container, use the
command:

```bash
xterm -s bash -fa 'Monospace' -fs 12 &
```

Note: git is also available in the docker image, so you can clone the tutorial
repository afterwards, from inside the container. Since you have the same user
identification as on your local account, files will be accessible with the same
rights from both sides.

