"""mongodb module - 爬虫访问、操作 mongodb

Useage:
    import module - from scrapy4demo.dao import mongodb

    mongo_dao = mongodb.MongoDAO(数据库名称)
    record = {
        'test1': 'testvalue1',
        'test2': 'testvalue2'
    }
    mongo_dao.insert_one(collection 名称, record)
"""

import configparser
from deprecated.sphinx import deprecated
import os
import threading
import pymongo
import sshtunnel


class NoneIdError(ValueError):
    pass


class MongoDAO(object):

    _instance_lock = threading.Lock()

    # 单例模式
    def __new__(cls, *args, **kwargs):
        if not hasattr(MongoDAO, "_instance"):
            with MongoDAO._instance_lock:
                if not hasattr(MongoDAO, "_instance"):
                    MongoDAO._instance = object.__new__(cls)
        return MongoDAO._instance

    def __init__(self, db_name):
        """init class

        Args:
            the database name that you want to connect
        """
        # read config
        config = configparser.ConfigParser()
        config.read(
            os.path.join(
                os.path.abspath(os.path.dirname(__file__)), '../config',
                'db.ini'))
        # SSH connection config
        self.__ssh_enable = config['ssh']['enable']
        self.__ssh_host = config['ssh']['host']
        self.__ssh_port = config['ssh']['port']
        self.__ssh_user = config['ssh']['user']
        self.__ssh_key_path = config['ssh']['key_path']
        # mongo config
        self.__mongo_host = config['mongo']['host']
        self.__mongo_port = config['mongo']['port']
        if db_name:
            self.__mongo_database = db_name
        else:
            # for test
            self.__mongo_database = config['mongo']['database']
        self.__mongo_account = config['mongo']['user']
        self.__mongo_pwd = config['mongo']['pwd']

        if self.__ssh_enable == 'true':
            # get ssh connection
            self.__server = sshtunnel.SSHTunnelForwarder(
                (self.__ssh_host, int(self.__ssh_port)),
                ssh_username=self.__ssh_user,
                ssh_pkey=self.__ssh_key_path,
                remote_bind_address=(self.__mongo_host,
                                     int(self.__mongo_port)),
                # local_bind_address=('0.0.0.0', 10022)
            )
            self.__server.start()
            # get mongo client
            self.__client = pymongo.MongoClient(self.__mongo_host,
                                                self.__server.local_bind_port)
            self.__client.admin.authenticate(
                self.__mongo_account,
                self.__mongo_pwd,
                mechanism='SCRAM-SHA-1')
        else:
            # get mongo client
            self.__client = pymongo.MongoClient(self.__mongo_host,
                                                int(self.__mongo_port))
            self.__client.admin.authenticate(
                self.__mongo_account,
                self.__mongo_pwd,
                mechanism='SCRAM-SHA-1')

    def close_server(self):
        """close ssh server

        Note: close ssh connection when the spider exit
        """
        self.__server.stop()
        self.__server.close()

    def close_client(self):
        """close pymongo client

        Note: close pymongo client when the spider exit
        """
        self.__client.close()

    def insert_one(self, collection_name, record, insert_type=0):
        """insert one document to mongodb

        Args:
            collection_name: mongodb 文档集合（表）名称
            record: 要插入的文档数据
            insert_type: 文档插入方式
                insert_type=0: upsert, means insert document when the document
                        is not exists and update the document then the document
                        is exists
                insert_type=1: insert the document whateven the document
                                is exists or not
        """
        if not record["brand"] or not record["ref"]:
            raise NoneIdError("the brand or ref is None: %s" % record)
            return

        if insert_type == 0:
            self.__client[self.__mongo_database][collection_name].update_one(
                {
                    "brand": record["brand"],
                    "ref": record["ref"]
                },
                {"$set": record},
                upsert=True)
        elif insert_type == 1:
            self.__client[self.__mongo_database][collection_name].insert_one(
                record)

    @deprecated(reason="You should use function insert_one")
    def insertOne(self, collection_name, record):
        """insert one document to mongodb, but this function is deprecated now

        Note: this function is deprecated because of
            the inapposite function name according to
            https://zh-google-styleguide.readthedocs.io/en/latest/google-python-styleguide/python_style_rules/
        """
        self.insert_one(collection_name, record)

    @deprecated(reason="You should use function close_server")
    def closeServer(self):
        """close ssh server, but this function is deprecated now

        Note: this function is deprecated because of
            the inapposite function name according to
            https://zh-google-styleguide.readthedocs.io/en/latest/google-python-styleguide/python_style_rules/
        """
        self.close_server()

    @deprecated(reason="You should use function close_client")
    def closeClient(self):
        """close pymongo client, but this function is deprecated now

        Note: this function is deprecated because of
            the inapposite function name according to
            https://zh-google-styleguide.readthedocs.io/en/latest/google-python-styleguide/python_style_rules/
        """
        self.close_client()


def main():
    mongo_dao = MongoDAO("test")
    record = {'test1': 'testvalue1', 'test2': 'testvalue2'}
    mongo_dao.insert_one(record)


if __name__ == "__main__":
    main()
