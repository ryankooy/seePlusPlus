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
		print('\n|------------------|')
		print('|      %.1f°C\n|      %.1f°F' % (self.celsius, self.fahrenheit))
		print('|------------------|')
		
if __name__ == '__main__':
	while True:
		prompt = '\nEnter a temperature followed by [C] for Celsius or [F] for Fahrenheit.\nEnter [X] to exit:\n'
		ans = input(prompt).strip()
		if ans.isnumeric():
			temp = int(ans)
			t = Temperature(temp)
			t.print_results()
		elif ans.isalpha():
			if ans.lower() == 'x':
				print('Bye.')
				exit()
			else:
				continue
		else:
			try:
				temp = int(''.join([i for i in ans if i.isdigit()]))
			except:
				continue
			f_or_c = ''.join([i for i in ans if i.isalpha()])
			fc = f_or_c.lower()
			t = Temperature(temp)
			if fc == 'c':
				t.print_results()
			elif fc == 'f':
				t.fahrenheit = temp
				t.print_results()
			else:
				continue
