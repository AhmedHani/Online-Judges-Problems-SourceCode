___author__ = 'Ahmed Hani Ibrahim'

import math

physics_scores = str(input("Physics Scores  "))
physics_scores = list(map(lambda v: int(v), physics_scores.strip().split()))

history_scores = str(input("History Scores  "))
history_scores = list(map(lambda v: int(v), history_scores.strip().split()))

mean_physics = sum(physics_scores) / len(physics_scores)
mean_history = sum(history_scores) / len(history_scores)

numerator = sum([(a - mean_physics) * (b - mean_history) for a, b in zip(physics_scores, history_scores)])
denominator = sum([math.pow((a - mean_physics), 2) for a in physics_scores])

slope_of_regression = float(numerator) / float(denominator)

print(round(slope_of_regression, 3))
