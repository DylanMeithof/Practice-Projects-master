import Materials
i = 0
Materials.mats()
Scale = input("Enter Scale in the Following Form 'x|y|z' 'z' represents height: ")
xyz = Scale.split("|")

print([xyz[0]])
while i <  int(xyz[0]):
    line = input()
    i = i + 1
    print(i)