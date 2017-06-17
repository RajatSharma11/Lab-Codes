# Python 3.6
# Board Size 4 X 4
t = int(input())
def isWord(s,a):
    #print(s,end = "  ")
    if(s in a):
        return True
    else:
        return False

def findWordUtil(l,string,i,j,a):
    visited[i][j] = True
    #print(visited)
    string += l[i][j]
    #print(string)
    if(isWord(string,a)):
        #print(string)
        if(string not in ans):
            ans.append(string)
    row = i - 1
    while (row <= i + 1 and row < 4):
        col = j - 1
        while (col <= j + 1 and col < 4):
            if(row >= 0 and col >= 0 and not(visited[row][col])):
                findWordUtil(l,string,row,col,a)
            col+=1
        row+=1
    string = string[:len(string) - 1]
    visited[i][j] = False


def findWord(l,a):
    for i in range(4):
        visited.append([False,False,False,False])
    string = ""
    for i in range(4):
        for j in range(4):
            findWordUtil(l,string,i,j,a)
while t > 0:
    l = []
    ans = []
    visited = []
    a = list(input().upper().split())
    a = a[1:]
    for i in range(4):
        b = list(input().split())
        l.append(b[:])
    #print(l[0][2])
    #print(a)
    findWord(l,a)
    ans.sort()
    for i in range (len(ans)):
        print(ans[i].lower(),end = " ")
    print()
    t-=1
    
############################################################################################################################################
# Sample Input
# 1
# 5 int num float string double
# D O U B
# A N M L
# T O E F
# I N L G

# Sample output
# double float int num
