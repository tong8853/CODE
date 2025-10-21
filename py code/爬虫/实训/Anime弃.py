import requests
from bs4 import BeautifulSoup

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36 Edg/140.0.0.0"
}
for num in range(0, 250, 50):
    response = requests.get(f"https://myanimelist.net/topanime.php?type=airing&limit={num}", headers = headers)
    html = response.text
    soup = BeautifulSoup(html, "html.parser")
    all_titles = soup.find_all('a', class_ = "hoverinfo_trigger", style="position: relative; display: inline-block;")
    for title in all_titles:
        print(title.string)
# for start_num in range(0, 250, 50):
#     response = requests.get(f"https://myanimelist.net/topanime.php?type=airing&limit={start_num}",headers = headers)
#     html = response.text
#     soup = BeautifulSoup(html, "html.parser") #第二个参数为指定解析器
#     all_titles = soup.findAll("span", attrs = {"class": "title"})
#     for title in all_titles:
#         title_string = title.string
#         if "/" not in title_string:
#             print(title_string)