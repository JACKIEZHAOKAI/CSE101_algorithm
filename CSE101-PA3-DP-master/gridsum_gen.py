# GridSum test case generator for PA 3
# DO NOT MODIFY BELOW
import random
import sys
import argparse

def mat_gen(conf):
   N = conf['num']
   Q = conf['queries']
   filename = 'grid/GRID_{0}_{1}'.format(N, Q)

   output_file = open(filename, 'w')

   output_file.write(str(N) + '\n')

   for i in range(N):
       for j in range(N - 1):
           output_file.write('{0} '.format(str(random.randint(1, 50))))
       output_file.write('{0}\n'.format(str(random.randint(1, 50))))

   for q in range(Q):
       xcoors = [random.randint(0,N-1), random.randint(0,N-1)]
       ycoors = [random.randint(0,N-1), random.randint(0,N-1)]
       xcoors.sort()
       ycoors.sort()
       output_file.write('{0} {1} {2} {3}\n'.format(xcoors[0], ycoors[0], xcoors[1], ycoors[1]))

   output_file.close()

if __name__ == '__main__':
   parser = argparse.ArgumentParser()
   parser.add_argument('-n', action='store', dest='num', type=int,
         help='the number of rows/cols in the matrix', required=True)
   parser.add_argument('-q', action='store', dest='queries', type=int,
         help='the number of queries to make', required=True)
   args = vars(parser.parse_args())
   if args["num"] <= 0.0:
      print("Number of rows/cols must be positive")
   if args["queries"] <= 0:
      print("Number of queries must be positive.")
   mat_gen(args)
