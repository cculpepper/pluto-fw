#!/usr/bin/env python3

n = 100
print("const char svc_itoa_tab [%d][2] = {"%n)
for i in range(n) :
	print('"%02d",'%i)
print("};")
