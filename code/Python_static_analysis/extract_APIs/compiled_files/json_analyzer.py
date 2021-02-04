import json

def found_api_in_parsed_header():
    function_file = open('parsed_header.txt','r')
    function_data = function_file.read()
    print(type(function_data))
    num_found = 0
    #num_pygen = 0
    for name in function_names:
        m = function_data.find(name)
        #tmp_name = name[3:]
        #print(tmp_name)
        #n = generated_funcs.find(tmp_name)
        if(m > 0):
            num_found = num_found+1
    #if(m == -1):
        #print(name)
    #if(n>0):
    #    num_pygen = num_pygen + 1
    #if(n == -1):
        #print(tmp_name)
    print(num_found)
    #print(num_pygen)

function_names = []
f = open('pyopencv_signatures.json','r')
#py_generated_func_file = open('pyopencv_generated_funcs.h')
#generated_funcs = py_generated_func_file.read()
log_file = open('record_log.txt','r')

data = json.load(f)
num = 0

for key in data.keys():
    record = data[key][0]
    tmp_key = record.keys()
    if('arg' in tmp_key):
        num = num+1
        function_names.append(record['name'])
        if('retval' in record['ret']):
            print(record['name'])
    #print(num)
#print(function_names)


