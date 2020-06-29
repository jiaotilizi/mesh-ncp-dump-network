import json
import sys

fh = open(sys.argv[1],'r')
s = fh.read()
fh.close()

p = json.loads(s)
print("python: ",p)

netkeys = p['netKeys']
devkeys = p['devKeys']
print(netkeys)
print(devkeys)

ostr = ''
for key in devkeys :
    ostr += " add node %s %s %s 2"%(key['uuid'],key['value'],key['primaryAddress'])
print(ostr)
