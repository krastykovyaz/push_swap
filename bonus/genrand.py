import random
integers=[]
for i in range(202):
      r=random.randint(-10000,10000)
      if r not in integers: integers.append(r)
strings = [str(integer) for integer in integers]
a_string = " ".join(strings)
# an_integer = int(a_string)

print(a_string)