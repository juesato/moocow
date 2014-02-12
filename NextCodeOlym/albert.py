# read in 5 lines

orig = '''***   * *** *** * * *** *** *** *** ***
* *   *   *   * * * *   *     * * * * *
* *   * *** *** *** *** ***   * *** ***
* *   * *     *   *   * * *   * * *   *
***   * *** ***   * *** ***   * *** ***'''.split('\n')

def check(a, b):
  for i in range(len(a)):
    if a[i] != b[i]:
      return False

  return True

def get_num(n):
  ret = []
  for i in range(5):
    ret.append(orig[i][4*n:(4*n+3)])
  return ret

lines = []
for i in range(5):
  line = raw_input()
  lines.append(line)

# print lines

# *** ***   ***
#   *   *   * *
# *** *** + ***
# *     *   * *
# *** ***   ***

# lines = '''*** ***   * *
#   *   *   * *
# *** *** + ***
# *     *     *
# *** ***     *'''.split('\n')

def add_onto(building, d):
  thingy = get_num(d)

  for i in range(5): # for each line
    building[i] += ' ' + thingy[i]


# split the input into two numbers (by plus sign)
plus_pos = lines[2].find('+')
# parse the left side
left_side = []
right_side = []
for i in range(5):
  left_side.append(lines[i][0:(plus_pos-1)])
  right_side.append(lines[i][(plus_pos+2):])

# print left_side

# figure how many numbers
chars = len(left_side[0])
nums = (chars + 1) / 4

left_str = ''


for i in range(nums):
  # extraact
  temp = []
  for j in range(5):
    temp.append(left_side[j][4*i:(4*i+3)])
  done = False
  for j in range(10):
    if check(get_num(j), temp):
      # it's j
      left_str += str(j)
      break

  # print left_str

right_str = ''

for i in range(nums):
  # extract
  temp = []
  for j in range(5):
    temp.append(right_side[j][4*i:(4*i+3)])
  done = False
  for j in range(10):
    if check(get_num(j), temp):
      # it's j
      right_str += str(j)
      break

# add them together
run_sum_str = str(int(left_str) + int(right_str))


building = ['', '', '', '', '']

for d in run_sum_str:
  add_onto(building, int(d))

# print it out
# for line in building:
  # print line

newthing = []
for line in building:
  newthing.append(line[1:])

for line in newthing:
  print line