#! /usr/bin/env python
# -*- coding: utf-8 -*-

import glob
import sys
sys.path.append('gen-py')

from thbdb import Basic
from thbdb import ttypes

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

if __name__ == '__main__':
    try:
        transport = TSocket.TSocket('localhost', 9090)
        transport = TTransport.TBufferedTransport(transport)
        protocol = TBinaryProtocol.TBinaryProtocol(transport)
        #client = Calculator.Client(protocol)
        client = Basic.Client(protocol)

        transport.open()

        print "Call hello() = %s " % (client.hello("Yeah!"),)

        # print "Call put() = %s " % (client.put("a","a"),)

        # print "Call put() = %s " % (client.put("big","123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"),)

        print "Call exists(\"a\") = %s " % (client.exists("a"),)

        print "Call exists(\"big\") = %s " % (client.exists("big"),)

        print "Call exists(\"c\") = %s " % (client.exists("c"),)

        # print "Call get(\"get\") = %s " % (client.get("big"),)

        # print "Call get(\"c\") = %s " % (client.get("c"),)

        # print "Call put() = %s " % (client.put("aaaaa","aaaaa"),)

        # print "Call () remove(\"aaaaa\") = %s " % (client.remove("aaaaa"),)

        # print "Call put1() = %s " % (client.put("aaaaa","aaaaa"),)


        # for idx in range(10):
        for idx in range(10,10000,200):
              print "Call remove(%s) = %s " % ("key#" + str(idx), client.remove("key#" + str(idx)),)


        # for idx in range(10):
        for idx in range(10,10000,200):
            print "Call put() = %s " % (client.put("key#" + str(idx) ,"value" + str(idx) ),)


        # 大量投入セット　↓        
        # for idx in range(10):
        # for idx in range(10,990000,200):
        #       print "Call remove(%s) = %s " % ("key#" + str(idx), client.remove("key#" + str(idx)),)

        # # for idx in range(10):
        # for idx in range(10,990000,200):
        #     print "Call put() = %s " % (client.put("key#" + str(idx) ,"value" + str(idx) ),)
        # 大量投入セット　↑


        print "Call ping = %s " % (client.ping(),)

        print "Call status = %s" % (client.getStatus(),)

        print "Call getKeysByPosition(0,100) = %s" % (client.getKeysByPosition(0,1000),)
        print "Call getKeysByPosition(0,1) = %s" % (client.getKeysByPosition(0,1),)
        print "Call getKeysByPosition(0,0) = %s" % (client.getKeysByPosition(0,0),)
        print "Call getKeysByPosition(51,1) = %s" % (client.getKeysByPosition(51,1),)
        print "Call getKeysByPosition(51,2) = %s" % (client.getKeysByPosition(51,2),)
        print "Call getKeysByPosition(0,6) = %s" % (client.getKeysByPosition(0,6),)
        print "Call getKeysByPosition(49,4) = %s" % (client.getKeysByPosition(49,4),)
        print "Call getKeysByPosition(52,10) = %s" % (client.getKeysByPosition(52,10),)
        print "Call getKeysByPosition(53,10) = %s" % (client.getKeysByPosition(53,10),)
        
        print "Call compact = %s" % (client.compact(),)

        transport.close()

    except Thrift.TException, tx:
        print "%s" % (tx.message)
