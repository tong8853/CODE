import requests
from bs4 import BeautifulSoup

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36 Edg/140.0.0.0"
}

# 循环分页：limit=0（第1-50名）、limit=50（第51-100名）
for num in range(0, 50, 50):
    url = f"https://myanimelist.net/topanime.php?type=airing&limit={num}"
    response = requests.get(url, headers=headers)
    if response.status_code != 200:
        print(f"请求失败，状态码：{response.status_code}")
        break
    html = response.text
    soup = BeautifulSoup(html, "html.parser")
    
    # 定位包含标题的 h3 标签，再提取其中的 <a>
    h3_tags = soup.find_all('h3', class_='anime_ranking_h3')
    for h3 in h3_tags:
        title_a = h3.find('a', class_='hoverinfo_trigger')
        if title_a:
            print(title_a.string.strip())