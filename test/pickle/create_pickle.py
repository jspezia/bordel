import pickle

class Demo:
	def __init__(self):
		self.a = 6
		self.l = ('hello','world')
#		print(self.a,self.l)

if __name__ == "__main__":
	f=Demo()
	pickle.dump(f, file('Demo.pickle','w'))
