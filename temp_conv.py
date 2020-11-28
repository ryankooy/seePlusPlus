class Temperature:
	@staticmethod
	def c_to_f(c):
		return c * 9/5 + 32
		
	@staticmethod
	def f_to_c(f):
		return (f - 32) * 5/9
		
	def __init__(self, celsius):
		self.celsius = celsius
		
	@property
	def celsius(self):
		return self._celsius
		
	@celsius.setter
	def celsius(self, value):
		self._celsius = value
		
	@property
	def fahrenheit(self):
		return Temperature.c_to_f(self.celsius)
		
	@fahrenheit.setter
	def fahrenheit(self, value):
		self.celsius = Temperature.f_to_c(value)
		
	def print_results(self):
		print('\n--------------------------')
		print(f'C°: {self.celsius}\nF°: {self.fahrenheit}')
		print('--------------------------')
		
if __name__ == '__main__':
	while True:
		text = input('\nEnter a temperature followed by [C] for Celsius or [F] for Fahrenheit.\nEnter [X] to exit:\n')
		if text.isnumeric():
			temp = int(text.strip())
			t = Temperature(temp)
			t.print_results()
		elif text.isalpha():
			if text.lower() == 'x':
				print('Bye.')
				exit()
			else:
				continue
		else:
			temp = int(''.join([i for i in text if i.isdigit()]))
			f_or_c = ''.join([i for i in text if i.isalpha()]).strip()
			fc = f_or_c.lower()
			t = Temperature(temp)
			if fc == 'c':
				t.print_results()
			elif fc == 'f':
				t.fahrenheit = temp
				t.print_results()
			else:
				continue
