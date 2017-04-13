import random
import os
#a="time ~/code/arithmetic/0.2/dirmatrix/a.out"
#a="time ~/code/arithmetic/0.2/undmatrix/a.out"
a="time ~/code/arithmetic/0.2/dislist/a.out"
#a="time ~/code/arithmetic/0.2/unlist/a.out"
numberlist=[10,50,100,500,1000]
for n in numberlist:
    finput=os.popen(a,"w")
    finput.write(str(n)+"\n")
    for row in range(n):
        for line in range(n):
            cancross=random.randint(0,1)
            if cancross==1:
                data=random.randint(1,5)
                finput.write(str(row+1)+" "+str(line+1)+" "+str(data)+"\n")
    finput.write("0 0 0\n")