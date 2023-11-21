class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        if(len(chars) == 1):
            if(chars[0].isalpha()):
                return 1
            else:
                return 0
        d = ""
        l = 1
        i = 0
        j = i
        while(j < len(chars)):
            if((ord(chars[j]) >= 35) and (ord(chars[j]) <= 126)):
                if(chars[j] != d):
                    d = chars[j]
                    if(l>1):
                        for di in str(l):
                            chars[i] = di
                            i+=1
                        l=1
                    chars[i] = chars[j]
                    i+=1
                else:
                    l+=1
            else:
                return 0
            j+=1
        if(l>1):
            chars[i:] = str(l)
        else:
            chars[:] = chars[:i]
        return len(chars)

        return len(l)
    def compress1(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        if(len(chars) == 1):
            if(chars[0].isalpha()):
                return 1
            else:
                return 0
        d = chars[0]
        l = 1
        i = 1
        j = i
        while(j < len(chars)):
            if((ord(chars[j]) >= 35) and (ord(chars[j]) <= 126)):
                #print(chars)
                if(chars[j] != d):
                    d = chars[j]
                    if(l>1):
                        if(l >9 ):
                            k=0
                            while(k < len(str(l))):
                                chars[i] = str(l)[k]
                                i+=1
                                k+=1
                            chars[i] = chars[j]
                            i+=1
                        else:
                            chars[i] = str(l)
                            chars[i+1] = chars[j]
                            i+=2
                        l=1
                        #continue
                    else:
                        chars[i] = chars[j]
                        i+=1
                        
                else:
                    l+=1
            else:
                return 0
            j+=1
        if(l>1):
            chars[i:] = str(l)
            #i+=1
        else:
            chars[:] = chars[:i]
        return len(chars)

ch = ["a","a","b","b","c","c","c"]
#ch = ["a","b","b","c","c","c"]
ch = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
#ch = ["a","a","b","b","c","c","c"]
#ch = ["a"]
#ch = ["a","a","a","b","b","a","a"]
#ch = [""]
#ch =["a","b"]
soln = Solution()
print(soln.compress(ch))
print(ch)