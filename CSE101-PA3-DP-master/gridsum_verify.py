# GridSum test case verifier for PA 3
# DO NOT MODIFY BELOW
import random
import sys
import argparse

def mat_ver(conf):
   filename = conf['file']
   [xmin, ymin, xmax, ymax] = [int(val) for val in conf['bounds'].split(',')]

   size = 0
   mat = []
   with open(filename, 'rb') as ifile:
      for line in ifile:
         if size == 0:
            size = int(line.rstrip())
         elif len(mat) == size:
            break
         else:
            mat.append([int(val) for val in line.rstrip().split(' ')])

   sum = 0
   for x in range(xmin, xmax + 1):
      for y in range(ymin, ymax + 1):
         sum += mat[x][y]

   print("Sum from (" + str(xmin)  + ", " + str(ymin) + ") to (" + str(xmax) + ", " + str(ymax) + ") is " + str(sum))

if __name__ == '__main__':
   parser = argparse.ArgumentParser()
   parser.add_argument('-f', action='store', dest='file', type=str,
         help='the matrix file', required=True)
   parser.add_argument('-x', action='store', dest='bounds', type=str,
         help='the bounds to compute the sum for, in the format "xmin,ymin,xmax,ymax" with no spaces', required=True)
   args = vars(parser.parse_args())
   mat_ver(args)

