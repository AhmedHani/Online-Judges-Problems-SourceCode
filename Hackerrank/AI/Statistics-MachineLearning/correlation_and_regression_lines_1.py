___author__ = 'Ahmed Hani Ibrahim'

import numpy as np
import math

physics_scores = str(input("Physics Scores  "))
physics_scores = list(map(lambda v: int(v), physics_scores.strip().split()))

history_scores = str(input("History Scores  "))
history_scores = list(map(lambda v: int(v), history_scores.strip().split()))


numerator = (len(physics_scores) * sum([x * y for x, y in zip(physics_scores, history_scores)])) - ((sum(physics_scores) * sum(history_scores)))
denominator = ((len(physics_scores) * sum([x * y for x, y in zip(physics_scores, physics_scores)]) - (math.pow(sum(physics_scores), 2))) * (len(physics_scores) * sum([x * y for x, y in zip(history_scores, history_scores)]) - ((math.pow(sum(history_scores), 2)))))

r = numerator / math.sqrt(denominator)

print(round(r, 3))
