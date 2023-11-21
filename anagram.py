
class Solution:
    def populate_table(self, table, pattern):
        # first populate all the unique characters in table
        #update the counter with the len of unique characters in pattern
        counter = len("".join(set(pattern)))
        for c in "".join(set(pattern)):
            table[c] = 0
        # Now update all the characters appearance in the tables
        for c in pattern:
            table[c] += 1
        return counter

    def findAnagrams(self, s: str, p: str):
        beg = 0
        end = 0
        indices = []
        table = {}
        counter = self.populate_table(table, p)
        while( end < len(s)):
            if( s[end] in p ):
                table[s[end]] -=1
                if( table[s[end]] ) == 0:
                    counter -=1
            end +=1

            while( counter == 0 ):
                if((end - beg) == len(p)):
                    indices.append(beg)
                if( s[beg] in p ):
                    table[s[beg]] +=1
                    if( table[s[beg]]  > 0):
                        counter +=1
                beg +=1
        return indices


# Test Cases

# message = "baa"
# pattern = "aa"




message = "cbaebabacd"
pattern = "abc"

message = "abcaab"
pattern = "ab"
#output [0,4]

message ="abacbabc"
pattern = "abc"
#output [1,2,3,5]

soln = Solution()
print(soln.findAnagrams(message, pattern))