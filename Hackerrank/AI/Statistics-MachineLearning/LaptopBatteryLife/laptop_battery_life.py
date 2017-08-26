___author__ = 'Ahmed Hani Ibrahim'

x, y = [], []

with open('training_data.txt', 'r') as reader:
    for line in reader:
        line_tokens = line.strip().split(',')

        x.append(float(line_tokens[0]))
        y.append(float(line_tokens[1]))

weight1 = 0.0
bias = 1.0

#offline learning

epochs = 100000
learning_rate = 0.01

for epoch in range(0, epochs):
    bias_gradient = 0.0
    weight1_gradient = 0.0
    error_avg = 0.0

    for i in range(0, len(x)):
        y_predicted = x[i] * weight1 + bias
        y_actual = y[i]

        error_avg += (((weight1 * x[i]) + bias) - y_actual)

        bias_gradient += (((weight1 * x[i]) + bias) - y_actual)
        weight1_gradient += (((weight1 * x[i]) + bias) - y_actual) * x[i]

    weight1 -= (learning_rate * weight1_gradient) / len(x)
    bias -= (learning_rate * bias_gradient) / len(x)

new_x = 2
print(weight1)
print(bias)
print(new_x * weight1 + bias)
