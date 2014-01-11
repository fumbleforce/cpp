# Oppgave 1a

def isFibonacciNumber(n):
	a = 0
	b = 1
	while b < n:
		temp = b
		b = a + b
		a = temp
	
	if b == n:
		return True
	return False


for i in xrange(100):
	print "Is %s a fib. number? %s" % (str(i), str(isFibonacciNumber(i)))
