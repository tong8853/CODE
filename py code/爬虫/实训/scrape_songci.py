import requests
from bs4 import BeautifulSoup

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36 Edg/140.0.0.0"
}

for num in range(1, 16):
    if num == 1:
        url = "https://www.gushicimingju.com/gushi/songcisanbaishou/"
    else:
        url = f"https://www.gushicimingju.com/gushi/songcisanbaishou/page{num}/"
    response = requests.get(url, headers = headers) #UA伪装
    if response.status_code != 200:
        print(f"请求失败，状态码为：{response.status_code}")
        break
    html = response.text  #获html格式的响应体
    soup = BeautifulSoup(html, "html.parser") #解析获取的html文件,使用parser解析器
    
    ul = soup.find("ul", class_ = "simple-shiciqu has-author main-data")
    if not ul:  # 防止ul为空导致报错
        print(f"第{num}页未找到目标ul，跳过")
        continue
    all_li = ul.find_all("li")
    for li in all_li:
        # 提取所有a标签的文本内容
        all_a_text = [a.get_text(strip=True) for a in li.find_all("a")]
        # 提取内容span的文本
        content_text = li.find("span", class_ = "content").get_text(strip=True) if li.find("span", class_ = "content") else "无内容"
        # 打印结果
        print(" ".join(all_a_text))  # 拼接所有a标签的文本
        print(content_text)  # 打印诗词内容
        print("-" * 50) 