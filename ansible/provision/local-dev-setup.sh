#!/bin/bash

echo ''
echo '======================================================================='
echo 'Running local Ansible playbooks...'
cd /home/vagrant/public_html/ansible
ansible-playbook  playbooks.yml
