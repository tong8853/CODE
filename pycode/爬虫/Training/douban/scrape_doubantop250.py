import requests
from bs4 import BeautifulSoup
import pandas as pd

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/140.0.0.0 Safari/537.36 Edg/140.0.0.0"
}

# 存储电影数据的列表
movies_data = []

for start_num in range(0, 250, 25):
    response = requests.get(f"https://movie.douban.com/top250?start={start_num}", headers=headers)
    html = response.text
    soup = BeautifulSoup(html, "html.parser")
    
    # 获取所有电影条目
    movie_items = soup.find_all("div", class_="item")
    
    for item in movie_items:
        # 提取电影标题
        title_tag = item.find("span", class_="title")
        if title_tag:
            title = title_tag.get_text()
            
            # 提取评分
            rating_tag = item.find("span", class_="rating_num")
            rating = rating_tag.get_text() if rating_tag else "未知"
            
            # 提取评价人数 - 根据图片中的HTML结构修正
            people_tag = item.find("span", string=lambda x: x and '人评价' in x)
            people_count = people_tag.get_text().replace('人评价', '') if people_tag else "未知"
            
            # 添加到数据列表
            movies_data.append({
                '标题': title,
                '评分': rating,
                '评价人数': people_count
            })

# 创建DataFrame并排序
df = pd.DataFrame(movies_data)
df = df.sort_values(by='评分', ascending=False).reset_index(drop=True)

# 显示表格
print("\n 豆瓣电影 Top 250 评分统计：")
print(df.to_string(index=False))

# 保存到CSV文件
df.to_csv('douban_top250.csv', index=False, encoding='utf-8-sig')
print("\n数据已保存到 douban_top250.csv")

# 统计信息
print(f"\n 统计信息：")
print(f"总电影数量: {len(df)}")
print(f"最高评分: {df['评分'].max()}")
print(f"最低评分: {df['评分'].min()}")