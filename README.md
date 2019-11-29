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

## Using the myQLM simulator from Atos Quantum Lab

Below are the instructions on how to download and use the myQLM docker image
for the workshop.

The image once installed is around 2.5GB; its export file is about 950MB.
 
1 – Retrieve the image
(equivalent of docker pull if our image was published on docker.io)

```bash
~> sftp myqlm@doorway.bull.com

myqlm@doorway.bull.com's password: ...see mail...

Connected to doorway.bull.com.

sftp> cd downloads

sftp> get myqlm-runtime-0.0.5_latest.export

Fetching…

sftp> bye
```

Note: This can be done from any machines connected to Internet.
 
2 – Import the image into your docker installation

```bash
~> zcat myqlm-runtime-0.0.5_latest.export | docker import - myqlm-runtime-0.0.5:latest
```

Note: One can use “docker images” to see the list of images
 
3 – Instantiate a container from the image and connect to it

```bash
~> [sudo] docker run -ti -p 8011:8888 myqlm-runtime-0.0.5:latest /bin/bash -l
```

Notes:

8011 here is an arbitrary port on the host side that will be mapped to the port 8888 inside the container (Jupyter server default port).

From another window, one can use “docker ps” to see the container.
       
The myQLM wheels are already installed except for myqlm-simulators and are located at /var/myqlm/dist/0.0.5/atos/myqlm-0.0.5-atos/
       
There is a README file that explains how to install myQLM at /var/myqlm/dist/0.0.5/atos/README.md
 
4 – Start a Jupyter server once inside the container
 
```bash
~> su – qatuser
~> myqlm_notebook/launch_myqlm_notebook
…
```

Copy/paste this URL into your browser when you connect for the first time,
to login with a token:

```bash
http://0.0.0.0:8888/?token=f508e5b2659e107d02b9821fb8a604e9f7dd960dd2fb16f1
```

Note: You can also work in command line mode

5 – Connect to the server from a browser

```bash
http://<localhost_or_host_ip>:8011
```

Note: Copy/paste the value of the token shown on the Jupyter console above

