import random
import os
a="time ~/code/arithmetic/1.1/a.out"
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
    finput.write(str(random.randint(1,n))+" "+str(random.randint(1,n))+"\n")