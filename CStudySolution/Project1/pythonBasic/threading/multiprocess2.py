from concurrent.futures import ProcessPoolExecutor, ThreadPoolExecutor
import time

def sqaure_numbers(number):
    time.sleep(1)
    print(f"Square: {number*number}")

numbers = [1,2,3,4,5]

if __name__=="__main__":
    with ProcessPoolExecutor(max_workers=3) as executor:
        executor.map(sqaure_numbers,numbers)