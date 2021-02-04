import argparse
import ast
import json
import sys
debug_flag = 1
APIs=[]
mat_apis=["imread"]
Function_Def=[]
Function_Args={}
Function_Returns = {}
Module_alias = {}

def load_modules(ast_node):
    import_node = ast.Import()
    importFrom_node = ast.ImportFrom()
    for node in ast.walk(ast_node):
        if(type(node)==type(import_node)):
            length = len(node.names)
            i = 0
            while(i<length):
                if(node.names[i].asname is None):
                    Module_alias[node.names[i].name] = node.names[i].name
                else:
                    Module_alias[node.names[i].asname] = node.names[i].name
                i = i+1
        if(type(node)==type(importFrom_node)):
            print(node.module)
            for name in node.names:
                print(name.name)
                print(name.asname)





def printf(debug_str):
    if(debug_flag):
        print(debug_str)

def find_parent_node(root):
    for node in ast.walk(root):
        for child in ast.iter_child_nodes(node):
            child.parent = node

def type_inference_assignment(Assign_node):
    Assign_node.targets[0].type = Assign_node.value.type

def type_inference_API(API_node):
    print("inference_API")

def init_node_type(root):
    for node in ast.walk(root):
        node.type = ["unknown"]

def find_defined_function(ast_node):
    func_def_node = ast.FunctionDef()
    for node in ast.walk(ast_node):
        if(type(node)==type(func_def_node)):
            Function_Def.append(node.name)
            print(node.name)
            if(len(node.args.args)>0):
                tmp_arg_list = []
                arg_len = len(node.args.args)
                i=0
                while i < arg_len:
                    argument = node.args.args[i].arg
                    print(argument)
                    tmp_arg_list.append(argument)
                    i=i+1
                Function_Args[node.name] = tmp_arg_list
            else:
                Function_Args[node.name] = []

def get_function_return_var(func_def_node):
    return_node = ast.Return()
    num_node = ast.Num()
    name_node = ast.Name()
    call_node = ast.Call()
    for node in ast.walk(func_def_node):
        if(type(node) == type(return_node)):
            value_node = node.value
            if(type(value_node)==type(name_node)):
                Function_Returns[func_def_node.name] = value_node.id
                printf(value_node.id)
            elif(type(value_node)==type(num_node)):
                Function_Returns[func_def_node.name] = value_node.n
                printf(value_node.n)







def func_from_def_to_ref(def_node):
    func_def_node = ast.FunctionDef()

def fuc_from_ref_to_def(ref_node):
    func_ref_node = ast.Call()


class Analyzer(ast.NodeVisitor):

    def visit_Assign(self, node):
        print(node.targets[0].id)
        type_inference_assignment(node)
        self.generic_visit(node)

    def visit_Name(self,node):
        if(node.id == "cv2"):
            func_node = node.parent
            #print(func_node.attr)
            if(func_node.attr in mat_apis):
                print(func_node.attr)
                call_node = func_node.parent
                call_node.type = ["mat"]
        #self.generic_visit(node)

def main(filepath):
    #print(filepath)
    source_file = open(filepath,'r')
    source_content = source_file.read()
    ast_root = ast.parse(source_content)
    load_modules(ast_root)
    print(Module_alias)
    find_parent_node(ast_root)
    init_node_type(ast_root)
    analyzer = Analyzer()
    Name_node =ast.Name()
    Assign_node = ast.Assign()
    for node in ast.walk(ast_root):
        if(type(node) == type(Name_node)):
            Analyzer.visit_Name(analyzer,node)
            print(node.id)
    for node in ast.walk(ast_root):
        if(type(node) == type(Assign_node)):
            print(node.targets[0].type)
            type_inference_assignment(node)
            print(node.targets[0].type)
    find_defined_function(ast_root)
    print(Function_Def)
    print(Function_Args)


            

if __name__ == "__main__":
    filepath = "test_cases\\assignment_type_inference.py"
    main(filepath)