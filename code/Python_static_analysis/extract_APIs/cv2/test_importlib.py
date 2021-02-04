import importlib
from cv2 import *
import inspect

# wildcard import above does not import "private" variables like __version__
# this makes them available
globals().update(importlib.import_module("cv2.cv2").__dict__)
m = importlib.import_module("cv2.cv2").__dict__
n = importlib.import_module("cv2.cv2")
print(m.keys())
x = inspect.getmembers(n)

# for element in x:
#     print(element)

print(m)
