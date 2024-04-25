stack1=[]
stack2=[]
top1=-1
top2=-1

def pop1():
    global top1
    global stack1
    if(isempty1()):
        return 
    else:
        z=stack1[top1]
        stack1.remove(stack1[top1])
        top1=top1-1
        return z
def push1(n):
    global top1
    global stack1
    top1=top1+1
    stack1.append(n)
def isempty1():
    global top1
    if(top1==-1):
        return True
    else:
        return False
    
def pop2():
    global top2
    global stack2
    if(isempty2()):
        return 
    else:
        z=stack2[top2]
        stack2.remove(stack2[top2])
        top2=top2-1
   
        return z
def push2(n):
    global top2
    global stack2
    top2=top2+1
    stack2.append(n)
def isempty2():
    global top2
    if(top2==-1):
        return True
    else:
        return False


def enqueue(x):
    push1(x)
    
def dequeue():
    global top1
    global stack1
    while(not isempty1()):
        push2(pop1())
    pop2()
    while(not isempty2()):
        push1(pop2())
    
def peak():
    global stack2
    while(not isempty1()):
        push2(pop1())
    w=stack2[top2]
    while(not isempty2()):
        push1(pop2())
    print(w)
    
n=int(input())
L=[]
for i in range(0,n):
    s=input()
    L.append(s)
for i in range(0,n):
    if(int(L[i][0])==1):
        pw=int(L[i][2:len(L[i])])
        enqueue(pw)
    else:
        if(int(L[i][0])==2):
            dequeue()
        else:
            peak()
    
