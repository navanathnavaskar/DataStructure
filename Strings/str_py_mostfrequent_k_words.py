from collections import Counter

output = []
def reemovNestings(l):
        for i in l:
                if type(i) == list:
                        reemovNestings(i)
                else:
                        output.append(i)


list1 = []
with open("file.txt", "r") as f:
        for line in f:
                striplines = line.strip()
                listLines = striplines.split()
                list1.append(listLines)

reemovNestings(list1)
print(output)
counter = Counter(output)

freqOcc = counter.most_common(3)

print(freqOcc)