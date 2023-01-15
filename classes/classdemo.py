#!/usr/bin/python3

class Student:
    public = 0
    __private = 1
    def __init__(self):
        self.__privateInst = 10
        self.publicInst = 20

std1 = Student()
print(Student.count)


