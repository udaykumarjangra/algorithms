import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets, linear_model
from sklearn.metrics import mean_squared_error

diabetes = datasets.load_diabetes()

# (['data', 'target', 'frame', 'DESCR', 'feature_names', 'data_filename', 'target_filename'])

# print(diabetes.keys())
# print(diabetes.data)
# print(diabetes.DESCR)

diabetes_x = diabetes.data # [:, np.newaxis, 2] # for plotting line

diabetes_x_train = diabetes_x[:-30] # slicing from data
diabetes_x_test = diabetes_x[-20:]

diabetes_y_train = diabetes.target[:-30] # slicing from data
diabetes_y_test = diabetes.target[-20:]

model = linear_model.LinearRegression() # using regression model

model.fit(diabetes_x_train, diabetes_y_train)

diabetes_y_predict = model.predict(diabetes_x_test)

print("Mean squared error is : ", mean_squared_error(diabetes_y_test, diabetes_y_predict))

print("Weights: ", model.coef_)
print("Intercept: ", model.intercept_)

# for plotting a line

# plt.scatter(diabetes_x_test, diabetes_y_test)
# plt.plot(diabetes_x_test, diabetes_y_predict)
#
# plt.show()

# Mean squared error is :  2561.3204277283867
# Weights:  [941.43097333]
# Intercept:  153.39713623331698
