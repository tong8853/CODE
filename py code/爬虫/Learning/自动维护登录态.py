import requests
from fake_useragent import UserAgent

ua = UserAgent()
headers = {"User-Agent": ua.random}
url = "https://www.douban.com/"
cookies = {
    "SUB": "xxxxxxx",
    "other": "xxxxx"
}
response = requests.get(url, headers=headers, cookies=cookies)
