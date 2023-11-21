
#Microsoft | OA 2019 | Longest Substring Without 3 Contiguous Occurrences of Letter
def longestSub2(s):
    sub = ""
    start = i = 0
    l = len(s)
    while(i+1 < l):
        count = 0
        while((i+1 < l) and (s[i] == s[i+1]) and (count<2)):
            count+=1
            i+=1
        if(count<=1):
            i+=1
            continue
        else:
            if (len(sub) < len(s[start:i])):
                sub = s[start:i]
            #print("i,sub",i,sub)
            start = i
    if (len(sub) < len(s[start:])):
            sub = s[start:]
    return sub

print("1")
S = "aabbaaaaabb"
print(longestSub2(S))

print("2")
S = "aabbaabbaabbaa"
print(longestSub2(S))

print("3")
S = "abbaabbaaabbaaa"
print(longestSub2(S))