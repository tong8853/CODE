import requests
URL = "http://books.toscrape.com/"
response = requests.get(URL)
print(response.status_code, end = "\n") #打印response对象的状态码
print(response.headers, end = "\n") #打印响应头
print(response.text, end = "\n") #打印响应体