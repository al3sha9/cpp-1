#!/usr/bin/python
import random, pdb, time
from tkinter import *

global time_of_sleep
time_of_sleep = 1

class visual_tower:
    def __init__(self,n,p0,p1,p2,p3):
        self.myGui=Tk()
        self.myGui.title("Tower Of Hanoi - By ShadowWalker (Ali Jafri)")
        self.p=[]
        self.p.append(p0)
        self.p.append(p1)
        self.p.append(p2)
        self.p.append(p3)
        self.Frames=[]
        self._n=n
        for i in range(4):
            self.Frames.append(Frame(self.myGui,height=self._n*100,width=(self._n+1)*25))
            self.Frames[i].grid(row=0,column=i)
        self.showit()
        self.myGui.update()

    def showit(self):
        w=range(self._n)
        for f in range(4):
            w_tmp = Canvas(self.Frames[f], width=(self._n)*25, height=26)
            w_tmp.grid(row=self._n,column=0,columnspan=(self._n+1))
            w_tmp.create_rectangle(0,0, self._n*25 ,10,fill="blue")
            ff=[0 for i in range(self._n)]
            for i in range(0,self.p[f]._size):
                w[i] = Canvas(self.Frames[f], width=(self.p[f].stk[i])*25, height=26)
                w[i].grid(row=self._n-i-1,column=0,columnspan=(self._n-self.p[f].stk[i]+1))
                w[i].create_rectangle(0,0, self.p[f].stk[i]*25 ,25,fill="black")
            for i in range(self.p[f]._size,self._n):
                w[i] = Canvas(self.Frames[f], width=(self._n)*25, height=26)
                w[i].grid(row=self._n-i-1,column=0,columnspan=(self._n+1))
                w[i].create_rectangle(0,0, self._n*25 ,25,fill="white")
        
        self.myGui.update()
        if(self.p[3]._size == self._n and self.p[0]._size == 0 ):
            self.myGui.mainloop()

class stack:
    def __init__(self,size,name):
        self.name=name
        self._size=size
        self.stk=[]
        for i in range(self._size,0,-1):
            self.stk.append(i)

    def pop(self):
        if self._size > 0:
            _tmp=self.stk[ self._size-1 ] #element to be popped
            self.stk=self.stk[:self._size-1]
            self._size=self._size-1
            return _tmp
        else:
            return -1

    def push(self,elem):
        if(self._size==0 or elem < self.stk[ self._size-1 ]):
            self.stk.append(elem)
            self._size=self._size+1
        else:
            print("This Operation is Invalid in Tower's of Hanoi ;)")

    def printit(self):
        for i in range(self._size-1,-1,-1):
            print(self.stk[i])

class hanoi:
    def __init__(self,n):
        self.n=n
        self.p1=stack(self.n,name="peg1")
        self.p2=stack(self.n,name="peg2")
        self.p3=stack(self.n,name="peg3")
        self.p4=stack(self.n,name="peg4")
        self.vt=visual_tower(self.n,self.p1,self.p2,self.p3,self.p4)
        while(self.p2.pop() !=-1):
            pass
        while(self.p3.pop() !=-1):
            pass
        while(self.p4.pop() !=-1):
            pass
        self.displayit()

    def displayit(self):
        self.vt.showit()
        time.sleep(time_of_sleep)

def tower_of_hanoi(num_of_Disks, src,  inter1, inter2, dest):
    if(num_of_Disks %2 == 1 and num_of_Disks < 2):
        print("\nTransfer Disc from\n",src.name," >> TO >> ",dest.name)
        dest.push(src.pop())
        H.displayit()
    elif(num_of_Disks % 2==0 and num_of_Disks < 3):
        print("\nTransfer Disc from\n",src.name," >> TO >> ",inter1.name)
        inter1.push(src.pop())
        H.displayit()
        print("\nTransfer Disc from\n",src.name," >> TO >> ",dest.name)
        dest.push(src.pop())
        H.displayit()
        print("\nTransfer Disc from\n",inter1.name," >> TO >> ", dest.name)
        dest.push(inter1.pop())
        H.displayit()
    else:
        tower_of_hanoi(num_of_Disks-2,src,inter2,dest,inter1)
        print("\nTransfer Disc from\n",src.name, " >> TO >> ", inter2.name)
        inter2.push(src.pop())
        H.displayit()
        print("\nTransfer Disc from\n",src.name, " >> TO >> ", dest.name)
        dest.push(src.pop())
        H.displayit()
        print("\nTransfer Disc from\n",inter2.name, " >> TO >> ", dest.name)
        dest.push(inter2.pop())
        H.displayit()
        tower_of_hanoi(num_of_Disks-2,inter1,src,inter2,dest)

def main():
    n=int(input("No. Of Disks : "))
    global H
    H = hanoi(n)
    tower_of_hanoi(n,H.p1,H.p2,H.p3,H.p4)

def TOI(N):
    global H
    H = hanoi(N)
    tower_of_hanoi(N,H.p1,H.p2,H.p3,H.p4)
    
if __name__=="__main__":
    main()
