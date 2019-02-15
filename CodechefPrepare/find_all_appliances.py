import MySQLdb
import sys
import os
import argparse


class DB:
    def __init__(self):
        self.db = MySQLdb.connect("10.128.20.18", "remote_user", "fireeye", "wmps")
        self.cursor = self.db.cursor()

    def execute_query(self, query):
        self.cursor.execute(query)

    def get_one_row(self):
        return self.cursor.fetchone()

    def get_all(self):
        return self.cursor.fetchall()

    def update_db(self, sql_file):
        self.cursor.execute('source {}'.format(sql_file))

    def close(self):
        self.db.close()


def find_device():
    db = DB()
    query = "select name, ssh_ip from testbeds where ssh_ip like '10.128%'"

    db.execute_query(query)
    # data = db.get_one_row()


    data = db.get_all()

    fmt = """
client %s {
secret = testing123
nas_type = other
}

"""

    fl = open('list.txt', 'w')

    for tpl in data:
        ip = tpl[1]
        fl.write(fmt % ip)

    fl.close()

if __name__ == '__main__':
    find_device()