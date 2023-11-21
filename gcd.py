class Solution(object):
    def gcdOfStrings1(self, s1, s2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        i = 0
        strP=""
        if(len(s1) >len(s2)):
            N = len(s2)
        else:
            N = len(s1)
        while(i< N):
            if(s1[i] in s2):
                    strP+=(s1[i])
            i+=1
        i=0
        L = len(strP)
        print(strP)
        while(i+L<N):
            if(strP != s2[i:i+L]):
                strP=""
            i+=L
                
        return strP
    def gcdOfStrings(self, str1, str2):
        while not (str1 == "" or str2 == ""):
            if len(str1) == len(str2):
                return str1 if str1 == str2 else ""
            if len(str1) < len(str2):
                print("switching",str1, str2)
                str1, str2 = str2, str1
            if str2 in str1:
                print("replacing",str1, str2)
                str1 = str1.replace(str2, "")
                print("after replacing",str1, str2)

            else:
                print("can't replace",str1, str2)
                return ""
        return str2


s1 = "leet"
s2 = "code"
s1 = "TAUXXTAUXXTAUXXTAUXXTAUXX"
s2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"
s1 = "ababababababab"
s2 = "ababab"

soln = Solution()
def gcd(a, b):
    if a == 0 :
        return b
    return gcd(b%a, a)
print(gcd(36,60))
print(soln.gcdOfStrings(s1,s2))