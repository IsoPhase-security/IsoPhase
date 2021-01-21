from typed_ast import ast3
import ast
import astpretty
import re

txt = "The rain in Spain"
x = re.search("^The.*Spain$", txt)


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



def ast_test():
    pyi_file = open("comment.py",'r')
    file_content = pyi_file.read()
    pyi_ast = ast.parse(file_content)
    astpretty.pprint(pyi_ast)

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
                




            
               


    
    





pre_regext_str = "r\"\"\".*->"
test_function = "def sigmoid(input):"
test_pyi_def = "def sigmoid(input: Any): ..."
deep_type_search("short_file.pyi")
