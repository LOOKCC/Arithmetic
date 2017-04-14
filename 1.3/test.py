import random
import os
a="time ~/code/arithmetic/1.3/a.out"
numberlist=[10]
for n in numberlist:
    #finput=os.popen(a,"w")
    #finput.write(str(n)+"\n")
    print(str(n))
    for row in range(n):
        for line in range(n):
            cancross=random.randint(0,1)
            if cancross==1:
                #finput.write(str(row+1)+" "+str(line+1)+" "+str(1))
                print(str(row+1)+" "+str(line+1)+" "+str(1))
    #finput.write("0 0 0\n")
    print("0 0 0")