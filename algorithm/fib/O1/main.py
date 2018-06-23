import math
n = int(input())
tmp1 = math.pow(((1+math.sqrt(5)) / 2), n);
tmp2 = math.pow(((1-math.sqrt(5)) / 2), n);
print(int((tmp1 - tmp2) / math.sqrt(5))) 
