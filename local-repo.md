## 定义仓库路径
```shell
mkdir -p /root/local.repo
sed -i '/^keepcache=0/ckeepcache=1' /etc/yum.conf
sed -i '/^cachedir=/ccachedir=/root/local.repo' /etc/yum.conf
yum install -y createrepo
cd local.repo
createrepo .
```

## 安装postgis
```shell
cd /etc/yum.repos.d/
sudo yum install -y vim tree wget wget net-tools epel-release net-tools yum-utils
yum makecache
sudo yum install -y gcc make subversion gcc-c++ sqlite-devel libxml2 libxml2-devel python-devel numpy swig expat-devel libcurl-devel
sudo yum install -y https://download.postgresql.org/pub/repos/yum/reporpms/EL-7-x86_64/pgdg-redhat-repo-latest.noarch.rpm
sudo yum install -y postgresql14-server
sudo yum install -y postgis32_14.x86_64
```

## 安装docker
```shell
sudo yum-config-manager --add-repo https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/centos/docker-ce.repo
yum list docker-ce --showduplicates | sort -r
yum install -y docker-ce-24.0.5-1.el7
```

## 安装nvidia docker
```shell
distribution=$(. /etc/os-release;echo $ID$VERSION_ID)
curl -s -L https://nvidia.github.io/nvidia-docker/$distribution/nvidia-docker.repo | sudo tee /etc/yum.repos.d/nvidia-docker.repo
```

```shell
[libnvidia-container]
name=libnvidia-container
baseurl=https://nvidia.github.io/libnvidia-container/stable/centos7/$basearch
repo_gpgcheck=1
gpgcheck=0
enabled=1
gpgkey=https://nvidia.github.io/libnvidia-container/gpgkey
sslverify=1
sslcacert=/etc/pki/tls/certs/ca-bundle.crt

[libnvidia-container-experimental]
name=libnvidia-container-experimental
baseurl=https://nvidia.github.io/libnvidia-container/experimental/centos7/$basearch
repo_gpgcheck=1
gpgcheck=0
enabled=0
gpgkey=https://nvidia.github.io/libnvidia-container/gpgkey
sslverify=1
sslcacert=/etc/pki/tls/certs/ca-bundle.crt

[nvidia-container-runtime]
name=nvidia-container-runtime
baseurl=https://nvidia.github.io/nvidia-container-runtime/stable/centos7/$basearch
repo_gpgcheck=1
gpgcheck=0
enabled=1
gpgkey=https://nvidia.github.io/nvidia-container-runtime/gpgkey
sslverify=1
sslcacert=/etc/pki/tls/certs/ca-bundle.crt

[nvidia-container-runtime-experimental]
name=nvidia-container-runtime-experimental
baseurl=https://nvidia.github.io/nvidia-container-runtime/experimental/centos7/$basearch
repo_gpgcheck=1
gpgcheck=0
enabled=0
gpgkey=https://nvidia.github.io/nvidia-container-runtime/gpgkey
sslverify=1
sslcacert=/etc/pki/tls/certs/ca-bundle.crt

[nvidia-docker]
name=nvidia-docker
baseurl=https://nvidia.github.io/nvidia-docker/centos7/$basearch
repo_gpgcheck=1
gpgcheck=0
enabled=1
gpgkey=https://nvidia.github.io/nvidia-docker/gpgkey
sslverify=1
sslcacert=/etc/pki/tls/certs/ca-bundle.crt
```
```shell
sudo yum install -y nvidia-container-toolkit
```

## 安装htop
```shell
yum install -y htop
yum install -y iotop
yum install -y iftop
yum install -y glances
yum install -y rsync
yum install -y ncdu
yum install -y dos2unix
yum install -y jq
```
## 加密
```shell
openssl enc -aes-256-cbc -salt -in local.repo.tar.gz -out local.repo.tar.gz.enc -k local.repo -md md5
openssl enc -d -aes-256-cbc -in local.repo.tar.gz.enc -out local.repo.tar.gz -k local.repo -md md5
```
## 离线

```shell
#/var/lib/pgsql
current_path=$(cd $(dirname $0);pwd)
# 解压
tar -zxvf postgres.tar.gz
# 初始化repo
cat << EOF | tee /etc/yum.repos.d/local-postgres.repo
[Postgres]
name=Postgres
baseurl=file://${current_path}/postgres/
enabled=1
gpgcheck=0
priority=1
EOF
mv /etc/yum.repos.d/CentOS-Base.repo /etc/yum.repos.d/CentOS-Base.repo.bak
# 安装
sudo yum install -y vim tree wget net-tools
sudo yum install -y gcc make subversion gcc-c++ sqlite-devel libxml2 libxml2-devel python-devel numpy swig expat-devel libcurl-devel
sudo yum install -y epel-release
sudo yum install -y postgresql14-server
sudo yum install -y postgis32_14.x86_64
# 新建数据目录
mkdir -p /var/lib/pgsql/14/data
chown -R postgres:postgres /var/lib/pgsql
# 初始化数据库
sudo /usr/pgsql-14/bin/postgresql-14-setup initdb
# 启动
sudo systemctl enable postgresql-14
sudo systemctl start postgresql-14
# 开启访问权限
echo "listen_addresses = '*'" >> /var/lib/pgsql/14/data/postgresql.conf
sed -i '/local   all             all                                     peer/clocal   all             all                                     trust' /var/lib/pgsql/14/data/pg_hba.conf
sed -i '/host    all             all             127.0.0.1\/32            scram-sha-256/chost    all             all             127.0.0.1/32            trust' /var/lib/pgsql/14/data/pg_hba.conf
sed -i '/host    all             all             ::1\/128                 scram-sha-256/chost    all             all             ::1/128                 trust' /var/lib/pgsql/14/data/pg_hba.conf
sed -i '/local   replication     all                                     peer/clocal   replication     all                                     trust' /var/lib/pgsql/14/data/pg_hba.conf
sed -i '/host    replication     all             127.0.0.1\/32            scram-sha-256/chost    replication     all             127.0.0.1/32            trust' /var/lib/pgsql/14/data/pg_hba.conf
sed -i '/host    replication     all             ::1\/128                 scram-sha-256/chost    replication     all             ::1/128                 trust' /var/lib/pgsql/14/data/pg_hba.conf
echo "host    all             all             all                     md5" >> /var/lib/pgsql/14/data/pg_hba.conf
# 重启
sudo systemctl restart postgresql-14
# 设置密码
sudo /usr/pgsql-14/bin/psql -U postgres -c "ALTER USER postgres WITH PASSWORD '123++';"
sudo /usr/pgsql-14/bin/psql -U postgres -c 'CREATE EXTENSION postgis;'
sudo /usr/pgsql-14/bin/psql -U postgres -c 'CREATE EXTENSION postgis_topology;'
sudo /usr/pgsql-14/bin/psql -U postgres -c "CREATE EXTENSION \"uuid-ossp\";"
# 重启
sudo systemctl restart postgresql-14
# 恢复repo
mv /etc/yum.repos.d/CentOS-Base.repo.bak /etc/yum.repos.d/CentOS-Base.repo
```