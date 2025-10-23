from urllib.parse import urlparse

url = "http://www.skyme.org:8080/test/public/index.jsp"
parsed_url = urlparse(url)   #解析该网址
#提取各部分
protocol = parsed_url.scheme    #提取协议名
hostname = parsed_url.netloc.split(':')[0] #提取主机名
port = parsed_url.port if parsed_url.port else '80'  #提取端口
path = parsed_url.path #提取路径
filename = parsed_url.path.split('/')[-1] #提取文件名

#构建字典
url_info = {
    "协议": protocol,
    "主机名": hostname,
    "端口号": port,
    "路径": path,
    "文件名": filename
}

#输出结果
print("实验运行结果：")
print(url_info)