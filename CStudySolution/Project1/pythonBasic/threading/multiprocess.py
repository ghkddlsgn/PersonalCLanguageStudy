#process that run in parallel

import multiprocessing
import time

def sqaure_numbers():
    for i in range(5):
        time.sleep(0.1)
        print(f"sqaure:{i**2}")

def cube_numbers():
    for i in range(5):
        time.sleep(0.1)
        print(f"cube:{i*i*i}")

if __name__=="__main__":
    #create 2 processes
    p1 = multiprocessing.Process(target=sqaure_numbers)
    p2 = multiprocessing.Process(target=cube_numbers)
    t=time.time()

    #start the process
    p1.start()
    p2.start()

    #wait for the process to complete
    p1.join()
    p2.join()