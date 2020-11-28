class Kooy:
  __private = 321
  non_private = __private * 2

mine = Kooy()
print(mine.non_private)
# print(mine.__private)
print(mine._Kooy__private)
