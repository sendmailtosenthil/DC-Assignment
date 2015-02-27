# DC-Assignment

The dictionary.x file is having definition for interface
You can generate stubs using below command

rpcgen -C dictionary.x

Client compliation is as follows
cc -o client client.c  dictionary_clnt.c dictionary_xdr.c -lnsl
This will generate exe called client (2nd param). Please change to different name.

Server compilation is as follows
cc -o server -DRPC_SVC_FG server.c dictionary_svc.c dictionary_xdr.c -lnsl
This will generate exe called server (2nd param). Please change to different name.

How to use?

1. Run server in a first terminal
2. Run client in second terminal.
	Client will ask you to provide host name.
	You will be asked to enter I or S or D option

Play with it.

