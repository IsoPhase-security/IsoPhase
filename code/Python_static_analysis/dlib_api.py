# importing the libraries
from bs4 import BeautifulSoup
import requests

arrow1 = "→"
arrow2 = "-&gt"
url="http://dlib.net/python/index.html#dlib.array"

# Make a GET request to fetch the raw HTML content
html_content = requests.get(url).text

# lines = html_content.splitlines()
# for line in lines:
#     print(line)
# Parse the html content
soup = BeautifulSoup(html_content, "html")


# handle public function
function_records = soup.find_all("dl", attrs={"class":"function"})
for function_record in function_records:
    # print(function_record.find("dt"))
    function_name = function_record.find("dt").get("id")
    print(function_name)
    doc_content = function_record.find("dt").text.split()
    
    if(arrow1 not in doc_content):#handle overloaded function
        print("it is a overloaded function")
        print(function_record.find("li").text.split()[-1])
    else:
        print("it is not a overloaded function")
        print(doc_content[-1][0:-2])
    print("----------------")

#handle class method
class_records = soup.find_all("dl", attrs={"class":"class"})
for class_record in class_records:
    class_name = class_record.find("dt").get("id")
    print(class_name)
    class_methods = class_record.find_all("dl", attrs={"class":"method"})
    print("----------------")
    for method in class_methods:
        method_name = method.find("dt").get("id")
        print(method_name)
        method_text = method.find("dt").text
        if(arrow1 not in method_text):
            return_type = method.find("li").text.split()[-1]
            print("it is an overloaded method")
            print(method.find("li").text)
            print(return_type)
        else:
            return_type = method_text.split()[-1][0:-2]
            print("it is not an overloaded method")
            print(method_text)
            print(return_type)
        print("---------------------")

#print(function_records)
