#!/usr/bin/python3

from sys import argv
from MySQLdb import connect

conn = connect(user=argv[1], passwd=argv[2], db=argv[3])
cur = conn.cursor()
cur.execute("SELECT * FROM Persons")
# [print(person[2]) for person in cur.fetchall()]
print(cur.fetchone())
