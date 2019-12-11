import sys
import math
args = sys.argv

N = int(args[1])

print("/* Register Definition*/")
for i in range(0,N):
    print("reg [7:0] x_%s;" %i)
print("\n")


print("/* Kernel input*/")
for i in range(0,N):
    print("x_%s <= i[%s][%s];" %(i,int(i/ int(math.sqrt(N)) ),i% int(math.sqrt(N))))
print("\n")

print("/* Call module*/")

print("sort_pipe s (.clk(clk),",end="")
for i in range(0,N):
    print(" .x_%s(x_%s)," %(i,i),end="")
print(" .median(median));")
