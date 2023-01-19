import matplotlib.pyplot as p
f=open("time.txt","r")
p1=float(f.readline()) #reading lines one by one
p2=float(f.readline())
p3=float(f.readline())
p4=float(f.readline())

time_ref={'Without priority':p1, "With Priority 1":p2, "With Priority 2":p3, "With Priority 3":p4}

a=list(time_ref.keys())
b=list(time_ref.values())

figure=p.figure(figsize=(9,6))

p.bar(a,b, color="blue", width=0.3)

p.xlabel("PRIORITIES ARE HERE")
p.ylabel("TIME TAKEN FOR SCHEDULING")
p.title("For Thread A")
p.show()


#For Thread B
de=float(f.readline())
p1=float(f.readline())
p2=float(f.readline())
p3=float(f.readline())

data={'default':de, "priority1":p1, "priority2":p2, "priority3":p3}

x=list(data.keys())
y=list(data.values())

fig=p.figure(figsize=(9,6))

p.bar(a,b,color="blue",width=0.3)

p.xlabel("PRIORITIES ARE HERE")
p.ylabel("TIME TAKEN FOR SCHEDULING")
p.title("For Thread B")
p.show()

#For thread C
de=float(f.readline())
p1=float(f.readline())
p2=float(f.readline())
p3=float(f.readline())

data={'default':de, "priority1":p1, "priority2":p2, "priority3":p3}

x=list(data.keys())
y=list(data.values())

fig=p.figure(figsize=(9,6))

p.bar(x, y, color="blue", width=0.3)

p.xlabel("PRIORITIES ARE HERE")
p.ylabel("TIME TAKEN FOR SCHEDULING")
p.title("For Thread C")
p.show()