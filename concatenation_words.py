
class Solution:
    def populate_table(self, table, words):
        # first populate all the words in table
        counter = 0
        total_len = 0
        if(len(words)):
            for word in words :
                if(word not in table):
                    counter+=1
                table[word] = 0
            for word in words :
                total_len+=len(word)
                table[word]+= 1
            return counter, total_len
        return None, None

    def findSubstring(self, s: str, p: list):
        beg = 0
        end = 0
        indices = []
        table = {}
        counter, total_len = self.populate_table(table, p)
        print(table)
        print(counter, total_len)
        if( counter is None):
            return []
        word_len = len(p[0])
        while( end < len(s)):
            if( s[end:(end+word_len)] in p ):
                table[s[end:(end+word_len)]] -=1
                if( table[s[end:(end+word_len)]] ) == 0:
                    counter -=1
                end += word_len
            else:
                end+=1
            print(table, counter)
            while( counter == 0 ):
                if((end - beg) == ( total_len)):
                    indices.append(beg)
                if( s[beg:(beg+word_len)] in p ):
                    table[s[beg:(beg+word_len)]] +=1
                    if( table[s[beg:(beg+word_len)]]  > 0):
                        counter +=1
                    beg +=word_len
                else:
                    beg+=1
                print(table)
        return indices


# Test Cases
message = "barfoothefoobarman"
words = ["bar", "foo"]
#expected output = [0,9]
message = "barbarfoothefoobarman"
words = ["bar", "foo"]
#expected output = [3,12]

message = "wordgoodgoodgoodbestword",
words = ["word","good","best","word"]
#expected Output: []

message = "wordgoodgoodgoodbestword"
words = ["word","good","best","good"]
#expected Output: [8]

message = "lingmindraboofooowingdingbarrwingmonkeypoundcake"
words = ["fooo","barr","wing","ding","wing"]
#expected Output: [13]

message = "aaaaaaaa"
words = ["aa","aa","aa"]
soln = Solution()
print(soln.findSubstring(message, words))