___author__ = 'Ahmed Hani Ibrahim'


data_size = int(input())
train_x, train_y = [], []

for i in range(0, data_size):
    line = str(input())

    train_x.append(int(line.strip().split()[0].split('_')[1]))
    train_y.append(int(line.strip().split()[1]))

    final_month = train_x[i]

weight1 = 0.0
bias = 1.0

#offline learning

epochs = 10000
learning_rate = 0.00001

for epoch in range(0, epochs):
    bias_gradient = 0.0
    weight1_gradient = 0.0
    error_avg = 0.0

    for i in range(0, len(train_x)):
        y_predicted = train_x[i] * weight1 + bias
        y_actual = train_y[i]

        error_avg += (((weight1 * train_x[i]) + bias) - y_actual)

        bias_gradient += (((weight1 * train_x[i]) + bias) - y_actual)
        weight1_gradient += (((weight1 * train_x[i]) + bias) - y_actual) * train_x[i]

    weight1 -= (learning_rate * weight1_gradient) / len(train_x)
    bias -= (learning_rate * bias_gradient) / len(train_x)

#print(weight1)
#print(bias)

for i in range(final_month + 1, final_month + 12):
    print(int(i * weight1 + bias))
