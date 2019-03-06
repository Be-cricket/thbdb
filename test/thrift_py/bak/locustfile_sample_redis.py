# -*- coding: utf-8 -*-
import time
import redis
from locust import Locust, events, task, TaskSet

class RedisClient(object):
    def __init__(self, hosts):
        r = redis.StrictRedis(host='localhost', port=6379, db=0)
        self.client = r

    def set(self, key, value):
        start_time = time.time()
        try:
            ret = self.client.set(key, value)
            total_time = int((time.time() - start_time) * 1000)
            if ret is True:
                events.request_success.fire(request_type='redis',
                                            name='set',
                                            response_time=total_time,
                                            response_length=0)
            else:
                events.request_failure.fire(request_type='redis',
                                            name='set',
                                            response_time=total_time,
                                            exception=None)
        except Exception as e:
            total_time = int((time.time() - start_time) * 1000)
            events.request_failure.fire(request_type='redis',
                                        name='set',
                                        response_time=total_time,
                                        exception=e)

        return ret

    def get(self, key):
        start_time = time.time()
        try:
            ret = self.client.get(key)
            total_time = int((time.time() - start_time) * 1000)
            if ret:
                events.request_success.fire(request_type='redis',
                                            name='get',
                                            response_time=total_time,
                                            response_length=0)
            else:
                events.request_failure.fire(request_type='redis',
                                            name='get',
                                            response_time=total_time,
                                            exception=None)
        except Exception as e:
            events.request_failure.fire(request_type='redis',
                                        name='get',
                                        response_time=total_time,
                                        exception=e)
        return ret


class RedisLocust(Locust):
    def __init__(self, *args, **kwargs):
        super(RedisLocust, self).__init__(*args, **kwargs)
        self.client = RedisClient()


class RedisUser(RedisLocust):
    min_wait = 10
    max_wait = 1000

    class task_set(TaskSet):        
        @task(1)
        def set_key(self):
            self.client.set('foo', 'bar')

        @task(1)
        def get_key(self, **kwargs):
            self.client.get('foo')
