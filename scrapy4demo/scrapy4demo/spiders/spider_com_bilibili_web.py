# -*- coding: utf-8 -*-
"""spider for https://www.bilibili.com/ranking @ bilibili ranking @ 2020.04.20

Note: 爬取 bilibili 全站榜单
"""

import json
import logging
import re
import time
import scrapy
from scrapy.http import HtmlResponse
from scrapy4demo.model.item_com_bilibili_web import WatchesItem
from scrapy4demo.utils import str_utils


class SpiderXpath(scrapy.Spider):
    name = 'spider_com_bilibili_web'
    custom_settings = {
        'ITEM_PIPELINES': {
            'scrapy4demo.pipelines.pipeline_com_bilibili_web.WatchesPipeline': 400
        }
    }
    handle_httpstatus_list = [404]

    ranking_url = [
        'https://www.bilibili.com/ranking',
    ]
    start_urls = ranking_url[:]

    # 是否开启 chrome 渲染
    chromeDriverOpen = False

    page_dereplication_map = {}

    def parse(self, response):
        """ crawle bilibili ranking

        Note: 爬取 bilibili 排行榜
        """
        logging.info('>>>>>>>>>>> %s >>>>>>>>>>>', 'start crawling')

        item = WatchesItem()
        # item attr
        # 1. url            视频地址
        # 2. create_time    爬取时间
        # 3. vedio_ranking  视频排名
        # 4. vedio_name     视频名称
        # 5. vedio_up       UP 主
        # 6. vedio_cover    视频封面
        # 7. play_count     视频播放量
        # 8. comment_count  视频评论数
        # 9. sum_up_score   视频综合评分
        for rank_item in response.xpath("//li[@class='rank-item']"):
            item["vedio_ranking"] = rank_item.xpath(".//div[@class='num']/text()").extract_first()
            item["vedio_name"] = rank_item.xpath(".//div[@class='info']/a/text()").extract_first()
            item["vedio_up"] = rank_item.xpath(".//div[@class='info']//div[@class='detail']/a//span/text()").extract_first()
            # vedio_cover 需动态渲染（因为元素为懒加载）
            item["vedio_cover"] = rank_item.xpath(".//div[@class='img']//img/@src").extract_first()
            item["play_count"] = rank_item.xpath(".//div[@class='info']//div[@class='detail']/span[1]/text()").extract_first()
            item["comment_count"] = rank_item.xpath(".//div[@class='info']//div[@class='detail']/span[2]/text()").extract_first()
            item["sum_up_score"] = rank_item.xpath("//div[@class='info']//div[@class='pts']//div/text()").extract_first()
            item["url"] = response.url
            item["create_time"] = int(round(time.time() * 1000))
            yield item

def main():
    print('test')


if __name__ == "__main__":
    main()
