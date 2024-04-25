def Gcolour(vert, edg, c, maxv, colour):
    if vert > maxv:
        return True

    for i in range(1, c + 1):
        print(vert,i,colour)
        flagV = True
        for j in edg:
            if j[0] == vert:
                if colour[j[1]] == i:
                    flagV = False
                    break
        if flagV:
            colour[vert] = i
            if Gcolour(vert + 1, edg, c, maxv, colour):
                return True
            colour[vert] = 0

    return False


E = []
print("Enter the number of vertices")
vert = int(input())
colour = [0] * (vert+1)
print("Enter the total number of edges")
edg = int(input())
c = int(input("Enter the number of colours"))
print("Enter the edges as '1,2' representing 1 to 2")
for i in range(0,edg):
    s = input()
    L = s.split(',')
    t = (int(L[0]), int(L[1]))
    E.append(t)

print(E)
Gcolour(0, E, c, vert, colour)
print(colour)

"""
Enter the number of vertices
3
Enter the total number of edges
10
Enter the number of colours3
Enter the edges as '1,2' representing 1 to 2
1,3
3,1
2,1
1,2
0,2
2,0
0,3
3,0
1,0
0,1
"""