class Solution:
     def findJudge(self, N, trust):
        count = [0] * (N + 1)
        for i, j in trust:
            print(i,j)
            count[i] -= 1
            count[j] += 1
        print(count)
        # for i in range(1, N + 1):
        #     if count[i] == N - 1:
        #         return i
        # return -1

if __name__ == "__main__":
    num = 2
    trust = [[1,2]]
    soln=Solution()
    soln.findJudge(num, trust)