#!/usr/bin/env python

import threading
from threading import Thread
from Queue import Queue

tasks = Queue()

output_lock = threading.Lock()

def output(dump_str, th):
    output_lock.acquire(True)

    print dump_str
    print th
    print

    output_lock.release()

# consumer
def do_work(task):
    """
    do what you want to `task`
    """
    output(task, threading.currentThread())

def consumer():
    while True:
        item = tasks.get()
        do_work(item)

        tasks.task_done()

def consumer_exector(nu_worker_threads):
    for i in range(nu_worker_threads):
        t = Thread(target=consumer)
        t.daemon = True
        t.start()

# producer 
def source():
    res = []
    for i in range(10):
        res.append(i)

    return res

def producer():
    for item in source():
        tasks.put(item)
    tasks.join()

def producer_executor(nu_pro_ths):
    for i in range(nu_pro_ths):
        t = Thread(target=producer)
        t.daemon = True
        t.start()

if __name__ == '__main__':
    producer_executor(5)
    consumer_exector(5)
#    producer()
