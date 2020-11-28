# C++
# STATIC:
# TheClass::method(param);
# INSTANCE:
# TheInstance.method(param);
# POINTER:
# ThePointer->method(param);

# Python
class TheClass:
  __private = 'secret butts'
  @classmethod
  def the_class_method(self, x):
    print(f'{repr(self)}: {x}')
  @staticmethod
  def the_static_method(x):
    print(f'the_static_method: {x}')
  def the_method(self, x):
    print(42 + x)
TheInstance = TheClass()
TheInstance.the_method(93)
TheClass.the_method(TheInstance, 28)
lbsb = 'large boi so beeg'
TheClass.the_class_method(lbsb)
TheClass.the_static_method(lbsb)
TheInstance.the_class_method(lbsb)
TheInstance.the_static_method(lbsb)
print(TheClass._TheClass__private)
