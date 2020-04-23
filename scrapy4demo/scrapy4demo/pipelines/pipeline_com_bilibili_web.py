# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html

import logging
import json
from scrapy4demo.dao import mongodb


class WatchesPipeline(object):

    # item count
    __count = 0
    # 去重
    __dereplication_map = {}

    # 连接数据库
    def __init__(self):
        # self.__mongo_dao = mongodb.MongoDAO("bilibili_com")
        pass

    def open_spider(self, spider):
        pass

    def close_spider(self, spider):
        # self.__mongo_dao.close_client()
        # self.__mongo_dao.close_server()
        pass

    def process_item(self, item, spider):
        logging.info(">>>>>>>>>>> item %s item >>>>>>>>>>>", str(item))

        # 使用 dict 转换 item，然后插入数据库
        item_info = dict(item)
        dereplication_key = item["vedio_ranking"] + "@" + item["vedio_name"]

        if dereplication_key not in self.__dereplication_map:
            self.__count = self.__count + 1
            self.__dereplication_map[dereplication_key] = 1
            # self.__mongo_dao.insert_one("ranking_items", item_info)
            path = './dev_logs/out/result.txt'
            with open(path, "a", encoding='utf8') as f:
                f.write(json.dumps(item_info, ensure_ascii=False) + '\n')
            logging.info(">>>>>>>>>>> item count %s item count >>>>>>>>>>>",
                         str(self.__count))

        return item_info
