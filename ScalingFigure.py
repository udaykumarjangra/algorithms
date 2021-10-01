import matplotlib.pyplot as plt

ax = plt.axes()
ax.set_facecolor('white') 

print()

print("Enter coordinates of x1 and y1: ")
x1 = int(input("Enter x1: "))
y1 = int(input("Enter y1: "))

print()

print("Enter coordinates of x2 and y2: ")
x2 = int(input("Enter x2: "))
y2 = int(input("Enter y2: "))

print()

print("Enter coordinates of x3 and y3: ")
x3 = int(input("Enter x3: "))
y3 = int(input("Enter y3: "))

print()

print("Enter coordinates of x4 and y4: ")
x4 = int(input("Enter x4: "))
y4 = int(input("Enter y4: "))

print()

x = [x1, x2, x3, x4, x1]
y = [y1, y2, y3, y4, y1]

plt.plot(x,y,color = '#1495FF', label = "Original")                               

sx = float(input("Enter the Scaling Factor of x-axis, sx: "))
sy = float(input("Enter the Scaling Factor of y-axis, sy: "))

x = int(sx * (x2 - x1) + 0.5)
y = int(sy * (y2 - y1) + 0.5)

x1_ = x1
y1_ = y1

x3_ = x3 + sx * (x3-x1) + 0.5
y3_ = y3 + sy * (y3-y1) + 0.5

if(y2>y4):
    x2_ = x2
    y2_ = y2 + sy * (y2-y1) + 0.5

    x4_ = x4 + sx * (x4-x1)
    y4_ = y4
else:
    x2_ = x2 + sx * (x2-x1) + 0.5
    y2_ = y2

    x4_ = x4
    y4_ = y4 + sy * (y4-y1)

x_ = [x1_, x2_, x3_,x4_, x1_]
y_ = [y1_, y2_, y3_,y4_, y1_]

plt.plot(x_,y_,color = '#FF552F', label = "Rotated")

plt.legend(loc = 'upper right')

plt.show()
