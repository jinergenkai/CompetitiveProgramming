import sys
import os
from os.path import exists
import random


if exists("input.txt"):
	sys.stdout = open("input.txt", "w")

print(random.randint(1, 9))

# sys.stdout = o


os.startfile(r"D:\CompetitiveProgramming\Cplusplus\test.exe")

# with open('some_file_1.txt', 'r') as file1:
#     with open('some_file_2.txt', 'r') as file2:
#         same = set(file1).intersection(file2)

# same.discard('\n')

# with open('some_output_file.txt', 'w') as file_out:
#     for line in same:
#         file_out.write(line)