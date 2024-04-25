
def SubsetSum(L,arr,n,ans,i):
    if i>n and L[0] != 30:
        return False
    if i>n and L[0] == 30:
        return True      
    if L[0]>30:
        return False
    if L[0]==30:
        return True
    for j in range(0,2):
        if j ==0:
            ans[i]=0
            L[1]=L[1]-arr[i]
            if SubsetSum(L,arr,n,ans,i+1) == True:
                return True
            else:
                L[1]=L[1]+arr[i]
                continue
        else:
            ans[i]=1
            L[0]=L[0]+arr[i]
            L[1]=L[1]-arr[i]
            if SubsetSum(L,arr,n,ans,i+1) == True:
                return True
            else:
                ans[i]=0
                L[0]=L[0]-arr[i]
                L[1]=L[1]+arr[i]
                continue
    return False
    
L=[]
arr=[5,10,12,13,15,18]
ans=[0,0,0,0,0,0]
sum=0
for i in arr:
    sum = sum+i
L.append(0)
L.append(sum)
SubsetSum(L,arr,5,ans,0)
print(ans)