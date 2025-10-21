import requests
from lxml import html

# 创建 Session 对象（自动管理 Cookie）
session = requests.Session()

# 设置请求头，伪装成浏览器
session.headers.update({
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
    'Referer': 'https://www.douban.com/',
    'Origin': 'https://www.douban.com',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
    'Accept-Encoding': 'gzip, deflate, br',
    'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
    'Connection': 'keep-alive',
})

# 第一步：获取登录页面，提取隐藏字段（如 ck）
login_url = 'https://accounts.douban.com/passport/login'
response = session.get(login_url)

# 使用 lxml 解析 HTML，提取 ck
doc = html.fromstring(response.text)
ck = doc.xpath('//input[@name="ck"]/@value')
ck = ck[0] if ck else ''

print(f"提取到 ck: {ck}")

# 第二步：构造登录数据
login_data = {
    'ck': ck,
    'name': 'your_username_or_email',      # 替换为你的账号
    'password': 'your_password',           # 替换为你的密码
    'remember': 'on',                      # 记住登录
    'login': '登录'                        # 提交按钮值
}

# 第三步：发送登录请求
post_url = 'https://accounts.douban.com/passport/login'
response = session.post(post_url, data=login_data, allow_redirects=True)

# 检查是否登录成功
if response.status_code == 200 and '用户名或密码错误' not in response.text:
    print("✅ 登录成功！")
else:
    print("❌ 登录失败，请检查账号密码")
    print(response.status_code)
    exit()

# 第四步：访问个人“在看电影”页面（使用 API）
# 可以从 https://movie.douban.com/watching 页面分析接口
# 示例 API（需登录后访问）：
api_url = 'https://movie.douban.com/j/tag/items'

params = {
    'tag_id': 'watching',       # 标签：在看
    'category': 'movie',        # 类型：电影
    'type': 'movie',            # 类型
    'action': 'unwatched',      # 动作
    'start': 0,
    'limit': 10
}

api_headers = {
    'X-Requested-With': 'XMLHttpRequest',
    'Referer': 'https://movie.douban.com/watching'
}

response = session.get(api_url, params=params, headers=api_headers)

if response.status_code == 200:
    data = response.json()
    print("\n🎬 你正在看的电影：")
    for item in data.get('items', []):
        subject = item['subject']
        title = subject['title']
        year = subject['year']
        url = subject['url']
        print(f"{title} ({year}) - {url}")
else:
    print("获取电影列表失败:", response.status_code)