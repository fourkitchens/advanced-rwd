# -*- mode: ruby -*-
# vi: set ft=ruby :

HOSTNAME = "rwdtraining.lo"
VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box = "precise64"
  config.vm.box_url = "http://files.vagrantup.com/precise64.box"
  config.vm.hostname = HOSTNAME
  config.vm.network :private_network, :ip => '192.168.111.42'
  # config.ssh.forward_agent = true
  config.vm.synced_folder ".", "/home/vagrant/public_html" , :nfs => true

  config.vm.provider :virtualbox do |vm|
    vm.customize ["modifyvm", :id, "--memory", "512"]
    vm.customize ["modifyvm", :id, "--cpus", "2"]
  end

  config.vm.provision :shell, :path => "ansible/provision/ansible-setup.sh"
  config.vm.provision :shell, :path => "ansible/provision/local-dev-setup.sh"
end
