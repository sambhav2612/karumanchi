import os
import shutil


def createOut(directory):
    main = os.path.abspath(os.path.join(os.path.dirname(
        __file__), '..', 'main/')).replace('\\', '/')
    sub_main = os.listdir(main)
    try:
        for item in sub_main:
            out = os.path.join(main + '/' + item, 'out/').replace('\\', '/')
            current = os.path.join(main + '/', item).replace('\\', '/')
            # creates a output directory
            if not os.path.exists(out):
                os.makedirs(out)
            with open(os.path.join(out + "readme.md").replace('\\', '/'), "a") as fh:
                fh.seek(0)
                fh.write("# Out\n")
                fh.close()
            # list all files inside the sub-directories
            files = os.listdir(current)
            for fil in files:
                my_file = os.path.join(current + '/', fil).replace('\\', '/')
                # for every output file
                if fil.endswith(".exe") or fil.endswith(".exe.stackdump") or fil.endswith(".hpp.gch") or fil.endswith(".h.gch"):
                    # copy to out/ and delete original copy
                    shutil.copy(my_file, out)
                    os.remove(my_file)
                # check for every source file
                if fil.endswith(".cpp"):
                    with open(fil, 'r+') as fh:
                        text = fh.readlines()
                        fh.seek(0)
                        text.insert(2, "using namespace std;\n")
                        fh.writelines(text)
                        fh.close()
                # check for every header file
                if fil.endswith(".hpp"):
                    with open(fil, 'r+') as fh:
                        text = fh.readlines()
                        fh.seek(0)
                        text.insert(0, "#pragma once\n")
                        fh.writelines(text)
                        fh.close()

    except OSError:
        print('Error: Creating directory - ' + out)


createOut('out')
