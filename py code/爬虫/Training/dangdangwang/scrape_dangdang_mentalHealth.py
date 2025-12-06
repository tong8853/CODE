import requests
from bs4 import BeautifulSoup

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36 Edg/140.0.0.0"
}

for num in range(0, 10, 1):
    url = f"http://bang.dangdang.com/books/bestsellers/01.31.00.00.00.00-recent7-0-0-1-{num}"
    response = requests.get(url, headers = headers) #UA伪装
    if response.status_code != 200:
        print(f"请求失败，状态码为：{response.status_code}")
        break
    html = response.text  #获html格式的响应体
    soup = BeautifulSoup(html, "html.parser") #解析获取的html文件,使用parser解析器
    
    all_name_div = soup.find_all("div", class_ = "name")
    for name_div in all_name_div:
        if name_div:
            a = name_div.find('a')
            if a:
                #获取title属性的值
                title = a.get("title")
                print(title)
            else:
                print("对应div里面没有a标签")
        else:
            print("未找到class为name的div")
        
        