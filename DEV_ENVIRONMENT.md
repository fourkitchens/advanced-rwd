# Setting up a Development Environment

All of the code here can be run on any environment that has Ruby and Bundler installed. However, there can be small differences between environments. As such, we have made a Virtual Machine (VM) for trainees to utilize locally. To

You will need to be connected to the internet to setup your environment, and depending on your connection speed it could take some time.

## Using Mac OS X locally

If you have already used Sass / Compass, and want to continue to do so, you may use you local Mac. This is how we generally develop our code, but ocassionaly minor differences between environments can cause errors. If you use your local machine, please ensure you have the followin installed:

* Ruby (Version 2.0.0-p451 or higher)
* [Node.js](http://nodejs.org/download/) (Most recent)
* [Bundler](http://bundler.io/) (Installed via command line) 
* [Yeoman](http://yeoman.io/) (npm install -g yo)

## Windows

These directions are meant for OS X and Linux hosts. Although the Vagrant machine should work on Windows, we have not tested it thoroughly. We HIGHLY recomend you use a OS X machine, as we cannot provide support in the training for Windows machines.

## Prerequisites

This VM is built using [Vagrant](https://www.vagrantup.com/) and [VirtualBox](https://www.virtualbox.org/). You will need to download them both to proceed.

Download Vagrant: https://www.vagrantup.com/downloads.html
Download VirtualBox: https://www.virtualbox.org/wiki/Downloads

Each installation should be just as easy as click to install, but if you need more information, check out the documentation online.

Vagrant Documentation: https://docs.vagrantup.com/v2/installation/
VirtualBox Documentation: https://www.virtualbox.org/manual/ch02.html

## Download the source code

All of the source code for this training lives on GitHub. You can look at it all by going to https://github.com/fourkitchens/advanced-rwd. If you are confortable with the command line, go to the directory you want to download the source code into, and run this command:

```bash
$ git clone git@github.com:fourkitchens/advanced-rwd.git
```

If you are not confortable with the command line, please install [GitHub for Windows](https://windows.github.com/) or [GitHub for Mac](https://windows.github.com/). Both of these programs will give you a GUI to clone repositories with. 


## Start up the development environment

* Thanks to our amazing pals at [Amazee Labs](http://amazeelabs.com/), we have including some scripts to help setup the VM.
* Double click on vagrant-up.command to run the shell script for your OS. Important: On some OS X Installations you need right
click on the file and click "open".
* You will be prompted for a Password. Enter your system password and confirm with return
* After a couple of minutes (depending on your internet connection), you should see:

```bash
-------------------------------------
| Vagrant Booted Up                 |
-------------------------------------
| Visit this page to continue:      |
| http://192.168.111.42             |
-------------------------------------

logout

```

Do NOT worry if it takes a little bit of time, or if other pieces of information show up on the screen. We are downloading and setting up an entire linux server, which can take some time.

If everything worked correctly, then you should be able to see a website at http://192.168.111.42/. Let us know if you have any questions or concerns.

## Recommended Editing Tools

To edit the files, you only need a text editor. Not Word. Never, ever Word. There are tools designed for it that will be more satisfying than a text editor.

Good tools for editing include [Coda](https://panic.com/coda/), [Notepad++](http://notepad-plus-plus.org/), [Sublime](http://www.sublimetext.com/), and [Atom](https://atom.io/). 
