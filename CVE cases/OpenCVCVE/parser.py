import ast
import sys
import os


class Analyzer(ast.NodeVisitor):
    def __init__(self):
        self.names = set(["cv2"])
        self.stats = {}  # {method:[l1, l3, l5...]}
        self.current_path = ''

    def pre_visit(self, node, path):
        self.current_path = path
        self.visit(node)

    def visit_Call(self, node):
        # print(node.func._fields)#ast.iter_fields(node))
        if 'value' in node.func._fields and 'id' in node.func.value._fields:  # check if fields exist
            if node.func.value.id in self.names:  # check if in set
                method = f'{node.func.value.id}.{node.func.attr}'
                if self.stats.get(method) is not None:
                    # self.stats[method].append(self.current_path + "@L:" + str(node.func.lineno))
                    self.stats[method].append(node.func.lineno)
                else:
                    self.stats[method] = [node.func.lineno]
        self.generic_visit(node)

    def visit_Assign(self, node):
        # TODO: need to find a way to traverse the tree automatically and get to the leaf node
        if ('value' in node.value._fields and  # check node.value.value exists
            type(node.value.value) is not bool and
            node.value.value is not None and
            'func' in node.value.value._fields and  # check node.value.value.func exists
            'id' in node.value.value.func.value._fields and  # check node.value.value.func.value.id exists
            node.value.value.func.value.id in self.names) or (  # ast.Subscript - func has field value.id
                'func' in node.value._fields and # check if node.value.func exists
                'value' in node.value.func._fields and  # check if node.value.func.value exists
                'id' in node.value.func.value._fields and  # check if node.value.func.value.id exists
                node.value.func.value.id in self.names):  # ast.Call
            for target in node.targets:
                self.names.add(f'{target.id}')
        self.generic_visit(node)


    def report(self):
        print(f'set: {self.names}')
        for stat in self.stats:
            print(f'{stat}; {self.stats[stat]}; count={len(self.stats[stat])}')


if __name__ == "__main__":

    # TODO: false positive at data_augmentation.py @L213 "image_array = cv2.cvtColor(..."->the returned type is ndarray

    if len(sys.argv) < 2:
        exit(1)

    # file to be read
    #with open(sys.argv[1], "r") as file:
    #    tree = ast.parse(file.read())

    root = sys.argv[1]
    analyzer = Analyzer()

    for dirpath, subdir, files in os.walk(root):
        for file in files:
            cur_file = os.path.join(dirpath, file)
            print(f'[DEBUG]: checking file {cur_file}...')
            if file[-3:] == '.py':
                with open(cur_file, "r") as source:
                    tree = ast.parse(source.read())
                    analyzer.pre_visit(tree, cur_file)
                    print(f'[DEBUG]: finished checking file {file}!')

    analyzer.report()
    
