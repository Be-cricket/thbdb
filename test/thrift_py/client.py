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

        #print "Call put() = %s " % (client.put("a","a"),)

        #print "Call put() = %s " % (client.put("big","123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"),)

        print "Call exists(\"a\") = %s " % (client.exists("a"),)

        print "Call exists(\"big\") = %s " % (client.exists("big"),)

        print "Call exists(\"c\") = %s " % (client.exists("c"),)

        print "Call get(\"get\") = %s " % (client.get("big"),)

        #print "Call get(\"c\") = %s " % (client.get("c"),)

        #print "Call put() = %s " % (client.put("aaaaa","aaaaa"),)

        print "Call () remove() = %s " % (client.remove("aaaaa"),)

        print "Call put() = %s " % (client.put("aaaaa","aaaaa"),)

        transport.close()

    except Thrift.TException, tx:
        print "%s" % (tx.message)
