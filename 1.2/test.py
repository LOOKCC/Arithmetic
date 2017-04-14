import random
import os
a="time ~/code/arithmetic/1.2/a.out"
numberlist=[10]
for n in numberlist:
    finput=os.popen(a,"w")
    finput.write(str(n))
    #print(str(n))
    for row in range(n):
        for line in range(n):
            cancross=random.randint(0,1)
            if cancross==1:
                data=random.randint(1,5)
                finput.write(str(row+1)+" "+str(line+1)+" "+str(data))
                #print(str(row+1)+" "+str(line+1)+" "+str(data))
    finput.write("0 0 0")
    #print("0 0 0")