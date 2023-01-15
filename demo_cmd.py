#!/usr/bin/python3
import cmd

class Demo(cmd.Cmd):
    def default(self, line):
        if line == 'test':
            print(line)
        else:
            print("*** Unknown syntax: {}".format(line))
            return False

    def do_EOF(self, line):
        return True

    def do_quit(self, line):
        return True

    def do_hello(self, line):
        print('hello')

if __name__ == '__main__':
    Demo().cmdloop()
