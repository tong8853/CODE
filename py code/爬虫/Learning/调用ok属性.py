import requests
URL = "http://books.toscrape.com/"
response = requests.get(URL)
if(response.ok):
    print(response.text, end = "\n") #打印响应体
else:
    print("请求失败")
