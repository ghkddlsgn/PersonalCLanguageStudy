'''

'''

# Example URLs for practicing LangChain

urls = [
    "https://python.langchain.com/docs/get_started/quickstart",  # Quick start guide
    "https://python.langchain.com/docs/modules/chains/",  # Chains documentation
    "https://python.langchain.com/docs/modules/agents/"   # Agents documentation
]

import threading
import requests
from bs4 import BeautifulSoup

def fetch_contents(url):
    response=requests.get(url)
    soup=BeautifulSoup(response.content, 'html.parser')
    print(f'Fetched {(len(soup.text))} characters from {url}')

threads = []

for url in urls:
    thread = threading.Thread(target=fetch_contents, args=(url,))
    threads.append(thread)
    thread.start()

for thread in threads:
    thread.join()

print("All web pages fetched")