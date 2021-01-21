import tokenize
import re

# def filter_comment_and_spaceline(content):
#     tmp_cache = []
#     for line in content:
#         tmp_line = filter_comment(line)
#         tmp_cache.append(tmp_line)
#         # if not re.match(r'^\s*$', line):
#         #     tmp_cache.append(line)
#     log_file = open("tmp_cache.py","w")
#     for line in tmp_cache:
#         log_file.write(line)

""" Strip comments and docstrings from a file.
"""

import sys, token, tokenize

class class_block:
    def __init__(self):
        self.begin = 0
        self.end = 0

def do_file(fname):
    """ Run on just one file.
    """
    source = open(fname)
    mod = open("output.py", "w")

    prev_toktype = token.INDENT
    first_line = None
    last_lineno = -1
    last_col = 0

    tokgen = tokenize.generate_tokens(source.readline)
    for toktype, ttext, (slineno, scol), (elineno, ecol), ltext in tokgen:
        if 0:   # Change to if 1 to see the tokens fly by.
            print("%10s %-14s %-20r %r" % (
                tokenize.tok_name.get(toktype, toktype),
                "%d.%d-%d.%d" % (slineno, scol, elineno, ecol),
                ttext, ltext
                ))
        if slineno > last_lineno:
            last_col = 0
        if scol > last_col:
            mod.write(" " * (scol - last_col))
        if toktype == token.STRING and prev_toktype == token.INDENT:
            # Docstring
            mod.write("#--")
        elif toktype == tokenize.COMMENT:
            # Comment
            #mod.write("##\n")
            print("comment removed")
        else:
            mod.write(ttext)
        prev_toktype = toktype
        last_col = ecol
        last_lineno = elineno

def write_log(content):
    log_file = open("tmp_cache.py","w")
    for line in content:
        log_file.write(line)

def filter_comment(line):
    m = re.match(r'^([^#]*)#(.*)$', line)
    if m:  # The line contains a hash / comment
        line = m.group(1)
    return line

def filter_spaceline(line):
    if not re.match(r'^\s*$', line):
        return line
    else:
        line = ""
        return line

def if_ended(line):
    last_char = line[-1]
    if(last_char == "..."):
        return 1
    else:
        return 0

def find_space_offset(line):
    i = 0
    while(i<len(line)):
        if(line[i]!=" "):
            return i
        i = i+1
    return -1

def remove_space_begin_and_end(line):
    begin = 0
    end = len(line) - 1
    while(begin < len(line)):
        if(line[begin]!=" "):
            break
        begin = begin+1
    
    while(end >= 0):
        if(line[end]!=" "):
            break
        end = end - 1
    tmp_line = line[begin:end]
    return tmp_line



def find_class_block(content):
    print("get into find_class_block")
    line_number = 0
    block_list = []
    print(len(content))
    while(line_number<54):
        tmp_prefix = content[line_number][0:5]
        tmp_flag = 0
        print(content[line_number])
        print(len(content[line_number]))
        print(tmp_prefix)
        print(content[line_number][len(content[line_number])-1])
        print("---------------")
        if(tmp_prefix == "class " and (content[line_number][-1] == ":" or content[line_number][-1] == ": ...")):
            print(line_number)
            tmp_class = class_block()
            tmp_class.begin = line_number
            tmp_flag = line_number+1
            while(tmp_flag<len(content)):
                if(content[tmp_flag][0] != " " ):
                    tmp_class.end = tmp_flag-1
                    block_list.append(tmp_class)
                    print(tmp_flag)
                    break
                tmp_flag = tmp_flag + 1
        line_number = line_number + 1
    return block_list
                






def main():
    test_file = "__init__.pyi"
    do_file(test_file)
    pyi_file  = open("output.py",'r')
    pyi_content = pyi_file.readlines()
    line_number = 0
    block_list = find_class_block(pyi_content)

    for block in block_list:
        print("----------------------")
        print(block.begin)
        print(block.end)
        print("-------------------")
    # while(line_number < len(pyi_content)):
    #     offset = find_space_offset(pyi_content[line_number])

    # tmp_content = []
    # for line in pyi_content:
    #     tmp_line = filter_spaceline(line)
    #     tmp_content.append(tmp_line)
    # write_log(tmp_content)
    # for line in tmp_content:
    #     if("->" in line):
    #         splitted_line = line.split()
    #         location_end_name = splitted_line[1].find("(")
    #         api_name = splitted_line[1][0:location_end_name-1]
    #         return_type = splitted_line[3][0:-1]
    #         print(api_name)
    #         print(return_type)
    #         print(splitted_line)
            
    

main()