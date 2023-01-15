#!/usr/bin/python3
from sys import argv
from MySQLdb import connect

conn = connect(user=argv[1], passwd=argv[2], db=argv[3])
cur = conn.cursor()
cur.execute("SELECT cities.name, states.name FROM cities \
            JOIN states ON cities.state_id = states.id \
            ORDER BY cities.id ASC")

pList = [pair[0] for pair in cur.fetchall() if argv[4] == pair[1]]
print(", ".join(pList))
