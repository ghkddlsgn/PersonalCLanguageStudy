import logging

logging.basicConfig(
    level=logging.DEBUG,
    format='%(asctime)s-%(name)s-%(levelname)s-%(message)s',
    datefmt='%Y-%m-%d %H:%M:%S',
    handlers=[
        logging.FileHandler("app1.log"),
        logging.StreamHandler()
    ]
)

logger=logging.getLogger("ArithmethicApp")

def add(a,b):
    result = a + b
    logger.debug(f"Adding {a} + {b} = {result}")
    return result

def devide(a,b):
    try:
        result = a/b
        logger.debug(f"Deviding {a} / {b} = {result}")
        return result
    except ZeroDivisionError:
        logger.error("we can't devide with 0")
        return 0

add(10,15)
devide(10,0)