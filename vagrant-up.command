#!/bin/bash
set -o nounset
set -o errexit

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR

vagrant up

echo "-------------------------------------"
echo "| Vagrant Booted Up                 |"
echo "-------------------------------------"
echo "| Visit this page to continue:      |"
echo "| http://192.168.111.42             |"
echo "-------------------------------------"
