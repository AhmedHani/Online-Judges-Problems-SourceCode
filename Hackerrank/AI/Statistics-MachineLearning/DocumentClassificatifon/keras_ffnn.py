import codecs
import copy as cp
from collections import Counter
import numpy as np
import pickle
from keras.models import Sequential
from keras.layers.core import Dense, Dropout, Activation

sentences, labels = [], []
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

labels = np.asarray(labels)

with open('fofe_sent2vec.pickle', 'rb') as handle:
    sents2vec = pickle.load(handle)

print(sents2vec[0])
print(labels[0])
print(sents2vec.shape)
print(labels.shape)

model = Sequential()
model.add(Dense(1024, input_dim=sents2vec.shape[1]))
model.add(Activation('sigmoid'))
model.add(Dropout(0.4))
model.add(Dense(512))
model.add(Activation('sigmoid'))
model.add(Dropout(0.4))
model.add(Dense(labels.shape[1]))
model.add(Activation('softmax'))

model.compile(loss='categorical_crossentropy', optimizer='rmsprop', metrics=['accuracy'])

model.fit(sents2vec, labels, nb_epoch=100, batch_size=256)
