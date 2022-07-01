import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
import random

plt.title('Live Random Plot')
#y = [k for k in range(20,100,3)]
#x = [k for k in range(len(y))]

#plt.plot(x,y)
#plt.plot(x,y, 'y--*')
plt.xlabel('Quantity')
plt.ylabel('Price')
plt.ylim(0,10)
plt.grid(True)
plt.ion()

x=[]
y=[]
k=0

while True:
    k += 1
    x.append(k)
    y.append(random.randrange(0,10))
    
    plt.plot(x,y,'c-')
    plt.show()
    plt.pause(0.00001)
#y1 = numpy.arange(1,5,0.2)
#x = [k for k in range(len(y1))]
#plt.plot(x,y1,'r--',
#         x,0.5*y1**2,'b--',
#         x,0.2*y1**3,'g--')
#plt.prid(True)
#plt.show()
