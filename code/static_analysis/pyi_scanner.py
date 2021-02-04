from typed_ast import ast3
import ast
import astpretty
import re
import os
import astunparse
# txt = "The rain in Spain"
# x = re.search("^The.*Spain$", txt)

type_list = []
def typed_ast_test():
    pyi_file = open("comment.py",'r')
    file_content = pyi_file.read()
    pyi_ast = ast3.parse(file_content)
    functionDef_node = ast3.FunctionDef()
    m = ast3.dump(pyi_ast)
    print(m)
    for node in ast3.walk(pyi_ast):
        if(type(node) == type(functionDef_node)):
            print("-----------------------------")



# def ast_test():
#     pyi_file = open("comment.py",'r')
#     file_content = pyi_file.read()
#     pyi_ast = ast.parse(file_content)
#     astpretty.pprint(pyi_ast)

def deep_type_search(filename:str):
    pyi_file = open(filename,"r")
    pyi_content = pyi_file.read()
    pyi_ast = ast3.parse(pyi_content)
    functionDef_node = ast3.FunctionDef()
    for node in ast3.walk(pyi_ast):
        if(type(node) == type(functionDef_node)):
            if(node.returns is None):
               target_function_name = node.name
               regex_str = "r\"\"\""+target_function_name+"\(" +".*->"
               py_file = open("comment.py")
               #print(regex_str)
               py_content = py_file.readlines()
               for line in py_content:
                   result = re.search(regex_str,line)
                   #print(line)
                   if(result is not None):
                        print(line)
                        return_type = line[result.end()+1:-1]
                        print(return_type)
                        print(len(return_type))
                        print(result)
                

def get_pyi_files(rootdir:str):# scan and return the list of pyi files
    pyi_list = []
    for subdir, dirs, files in os.walk(rootdir):
        for file in files:
            #print os.path.join(subdir, file)
            filepath = subdir + os.sep + file
            if filepath.endswith(".pyi"):
                pyi_list.append(filepath)
    return pyi_list

def find_parent_node(root):
    for node in ast3.walk(root):
        node.inclass = False
        for child in ast3.iter_child_nodes(node):
            child.parent = node

def handle_subscript(node):
    print(node.value.id)
    subscript_node = ast3.Subscript()
    if(type(node.slice.value) == type(subscript_node)):
        handle_subscript(node.slice.value)

def handle_returns_node(node):
    classDef_node = ast3.ClassDef()
    functionDef_node = ast3.FunctionDef()
    nameConstant_node = ast3.NameConstant()
    name_node = ast3.Name()
    subscript_node = ast3.Subscript()
    attribute_node = ast3.Attribute()
    print("function: " + node.name)
    if(type(node.returns) == type(nameConstant_node)):
        if(node.returns.value is None):
            # continue
            print("return value: " + "None")
        else:
            # continue
            print("return value: " + node.returns.value)
    elif(type(node.returns) == type(name_node)):
        # continue
        print("return value: " + node.returns.id)
    elif(type(node.returns) == type(subscript_node)):
        #continue
        if("ndarray" not in ast3.dump(node.returns)):
            # continue
            print("return value: unsupported type")
            print(astunparse.unparse(node.returns))
        else:
            print("return value: " + astunparse.unparse(node.returns))
            #handle_subscript(node.returns)
            #print(ast3.dump(node.returns))
            #print(astunparse.unparse(node.returns))
    elif(type(node.returns) == type(None)):
         # continue
         print("return value: " + "None")
    elif(type(node.returns) == type(attribute_node)):
        # continue
        print("return value: " + node.returns.value.id+"."+node.returns.attr)
    else:
        if(type(node.returns) not in type_list):
            type_list.append(type(node.returns))

def get_return_type(pyi_path:str):
    class_node_list = []
    pyi_file = open(pyi_path,"r")
    pyi_content = pyi_file.read()
    pyi_ast = ast3.parse(pyi_content)

    classDef_node = ast3.ClassDef()
    functionDef_node = ast3.FunctionDef()
    nameConstant_node = ast3.NameConstant()
    name_node = ast3.Name()
    subscript_node = ast3.Subscript()
    attribute_node = ast3.Attribute()

    find_parent_node(pyi_ast)
    for node in ast3.walk(pyi_ast):
        if(type(node) == type(classDef_node)):
            # print(node.name)
            class_node_list.append(node)
            for in_class_node in ast3.walk(node):
                in_class_node.inclass = True 

    for class_node in class_node_list:
        print("class: "+class_node.name)
        for node in ast3.walk(class_node):
            if(type(node) == type(functionDef_node)):
                handle_returns_node(node)

                # print("function: " + node.name)
                # if(type(node.returns) == type(nameConstant_node)):
                #     if(node.returns.value is None):
                #         # continue
                #         print("return value: " + "None")
                #     else:
                #         # continue
                #         print("return value: " + node.returns.value)
                # elif(type(node.returns) == type(name_node)):
                #     # continue
                #     print("return value: " + node.returns.id)
                # elif(type(node.returns) == type(subscript_node)):
                #     #continue
                #     if("ndarray" not in ast3.dump(node.returns)):
                #         # continue
                #         print("return value: unsupported type")
                #     else:
                #         print("return value: " + astunparse.unparse(node.returns))
                #         #handle_subscript(node.returns)
                #         #print(ast3.dump(node.returns))
                #         #print(astunparse.unparse(node.returns))
                # elif(type(node.returns) == type(None)):
                #     # continue
                #     print("return value: " + "None")
                # elif(type(node.returns) == type(attribute_node)):
                #     # continue
                #     print("return value: " + node.returns.value.id+"."+node.returns.attr)
                # else:
                #     if(type(node.returns) not in type_list):
                #         type_list.append(type(node.returns))      
        print("--------------------------------")
    print("out class APIs")
    for node in ast3.walk(pyi_ast):
        if(type(node) == type(functionDef_node) and (node.inclass is False)):
            print("aa")
            handle_returns_node(node)
    




pyi_list = get_pyi_files("numpy-master")
print(pyi_list)
for pyi_path in pyi_list:
    print(pyi_path)
    get_return_type(pyi_path)
#print(type_list)


        


# pre_regext_str = "r\"\"\".*->"
# test_function = "def sigmoid(input):"
# test_pyi_def = "def sigmoid(input: Any): ..."
# deep_type_search("short_file.pyi")
