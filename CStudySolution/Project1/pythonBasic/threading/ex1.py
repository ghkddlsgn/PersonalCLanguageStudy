import threading
import time

# def func(y):
#     print('ran')
#     time.sleep(1)
#     print('done')
#     time.sleep(0.85)
#     print('now done')

# x=threading.Thread(target=func, args=(4,))
# x.start()
# print(threading.active_count())
# time.sleep(0.9)
# print('finally')

ls = []

def count(n):
    for i in range(1,n+1):
        ls.append(i)
        time.sleep(0.5)

for _ in range(2):
    x = threading.Thread(target=count, args=(10,))
    x.start()

x.join()

print(ls)