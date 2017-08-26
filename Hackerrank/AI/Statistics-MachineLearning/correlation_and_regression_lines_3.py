___author__ = 'Ahmed Hani Ibrahim'

import random


physics_scores = str(input("Physics Scores  "))
physics_scores = list(map(lambda v: int(v), physics_scores.strip().split()))

history_scores = str(input("History Scores  "))
history_scores = list(map(lambda v: int(v), history_scores.strip().split()))

weight1 = 0.0
bias = 0.0

#offline learning

epochs = 10000
learning_rate = 0.01

for epoch in range(0, epochs):
    bias_gradient = 0.0
    weight1_gradient = 0.0
    error_avg = 0.0

    for i in range(0, len(physics_scores)):
        y_predicted = physics_scores[i] * weight1 + bias
        y_actual = history_scores[i]

        error_avg += (((weight1 * physics_scores[i]) + bias) - y_actual)

        bias_gradient += (((weight1 * physics_scores[i]) + bias) - y_actual)
        weight1_gradient += (((weight1 * physics_scores[i]) + bias) - y_actual) * physics_scores[i]

    weight1 -= (learning_rate * weight1_gradient) / len(physics_scores)
    bias -= (learning_rate * bias_gradient) / len(physics_scores)
    print(error_avg)

    if round(error_avg, 2) * -1.0 <= 0.1:
        break

print(weight1)
print(bias)

print(10.0 * weight1 + bias)
