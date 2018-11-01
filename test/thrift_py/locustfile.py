#! /usr/bin/env python
# -*- coding: utf-8 -*-

import glob
import sys
import time
import threading

sys.path.append('gen-py')

from thbdb import Basic
from thbdb import ttypes

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

from locust import Locust, TaskSet, task, events


LOCK_COMM = threading.Lock()

class MyTaskSet(TaskSet):

    transport = TSocket.TSocket('localhost', 9090)
    transport = TTransport.TBufferedTransport(transport)
    protocol = TBinaryProtocol.TBinaryProtocol(transport)
    clienta = Basic.Client(protocol)
    transport.open()
    print("Connected!")

    def on_start(self):
        msg = "Start :"
        
        print( msg )

    @task(1)
    def hello(self):
        global LOCK_COMM
        LOCK_COMM.acquire()
        start_time = time.time()
        try:
            msg = "Hello on :"
            print( msg  )
            retValue = MyTaskSet.clienta.hello( "YeaH!" );
            total_time = int((time.time() - start_time) * 1000)
            print( retValue )
            
            events.request_success.fire(request_type='ThBDB',
                                            name='hello',
                                            response_time=total_time,
                                            response_length=0)
        except Exception as e:
            total_time = int((time.time() - start_time) * 1000)
            events.request_failure.fire(request_type='ThBDB',
                                        name='hello',
                                        response_time=total_time,
                                        exception=e)
            print( e )
        finally:
            LOCK_COMM.release()

    @task(2)
    def get(self):
        global LOCK_COMM
        LOCK_COMM.acquire()
        start_time = time.time()
        try:

            msg = "get :"
            print( msg  )
            retValue = MyTaskSet.clienta.get( "a" );
            total_time = int((time.time() - start_time) * 1000)
            print( retValue )
            
            events.request_success.fire(request_type='ThBDB',
                                            name='get',
                                            response_time=total_time,
                                            response_length=0)
        except Exception as e:
            total_time = int((time.time() - start_time) * 1000)
            events.request_failure.fire(request_type='ThBDB',
                                        name='get',
                                        response_time=total_time,
                                        exception=e)
            print( e )
        finally:
            LOCK_COMM.release()

    @task(2)
    def get_big(self):
        global LOCK_COMM
        LOCK_COMM.acquire()
        start_time = time.time()
        try:

            msg = "get_big :"
            print( msg  )
            retValue = MyTaskSet.clienta.get( "big" );
            total_time = int((time.time() - start_time) * 1000)
            print( retValue )
            
            events.request_success.fire(request_type='ThBDB',
                                            name='get_big',
                                            response_time=total_time,
                                            response_length=0)
        except Exception as e:
            total_time = int((time.time() - start_time) * 1000)
            events.request_failure.fire(request_type='ThBDB',
                                        name='get_big',
                                        response_time=total_time,
                                        exception=e)
            print( e )
        finally:
            LOCK_COMM.release()

    #def index(self):
    #    import pdb; pdb.set_trace()
    #    self.client.get("/")



class MyLocust(Locust):
    task_set = MyTaskSet
    min_wait = 5000
    max_wait = 15000
