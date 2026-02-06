from urllib.parse import urlparse

# 定义统一资源定位器地址
url = "http://www.skyme.org:8080/test/public/index.jsp"

# 解析URL
parsed_url = urlparse(url)

# 提取各个部分
protocol = parsed_url.scheme
hostname = parsed_url.netloc.split(':')[0]  # 去掉端口
port = parsed_url.port if parsed_url.port else '80'  # 如果没有端口，默认为80
path = parsed_url.path
filename = parsed_url.path.split('/')[-1]  # 获取最后一个路径段作为文件名

# 构建字典
info_dict = {
    '协议': protocol,
    '主机名': hostname,
    '端口号': port,
    '路径': path,
    '文件名': filename
}

# 输出结果
print("实验运行结果：")
print(info_dict)