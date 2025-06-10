#when to use multi threading

import threading
import time

def print_numbers():
    for i in range(5):
        time.sleep(0.1)
        print(f"Number:{i}")

def print_letters():
    for letter in "abcde":
        time.sleep(0.1)
        print(f"Letter : {letter}")

#create 2 threads
t1 = threading.Thread(target=print_numbers)
t2 = threading.Thread(target=print_letters)

t=time.time()
t1.start()
t2.start()

#wait for threads to complete
t1.join()
t2.join()
finishedTime = time.time() - t
print(finishedTime)