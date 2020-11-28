import math

class Square:
  def __init__(self, side):
    self.side = float(side)

  ### AREA ###
  @property
  def area(self):
    return self._get_area()

  @area.setter
  def area(self, area):
    return self._set_area(area)

  def _get_area(self):
    return round(self.side ** 2, 6)

  def _set_area(self, area):
    self.side = round(math.sqrt(area), 6)

  ### PERIMETER ###
  @property
  def perimeter(self):
    return self._get_perimeter()

  @perimeter.setter
  def perimeter(self, perimeter):
    return self._set_perimeter(perimeter)

  def _get_perimeter(self):
    return round(self.side * 4, 6)

  def _set_perimeter(self, perimeter):
    self.side = round(perimeter / 4, 6)

  ### PRINT THE STATS ###
  def _print_deets(self):
    print()
    print(f'area of {self.area}')
    print(f'perimeter of {self.perimeter}')
    print(f'side length of {self.side}')

# sq = Square(3)
# sq._print_deets()
# sq.area = 200
# sq._print_deets()
# sq.perimeter = 50
# sq._print_deets()
# sq.side = 28
# sq._print_deets()