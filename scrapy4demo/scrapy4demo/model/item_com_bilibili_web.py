# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class WatchesItem(scrapy.Item):
    """define the fields for record item

    Note: the spider should at lease contains fields as bellow:
        1. url            视频地址
        2. create_time    爬取时间
        3. vedio_ranking  视频排名
        4. vedio_name     视频名称
        5. vedio_up       UP 主
        6. vedio_cover    视频封面
        7. play_count     视频播放量
        8. comment_count  视频评论数
        9. sum_up_score   视频综合评分
    """
    url = scrapy.Field()
    create_time = scrapy.Field()
    vedio_ranking = scrapy.Field()
    vedio_name = scrapy.Field()
    vedio_up = scrapy.Field()
    vedio_cover = scrapy.Field()
    play_count = scrapy.Field()
    comment_count = scrapy.Field()
    sum_up_score = scrapy.Field()