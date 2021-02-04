import os
from os import listdir
from os.path import isfile, join
import cxxfilt

bcpath="/home/meng/Desktop/libfacedetection"
outputDir="/home/meng/Desktop/libfacedetection"
filelist=os.listdir(bcpath)
toolpath="/home/meng/Desktop/llvm-clang-samples/build/simple_module_pass"
filenamelist=[]
for f in filelist:
    fname=f[1:-9]
    #print(fname)
    command=toolpath+" "+bcpath+"/"+f+" >> "+outputDir+"/"+fname+".txt"
    filenamelist.append(outputDir+"/"+fname+".txt")
    os.system(command)
print("data load done")
demangledlist=[]
length=len(filenamelist)
i=0
for filename in filenamelist:
    i=i+1
    # print(os.path.basename(filename)+" is analysed")
    readfile=open(filename,'r')
    print(filename)
    while True:
        readline=readfile.readline().strip('\n')
        print(readline)
        if not readline:
            break
        if ".cpp" in readline:
            break
        if "llvm" in readline:
            break
        # print(readline)
        # print(readline.find("cv"))
        # if readline.find("cv")!=0 or readline.find("caffe")!=0:
        #     break
        try:
            demangledline=cxxfilt.demangle(readline,external_only=False)
            # print(demangledline.find("cv"))
            # print(demangledline)
            # if demangledline.find("cv")!=0 or demangledline.find("caffe")!=0:
            #     break
        except ValueError:
            print("failed:"+readline)
        demangledlist.append(demangledline)
    print("\n\n\n\n\n\n\n\n\n")
    readfile.close()
    my_dict = {i:demangledlist.count(i) for i in demangledlist}
    print(my_dict)
    writefile=open("./demangled/"+os.path.basename(filename),"w")
    writefile.write(filename)
    writefile.write("\n")
    for key in my_dict:
        writefile.write(key+':'+str(my_dict[key]))
        #print(key+':'+str(my_dict[key]))
        writefile.write("\n")
    writefile.write("\n\n")
    writefile.close()
    my_dict.clear()
    demangledlist.clear()
    print(os.path.basename(filename)+" is done")
    print(str(i)+"/"+str(length))
    # print("\n")




