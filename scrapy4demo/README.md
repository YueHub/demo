## crawler
> 背景：多人合作在同一个代码仓库下爬取数据，且数据来源于不同网址，固为了让不同人员能够编写各自的代码爬取给自分配的网址，同时保证项目整洁保有结构化，固制定了一些开发规范。
> 对该项目做一定记录，作为 scrapy 爬虫的 demo 以供日后需要时参考。

### 开发环境搭建
- 安装 Python，[安装教程1](http://ubuntuhandbook.org/index.php/2017/07/install-python-3-6-1-in-ubuntu-16-04-lts/)、[安装教程2](https://askubuntu.com/questions/865554/how-do-i-install-python-3-6-using-apt-get)
- 安装 Python 包管理器 pip，[官方安装文档](https://packaging.python.org/guides/installing-using-linux-tools/#installing-pip-setuptools-wheel-with-linux-package-managers)

#### 使用 pipenv
<details>
<summary>使用 pipenv</summary>

**Ubuntu**
```shell
sudo apt install python3-venv python3-pip
```

- 安装 包依赖管理工具 pipenv，[官方安装文档](https://pipenv.readthedocs.io/en/latest/install/#installing-pipenv)

```shell
# 如果本地安装的是 python3-pip
pip3 install --user pipenv

# 如果本地安装的是 python-pip
pip install --user pipenv
```

- 使用以下命令安装项目依赖包：

```shell
pipenv install
```

**Mac OS**
```shell
brew install pyenv
pyenv install 3.6.9
pyenv global system 3.6.9
pipenv --python /Users/jojoli/.pyenv/versions/3.6.9/bin/python3.6 install
```

- 启动爬虫：
  - 如果在数据库服务器外网机器上（如自己的笔记本），则设置 crawler/crawler/config/db.ini 配置文件中 [ssh] 下 enable = true
  - 如果在数据库服务器内网机器上，则设置 crawler/crawler/config/db.ini 配置文件中 [ssh] 下 enable = false

之后在命令行中运行如下命令
```shell
pipenv shell
scrapy crawl {your_spider_name}

{ your_spider_name }: 爬虫名称
```
</details>

#### 使用 requirements.txt

```shell
pip3 install -r requirements.txt -i https://mirrors.aliyun.com/pypi/simple/
```

运行爬虫
```shell
scrapy crawl {your_spider_name} 

例如：
scrapy crawl spider_com_bilibili_web

{ your_spider_name }: 爬虫名称
```

### 爬虫开发
#### 项目目录约定
    ├─ crawler                              // 项目目录
        ├─ crawler                          // 爬虫模块
            ├─ config                       // 项目配置
                ├─ jobs                     // 增量爬虫状态保存
                    ├─ spider_cn_rolex_web  // for example，命名规范 spider_网址反转_web
                ├─ db.ini                   // 数据库配置文件
                ├─ proxy_pool.txt           // 代理池
            ├─ dao                          // 数据访问层
                ├─ mongodb.py               // MongoDB 数据访问类
            ├─ model                        // 爬虫结果项结构模型
                ├─ item_cn_rolex_web.py     // for example, 命名规范 item_网址反转_web
            ├─ pipelines                    // pipeline 管道(如持久化管道)
                ├─ pipeline_cn_rolex_web.py    // for example, 命名规范 pipeline_网址反转_web
            ├─ spiders                      // 爬虫主程序目录
                ├─ spider_cn_rolex_web.py    // for example, 命名规范 spider_网址反转_web
            ├─ utils                        // 工具包
            ├─ __init__.py                  
            ├─ demo_spider_css.py           // spider css demo
            ├─ demo_spider_xpath.py         // spider xpath demo
            ├─ settings.py                  // scrapy 配置
        ├─ docs                             // 文档
        ├─ Pipfile                          // Python 依赖包
        ├─ README.md                        // readme
        ├─ scrapy.cfg                       // scrapy 配置


#### 开发规范约定
- **编码风格规范**，遵照 [Google Python 风格规范](https://zh-google-styleguide.readthedocs.io/en/latest/google-python-styleguide/python_style_rules/)。可使用 [yapf](https://github.com/google/yapf/) 作为规范检查工具，可参考[用 VScode 配置 Python 开发环境](https://zhuanlan.zhihu.com/p/31417084)
- **爬虫主程序命名规范**：在 spiders 目录下创建爬虫主程序，文件命名规范如下：
    - **Web 站点：spider_网址反转名_web，如下：**
        bilibili Web 站点（http://www.bilibili.com）

        ```
        spider_com_bilibili_web.py
        ```
    - APP 应用：spider_APP包名_app

- **pipelines 命名规范**：在 pipelines 目录了下创建爬虫主程序，文件名规范如下：
    - **Web 站点：pipeline_网址反转名_web，如下：**
        bilibili Web 站点（http://www.bilibili.com）

        ```
        pipeline_com_bilibili_web.py
        ```
    - APP 应用：pipeline_APP包名_app

- **model 命名规范**：在 model 目录了下创建爬虫主程序，文件名规范如下：
    - **Web 站点：item_网址反转名_web，如下：**
        bilibili Web 站点（http://www.bilibili.com）

        ```
        item_com_bilibili_web.py
        ```
    - APP 应用：item_APP包名_app
- **item 命名规范**：在 model 目录下的 item_xxxxx_web.py 文件自定义一些公有字段的规范

### 相关文档