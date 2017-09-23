



x, y = [], []
x_test = []

line = str(input())
n_features, n_train = int(line.split()[0]), int(line.split()[1])

for i in range(0, n_train):
    current_sample = list(map(lambda v: float(v), str(input()).split()))

    x.append(current_sample[0:-1])
    y.append(float(current_sample[-1]))

n_test = int(str(input()))

for i in range(0, n_test):
    current_test = list(map(lambda v: float(v), str(input()).split()))
    x_test.append(current_test)

"""
def generate_polynomial_features(features):
    return [
            features[0],
            features[1],
            features[0]**2,
            features[1]**2,
            features[0] * features[1],
            features[0]**3,
            features[1]**3,
            (features[0]*features[1])**2,
            (features[0] * features[1])**3]
weight1, weight2 = 0.0, 0.0
bias = 1.0

epochs = 100000
learning_rate = 0.1

for epoch in range(0, epochs):
    bias_gradient = 0.0
    weight1_gradient = 0.0
    weight2_gradient = 0.0
    error_avg = 0.0

    for i in range(0, len(x)):
        y_predicted = x[i][0] * weight1 + x[i][1] * weight2 + bias
        y_actual = y[i]

        error_avg += y_predicted - y_actual

        bias_gradient += y_predicted - y_actual
        weight1_gradient += (y_predicted - y_actual) * x[i][0]
        weight2_gradient += (y_predicted - y_actual) * x[i][1]

    print(error_avg)

    weight1 -= (learning_rate * weight1_gradient) / len(x)
    weight2 -= (learning_rate * weight2_gradient) / len(x)
    bias -= (learning_rate * bias_gradient) / len(x)

    if round(error_avg, 2) == 0.3:
        break

for i in range(0, len(x_test)):
    print(round(x_test[i][0] * weight1 + x_test[i][1] * weight2 + bias, 2)) """

from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

to_polynomial = PolynomialFeatures(degree=3)
new_features = to_polynomial.fit_transform(x)
new_test_features = to_polynomial.fit_transform(x_test)
linear_regression = LinearRegression()
linear_regression.fit(new_features, y)

#print(new_features.shape)
#print(new_test_features.shape)

print(*linear_regression.predict(new_test_features), sep='\n')
