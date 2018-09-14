#!/usr/bin/env python

import shutil
import os

fullpath = os.path.join

start = "./"
dest = "./out"


def main():
    for dirname, dirnames, filenames in os.walk(start):
        for filename in filenames:
            source = fullpath(dirname, filename)
            if filename.endswith("exe") or filename.endswith("stackdump"):
                shutil.move(source, fullpath(dest, filename))


if __name__ == "__main__":
    main()
