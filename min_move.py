#https://leetcode.com/discuss/interview-question/398023/Microsoft-Online-Assessment-Questions
def min_move1(s):
    temp =list(s)
    i=0
    count = 0
    while(i<len(s)):
        if(s[i:i+5] == "aaaaa"):
            temp[i+2] = "b"
            i+=2
            count+=1
        elif(s[i:i+4] == "aaaa"):
            temp[i+2] = "b"
            i+=2
            count+=1
        elif(s[i:i+3] == "aaa"):
            temp[i+1] = "b"
            i+=1
            count+=1
        if(s[i:i+5] == "bbbbb"):
            temp[i+2] = "a"
            i+=2
            count+=1
        elif(s[i:i+4] == "bbbb"):
            temp[i+2] = "a"
            i+=2
            count+=1
        elif(s[i:i+3] == "bbb"):
            temp[i+1] = "a"
            i+=1
            count+=1
        else:
            i+=1
    return count


# 3 consecutive occurences of a character need to be removed
# if it is 4 we can replace 3 with 4
def min_move(s, o):
    i = 0
    steps = 0

    while(i < len(s)):
        j = 0
        ch = s[i]
        while((i < len(s)) and (ch == s[i])):
            i+=1
            j+=1
        if(j/o != 0):
            steps+= j/o
    return int(steps)

s="ccccccccccccccccccccc"
print(min_move(s,3))    # remove 3 cosnecutive occurences
print(min_move(s,4))    # remove 3 cosnecutive occurences

while(1):
    input_string = str(input().strip())
    print(input_string)
    if input_string[0]=='0':
        break
    else:
        print("func")
