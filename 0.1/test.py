import os
a="time ~/code/arithmetic/0.1/a.out"
textnumber=[1000,10000,100000,1000000,10000000]
for count in textnumber:
    finput=os.popen(a,"w")
    num=str(count)+"\n"
    finput.write(num)
    for n in range(count):
        finput.write(str(count-n)+"\n")