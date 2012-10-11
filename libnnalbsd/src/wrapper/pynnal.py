# PyNNs
import nnal

class MlpNetwork():
	network = None
	layers = None
	
	def __init__(self, ls):
		# Create the network
		self.network = nnal.mlp_new(ls, len(ls))
		self.layers = ls
		
	def setLearningRate(self, value):
		# Set the learning rate
		nnal.mlp_set_learning_rate(nnal, value)
		pass

	def getLearningRate(self):
		# Get the learning rate
		pass
		
	def Exec(self, inputs):
		# Exec the network
		pass
		
	def backPropagate(self, inputs, output):
		# Exec the backpropagation
		pass

	def Save(self, filename):
		# Save in a file
		pass

	def Reset(self):
		# Reset the network
		network = nnal.mlp_new(self.layers, len(self.layers))
		
		
def loadMlpNetwork(file):
	# Create a network loading it from a file
	pass




if __name__ == "__main__":
	patterns_and = [ [[1.0, 1.0], [1.0]], [[0.0, 1.0], [0.0]], [[1.0, 0.0], [0.0]], [[0.0, 0.0], [1.0]]] 
	net = MlpNetwork([2, 3, 2])
	
	patterns = patterns_and
	
	# Teach the and function
	for i in xrange(1000):
		for x in patterns:
			print "epoch "+str(i)+"\tdelta value: ", net.backPropagate(x[0], x[1])

	# Test the network
	test = [1.0, 1.0]
	print "test: "+str(test)+" -> "+str(net.Exec(test))
	
