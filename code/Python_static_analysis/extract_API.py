import argparse
import ast
import json


APIs=[]
Mat_API=[]
# def type_inference_assignment(Assign_node):
#     if(Assign_node.)



def find_parent_node(root):
    for node in ast.walk(root):
        for child in ast.iter_child_nodes(node):
            child.parent = node

def init_node_type(root):
    for node in ast.walk(root):
        node.type = "unknown"

def assign_type_APIs(root):
    print("api type is assigned")

def get_index(name_list,input):
    index = 0
    for element in name_list:
        if(element == input):
            return index
        index = index + 1
    return -1

class import_Analyzer(ast.NodeVisitor):
    def __init__(self):
        self.imported_modules = {"name":[],"asname":[]}
        self.stats = {"import": [], "from": []}

    def visit_Import(self, node):
        for alias in node.names:
            # print(alias.name)
            # print(alias.asname)
            self.imported_modules['name'].append(alias.name)
            if(alias.asname is None):
                self.imported_modules['asname'].append(alias.name)
            else:
                self.imported_modules['asname'].append(alias.asname)
        self.generic_visit(node)

    def visit_ImportFrom(self, node):
        module = node.module
        for alias in node.names:
            name = alias.name
            asname = alias.asname
            fullname = module+"."+name
            self.imported_modules['name'].append(fullname)
            if(alias.asname is None):
                self.imported_modules['asname'].append(name)
            else:
                self.imported_modules['asname'].append(asname)            
        #     print(alias.name)
        #     print(alias.asname)
        # print("---------")
        self.generic_visit(node)


    def visit_ClassDef(self,node):
        base_class = node.bases[0]
        base_name = base_class.value.id
        # print(base_class.attr)
        # print(base_name)
        self.generic_visit(node)

    # def visit_Name(self,node):
    #     if(node.id == "torch" or node.id == "cv2" or node.id == "nn" or node.id == "np" or node.id == "F" or node.id == "Variable" or node.id == "img"):
    #         print("---------------------------------")
    #         print(node.id)
    #         if(hasattr(node.parent,"attr")):
    #             print(node.parent.attr)
    #     self.generic_visit(node)

    # def visit_Attribute(self,node):
    #     print(node.attr)#get_APIs
    #     self.generic_visit(node)
    
    def report(self):
        print(self.imported_modules)

class func_Analyzer(ast.NodeVisitor):
    def __init__(self):
        self.func_calls = {}    
    
    def visit_Call(self, node):
        if(hasattr(node.func,"attr")):
            func_name = node.func.attr
            attrname = []
            print(func_name)
            current_node = node.func
            while(hasattr(current_node,"value")):
                if(hasattr(current_node.value,"attr")):
                    attrname.append(current_node.value.attr)
                elif(hasattr(current_node.value,"id")):
                    attrname.append(current_node.value.id)
                current_node = current_node.value
            print(attrname)        
            # if(hasattr(node.func,"value")):
            #     if(hasattr(node.func.value,"id")):
            #         libname = node.func.value.id
        self.generic_visit(node)

def main(filepath):
    #print(filepath)
    source_file = open(filepath,'r')
    source_content = source_file.read()
    ast_root = ast.parse(source_content)
    find_parent_node(ast_root)
    import_analyzer = import_Analyzer()
    import_analyzer.visit(ast_root)
    import_analyzer.report()
    import_list = import_analyzer.imported_modules
    print("--------------------------")
    func_analyzer = func_Analyzer()
    func_analyzer.visit(ast_root)

    

if __name__ == "__main__":
    # opencv_json_file = open("opencv_api.json","r")
    # opencv_json_data = json.load(opencv_json_file)
#    pytorch_json_file = open("pytorch_api.json","r")
#    pytorch_json_data = json.load(opencv_json_file)
    parser = argparse.ArgumentParser(description='Python Static Analysis Tool')
    parser.add_argument('--filepath',default = 'sample_opencv.py',help='Path to Python code file')
    args = parser.parse_args()
    main(args.filepath)