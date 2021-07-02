FROM  registry.cn-hangzhou.aliyuncs.com/mememe/mydocker:LinuxDEV-v3.0.4
RUN mkdir -p /root/workplace
COPY docker/sources.list /etc/apt/
RUN nginx -t
RUN apt-get -y update && apt-get install -y net-tools
RUN apt-get -y install gdbserver
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' '/etc/ssh/sshd_config'
RUN echo 'root:111111' | chpasswd

RUN wget https://www.python.org/ftp/python/3.9.5/Python-3.9.5.tgz && \
tar xzvf Python-3.9.5.tgz && \
cd Python-3.9.5 && \
./configure --prefix=/usr/local/python395/ && \
make && make install && \
rm -f /usr/bin/python3 && \
ln -s /usr/local/python395/bin/python3 /usr/bin/python3

EXPOSE 22 1234 80
VOLUME ['/root/workplace']
CMD /bin/sh -c "/etc/init.d/ssh start && nginx -g 'daemon off;'"


