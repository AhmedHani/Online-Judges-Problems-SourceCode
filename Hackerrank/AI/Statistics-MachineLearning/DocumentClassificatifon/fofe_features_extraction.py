import codecs
import copy as cp
from collections import Counter
import numpy as np
import pickle

sents2vec, sentences, labels = [], [], []
unique_words = {}
idx = 0
words_freqs = {}
max_label = 0
max_sentence_length = 0
classes_freqs = {}

with codecs.open('train.txt', 'r', encoding='utf-8') as reader:
    for line in reader:
        line_tokens = line.strip().split()
        if len(line_tokens) == 1:
            continue
        max_label = max(max_label, int(line_tokens[0]))
        labels.append(int(line_tokens[0]))
        sentences.append(line_tokens[1:])
        max_sentence_length = max(max_sentence_length, len(line_tokens[1:]))

        for word in line_tokens[1:]:
            if word not in unique_words:
                unique_words[word] = idx
                idx += 1

            if word not in words_freqs:
                words_freqs[word] = 1
            else:
                words_freqs[word] += 1

        if line_tokens[0] not in classes_freqs:
            classes_freqs[line_tokens[0]] = 1
        else:
            classes_freqs[line_tokens[0]] += 1

print("Number of Classes: " + str(max_label))
print("Classes Frequencies: " + classes_freqs.items().__repr__())
print("Number of Sentences: " + str(len(sentences)))
print("Max Sentence Length: " + str(max_sentence_length))
print("Number of Unique Words: " + str(len(unique_words)))
print("Most 5 Frequent Words: " + Counter(words_freqs).most_common(20).__repr__())

## Paper: https://arxiv.org/pdf/1505.01504.pdf

classes_one_hot = [0.0] * (max_label + 1)
words_one_hot = [0.0] * len(unique_words)

for i, label in enumerate(labels):
    vec = cp.copy(classes_one_hot)
    vec[label] = 1.0
    labels[i] = vec[1:]

for item in unique_words.items():
    vec = cp.copy(words_one_hot)
    vec[item[1]] = 1.0
    unique_words[item[0]] = vec

alpha = 0.1
for sentence in sentences:
    z = np.asarray(cp.copy(words_one_hot))

    for word in sentence:
        z = alpha * z + unique_words[word]

    sents2vec.append(z)

sents2vec, labels = np.asarray(sents2vec), np.asarray(labels)

with open('fofe_sent2vec.pickle', 'wb') as handle:
    pickle.dump(sents2vec, handle, protocol=pickle.HIGHEST_PROTOCOL)
