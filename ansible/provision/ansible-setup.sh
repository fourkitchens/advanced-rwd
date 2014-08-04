#!/bin/bash

# Simple function to exit with a message in the case of failure.
function error_exit
{
  echo ''
  echo "$1" 1>&2
  exit 1
}

home=`pwd`

echo ''
echo '======================================================================='
echo 'Setting up Ansible...'

if [ `which ansible` ]; then
  echo 'Ansible already installed.'
  exit 0
fi

echo ''
echo '======================================================================='
echo 'Updating apt and installing Ansible dependencies...'
aptitude -q=2 update > /dev/null || error_exit "Unable to update apt cache."
aptitude -q=2 -y install software-properties-common python-software-properties \
 > /dev/null 2>&1 || error_exit "Unable to install required packages."

echo ''
echo '======================================================================='
echo 'Adding ansible ppa...'
apt-add-repository ppa:ansible/ansible > /dev/null || error_exit "Unable to add Ansible PPA."
aptitude -q=2 update > /dev/null || error_exit "Unable to update apt cache."

echo ''
echo '======================================================================='
echo 'Installing Ansible...'
aptitude -q=2 -y install ansible > /dev/null 2>&1 || error_exit "Unable to install Ansible."

echo ''
echo 'Finished Ansible setup.'
echo ''
