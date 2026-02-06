import requests
from bs4 import BeautifulSoup

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36 Edg/140.0.0.0"
}

for num in range(1, 11):
    url = f"https://www.gushicimingju.com/gushi/songcisanbaishou/page{num}/"
    response = requests.get(url, headers = headers) #UA伪装
    if response.status_code != 200:
        print(f"请求失败，状态码为：{response.status_code}")
        break
    html = response.text  #获html格式的响应体
    soup = BeautifulSoup(html, "html.parser") #解析获取的html文件,使用parser解析器
    
    ul = soup.find("ul", class_ = "simple-shiciqu has-author main-data")
    all_li = ul.find_all("li")
    for li in all_li:
        all_a = li.find_all("a")
        content = li.find("span", class_ = "content")
        for a in all_a:
            print(a, end = "  ")
        print()
        print(content)
        
    
    
        