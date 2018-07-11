from main import BloomFilter
from random import shuffle

n = 20  # number of items to be added
p = 0.05  # FP Probablity

bloomf = BloomFilter(n, p)
print("Size of bit array: {}" . format(bloomf.size))
print("False positive Probability: {}" . format(bloomf.fp_prob))
print("Number of hash functions: {}" . format(bloomf.hash_count))

# words to be added
word_present = ['abound', 'abounds', 'abundance', 'abundant', 'accessable',
                'bloom', 'blossom', 'bolster', 'bonny', 'bonus', 'bonuses',
                'coherent', 'cohesive', 'colorful', 'comely', 'comfort',
                'gems', 'generosity', 'generous', 'generously', 'genial']

# word not added
word_absent = ['bluff', 'cheater', 'hate', 'war', 'humanity',
               'racism', 'hurt', 'nuke', 'gloomy', 'facebook',
               'sambhav', 'twitter']

for i in word_present:
    bloomf.add(i)

shuffle(word_present)
shuffle(word_absent)

test_words = word_present[:10] + word_absent
shuffle(test_words)

for word in test_words:
    if bloomf.check(word):
        if word in word_absent:
            print("'{}' is a false positive!" . format(word))
        else:
            print("'{}' is a probably present!" . format(word))
    else:
        print("'{}' is 100% not present!" . format(word))