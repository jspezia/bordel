import sys

if len(sys.argv) < 2:
	sys.exit('Usage: %s database-name' % sys.argv[0])
else:
	print sys.argv[1]
