class Solution:
    def rotate2(self, matrix):
        #return list
        matrix[:] = map(list,(zip(*matrix[::-1])))
    def rotate1(self, matrix):
        #retunr tuple
        matrix[:] = (zip(*matrix[::-1]))
    def rotate0(self, matrix):
        matrix[:] = matrix[::-1]

        i = 0
        j = 0
        while(i < len(matrix)):
            j = i + 1
            while(j < len(matrix)):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
                j+=1
            i+=1
    def rotate1(self, matrix):
        matrix[:] = matrix[::-1]

        i = 0
        j = 0
        for i in range(len(matrix)):
            for j in range(i):
                c = matrix[j][i] ^ matrix[i][j]
                matrix[j][i] = c ^ matrix[j][i]
                matrix[i][j] = c ^ matrix[i][j]
                j+=1
            i+=1
    def rotate(self, A):
        n = len(A)
        for i in range(n):
            for j in range(i):
                A[i][j], A[j][i] = A[j][i], A[i][j]
 

matrix = [[1,2,3], [4,5,6],[7,8,9]]

soln = Solution()
soln.rotate(matrix)
print(matrix)