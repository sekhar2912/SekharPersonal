#!/bin/sh
# Script to build the reactor_server and reactor_client !
rm -rf reactor_client reactor_server
ls reactor_client reactor_server
g++ -o reactor_server reactor_server_test.cpp event_demultiplexer.cpp reactor.cpp global.cpp
g++ -o reactor_client reactor_client_test.cpp event_demultiplexer.cpp reactor.cpp global.cpp
