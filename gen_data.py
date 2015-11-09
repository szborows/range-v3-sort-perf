#!/usr/bin/env python

import random

s = 5000
numbers = [random.randrange(0, s) for x in xrange(s)]
nss = '{' +  ','.join(map(str, numbers)) + '}'

def gen(filename, varname):
    with open(filename, 'w') as fp:
        fp.write('#include <vector>\n')
        fp.write('using namespace std;\n')
        fp.write('vector<vector<int>> ' + varname + ' {\n')
        for i in range(1000):
            fp.write(nss + ',')
        fp.write('};\n')

gen('data1.cpp', 'd1')
gen('data2.cpp', 'd2')
