# Exercise: Yocto build system and Git

## Instructions
1. Using resources available online, compile a bootable image for a RaspberryPi board using yocto.
    * You can use any image, minimal is correct
    * You're free to select a version of Yocto
    * You're free to select a version of the target RaspberryPi board
1. Add a new layer that:
    * contains a recipe to compile the bootgen tool from Xilinx for the target RaspberryPi
        * You can use tag 2019.2
    * adds bootgen to the firmware image image.
1. Provide a README in markdown format to describe steps to recompile your new image
    * Objective is that someone that follows the README can rebuild the image with no error

## Deliverables

Use public Git repositories (Github, Gitlab, etc.) to share the yocto layers.

# Solution

## Requirements
* Ubuntu 22.04

## Setup

### 1. Install WSL
You may skip this step if you are already running Ubuntu 22.04.

1. Open an administrator power shell session.
1. Run the command `wsl --install -d Ubuntu-22.04`
1. Enter a username and password when prompted.

When the installation process is complete, a new WSL session will be open in your terminal.

If you have already cloned the repository to your windows environment, you may open it by navigating to the mounted folder.

```bash
cd /mnt/c/path/to/git
```

If you have not cloned the repository yet, you may do so now in your WSL session.

```bash
git clone git@github.com:tycoontwist/EmbeddedSpecialistExercises.git
```

Git setup is outside the scope of this exercise.

### 2. Install dependencies
You must install the required host packages on your build machine before we can begin the build process.

First, update your package lists.
```bash
sudo apt-get update
```

Next, install the dependencies.

```bash
sudo apt install gawk wget git diffstat unzip texinfo gcc build-essential chrpath socat cpio python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev python3-subunit mesa-common-dev zstd liblz4-tool file locales libacl1
```

Lastly, set the locale.
```bash
sudo locale-gen en_US.UTF-8
```

### 3. Setup yocto environment
We'll be using the latest yocto release at the time of writing: `scarthgap`. Note this exercise uses git submodules to clone `poky`, the official yocto repository, along with `meta-raspberrypi` and `meta-openembedded`, which are meta layer definitions for the Raspberry Pi. After the setup script is run, a build directory is created which will contain all the files created during the build.

To run the yocto setup script, you will need to initialize the submodules.

Navigate to the poky directory and run the following command.

```bash
git submodule update --init
```

Next, navigate to the root of the `poky` directory and run the setup script; provide the location of the target build directory as an argument. In our case, we would like the build directory in `3-yocto-build-system-and-git`.

```bash
cd ~/poky/

source oe-init-build-env ../3-yocto-build-system-and-git
```

Lastly, we'll need to add the meta-raspberrypi layer to the `bblayers.conf` file. Open the file in your favorite text editor and add the following line.

```bash


### 4. Build the image
To build the image, run the following command in the `poky` directory.

TODO


