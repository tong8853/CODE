import requests
from bs4 import BeautifulSoup

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36 Edg/140.0.0.0"
}

for num in range(0, 250, 50):
    url = f"https://myanimelist.net/topanime.php?type=airing&limit={num}"
    response = requests.get(url, headers = headers) #UA伪装
    if response.status_code != 200:
        print(f"请求失败，状态码为：{response.status_code}")
        break
    html = response.text  #获html格式的响应体
    soup = BeautifulSoup(html, "html.parser") #解析获取的html文件,使用parser解析器
    
    all_h3 = soup.find_all('h3', class_ = "anime_ranking_h3")
    for h3 in all_h3:
        a = h3.find('a', class_ = "hoverinfo_trigger")
        if a:
            print(a.string)
        else:
            print("在h3，class_='hoverinfo_trigger'属性后没有目标字符串")
        