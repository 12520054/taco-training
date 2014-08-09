#Ex_1
#using for loop
print "Ex_1 using for loop:"
for i in range(0,1001): #for chay tu 0 den 1000
    if i % 3 == 0: # dieu kien
        print i, #in ra i thoa man dk
print '\nEx_1 using while loop:'
#using while loop
i = 0
while i < 1001: #Tuong tu cach tren
    if i % 3 == 0:
        print i,
    i += 1
print '\nEx_2 using for loop'
#Ex2
#using for loop
for i in range(1001,-1,-1): #chay nguoc lai theo -1 don vi
    if i % 3 == 0:
        print i,
print '\nEx_2 using while loop: '
#using while loop
i = 1000
while i >= 0:
    if i % 3 == 0:
        print i,
    i -= 1
#Ex3
print '\n'
#fibo loop
def Fibo(z):
    if z < 1:
        return 0
    List = [0,1,1]
    for index in range(3,int(z + 1)):
        List.append(List[index - 1] + List[index - 2])
    return List[z] 
#Ex4 other way
def Fibonacci(z):
    if z < 1:
        return 0
    if z == 1:
        return 1
    if z == 2:
        return 1
    return (Fibonacci(z - 1) + Fibonacci(z - 2))
print "Find the Fibo(10) by 2 way:", Fibo(10), Fibonacci(10) 
#Ex5
def isPalindrome(s):
    i = len(s)/2
    j = len(s)
    print i,j
    if j % 2 == 1:
        print s[0:i:1], s[-1:i - j:-1]
        if s[0:i + 1:1] == s[-1:i - j - 1:-1]:
            return 1
        return 0
    print s[0: i:1], s[-1: i - j - 1:-1]
    if s[0: i: 1] == s[-1: i - j - 1:-1]:
        return 1
    return 0
if isPalindrome("TranDanhxhnaDnarT") == 1:
    print True
else:
    print False
#Ex6
def countNumChar(s):
    return len(set(s))
print countNumChar("TranDanhHuu")
#Ex7
def isEndString(sourceStr, subStr):
    i = len(subStr)
    j = len(sourceStr)
    if sourceStr[j - i::1] == subStr:
        return True
    return False
print isEndString("TranDanh", "Danh")
#Ex8
def countStdio(sourceStr):
    i = len("stdio")
    j = len(sourceStr)
    count = 0
    for k in range(j):
        if sourceStr[k:i+k:1] == "stdio":
            count += 1
    return count
print countStdio("std.io.stdio.stdio.stdio.stdio....")
    
    
    
    
    