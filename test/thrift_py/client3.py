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

        #client.put( "test","テストバリュー" )
        
        result = client.get(u'あ')
        print( u'あ' )
        print( u'\u3042\u3042' )
        value = u'\u3042'
        print( value )
        print ( 'result: %s' % result)  

        
        #print ("Call get(\"あ\") =" , result.decode('string-escape') )
        
        transport.close()

    except Thrift.TException as  tx:
        print ( tx.message )
