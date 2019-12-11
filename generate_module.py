import sys
import json

args = sys.argv
fname = args[1]
#-------------------ReadJSON------------------------
a = open(fname)
b = json.load(a)
N = b["size"]
net = b["network"]
#---------------------------------------------------


#----module declear---------
print("module sort_pipe(")
print("     input clk,")
print("     input  [7:0] ", end="")

for i in range(N):
    print("x_%s, " %i ,end="")
print("")

print("     output [7:0] median")
print(");")

#------------------------------

for i in range(0,len(net)):
    print("reg[7:0] r%s [%s:0];" %(i,N-1))

print("")


cmp_cnt = 0
for i in range(0,len(net)):
    print("//-------declaration layer:%s----------" %i)
    for j in range(0,len(net[i])):
        print("wire [7:0] cmp%s_out0;" %cmp_cnt)
        print("wire [7:0] cmp%s_out1;" %cmp_cnt)
        print("reg [7:0] cmp%s_in0;" %cmp_cnt)
        print("reg [7:0] cmp%s_in1;" %cmp_cnt)
        cmp_cnt = cmp_cnt + 1
        print("")
    
#--------------------------Temp Register----------------------------------
print("//-------Temp Register----------")
USED = [0] * N

for i in range(0,len(net)):
    USED = [0] * N
    for j in range(0,len(net[i])):
        for k in range(2):
            USED[net[i][j][k]] = 1

    
    for l in range(N):
        if(USED[l] == 0):
            print("reg [7:0] r%s_%s_tmp;" %(i,l))

print("//-----------------------------")
print("")
#------------------------------------------------------------


cmp_cnt = 0
print("always @(posedge clk)begin")

#-----------Input layer----------------------------
print("//--------INPUT LAYER-------------")

for i in range(0,len(net[0])): 
    print("cmp%s_in0 <= x_%s;" %(cmp_cnt,net[0][i][0]))
    print("cmp%s_in1 <= x_%s;" %(cmp_cnt,net[0][i][1]))
    print("r0[%s] <= cmp%s_out0;" %(net[0][i][0],cmp_cnt))
    print("r0[%s] <= cmp%s_out1;" %(net[0][i][1],cmp_cnt))

    print("")
    cmp_cnt = cmp_cnt + 1

USED = [0] * N
for j in range(0,len(net[0])):
        for k in range(2):
            USED[net[0][j][k]] = 1
for l in range(N):
    if(USED[l] == 0):
        print("r0_%s_tmp <= x_%s;" %(l,l))
        print("r0[%s] <= r0_%s_tmp ;" %(l,l))

print("//--------------------------")
print("")

#--------------------------------------------------


for l in range(1,len(net)):
    print("//---------layer : %s------------" %l)
    #-----------layer----------------------------
    for i in range(0,len(net[l])): 
        print("cmp%s_in0 <= r%s[%s];" %(cmp_cnt,l-1,net[l][i][0]))
        print("cmp%s_in1 <= r%s[%s];" %(cmp_cnt,l-1,net[l][i][1]))
        print("r%s[%s] <= cmp%s_out0;" %(l,net[l][i][0],cmp_cnt))
        print("r%s[%s] <= cmp%s_out1;" %(l,net[l][i][1],cmp_cnt))
        print("")
        cmp_cnt = cmp_cnt + 1

    USED = [0] * N
    for j in range(0,len(net[l])):
            for k in range(2):
                USED[net[l][j][k]] = 1
    for k in range(N):
        if(USED[k] == 0):
            print("r%s_%s_tmp <= r%s[%s];" %(l,k,l-1,k))
            print("r%s[%s] <= r%s_%s_tmp;" %(l,k,l,k))
            print("")
    print("//--------------------------")

print("end")

#-------------------Comparator module connect-------------------------------
print("//-------------------Comparator module connect-------------------------------")
cmp_cnt = 0
for i in range(0,len(net)):
    for j in range(0,len(net[i])):
        print("cmp cmp%s (.in0(cmp%s_in0), .in1(cmp%s_in1), .out0(cmp%s_out0), .out1(cmp%s_out1));" %(cmp_cnt,cmp_cnt,cmp_cnt,cmp_cnt,cmp_cnt))
        cmp_cnt = cmp_cnt + 1
print("assign median = cmp%s_out1;" %(cmp_cnt-1))

print("endmodule")

print("")
#comparator
print("//--------------comparator----------------")
print("module cmp(")
print("     input  [7:0] in0,")
print("     input  [7:0] in1,")
print("     output wire [7:0] out0,")
print("     output wire [7:0] out1")
print(");")
print("     assign out0 = (in0<in1) ? in0:in1;")
print("     assign out1 = (in0<in1) ? in1:in0;")
print("endmodule")
