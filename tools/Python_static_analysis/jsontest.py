import json
with open('opencv_api.json') as json_file:
  data = json.load(json_file)
  for api in data:
    print(data[api])
print(type((640,  480)))