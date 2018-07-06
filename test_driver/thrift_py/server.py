#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.path.append('gen-py')

from thbdb import Basic
from thbdb import ttypes


from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

class HelloHandler:
    def __init__(self):
        pass

    def hello(self, arg1):
        print "server: %s " % arg1
        retValue = "The Server said:" + arg1
        return retValue


def main():
    handler = HelloHandler()
    processor = Basic.Processor(handler)
    transport = TSocket.TServerSocket(port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)

    print 'Starting the server...'
    server.serve()
    print 'done.'

if __name__ == '__main__':
    main()
