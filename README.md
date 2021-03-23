# 用户输入助手
## 结构
* GenDict 文件夹属于**离线部分**，用于根据语料库生成服务器运行所需的中英文字典．（其中dict 文件夹中存放 cppjieba 自带的分词库，lib 文件夹存放语料库，库的内容由于容量限制删掉了）
* include 和 src 文件夹存放所有的源码与需要的头文件
* data 文件夹中存放中英文的字典．通过GenDict生成字典，然后再放到server中使用
* server文件夹为**在线部分**
* data文件夹中存放中英文字典和缓存文件
* log 文件夹存放服务器的日志
* conf 文件夹中存放配置文件．可以更改ip和port
* 运行 make 命令后，生成的 server.exe　存放于 bin 文件夹中
* SCclient 文件夹存放一个简单的客户端程序

## 需要安装的库

json、scons# User-input-assistant
