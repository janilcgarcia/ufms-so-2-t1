import sys
import os
import re

if len(sys.argv) < 2:
    print('Usage: get-result.py result-dir')
    exit(1)

d = sys.argv[1]

dcontents = os.listdir(d)

fifo = list(
    map(
        lambda x: os.path.join(d, x),
        filter(
            lambda x: re.match(r'^fifo-\d+$', x) != None,
            dcontents
        )
    )
)

lru = list(
    map(
        lambda x: os.path.join(d, x),
        filter(
            lambda x: re.match(r'^lru-\d+$', x) != None,
            dcontents
        )
    )
)

def get_missed(f):
    regex = re.compile(r'^Misses: (\d+)')

    with open(f) as f:
        for line in f.readlines():
            m = regex.match(line)
            if m:
                return int(m.group(1))

    raise RuntimeError('Missed value not found on this ' +
                       'result file: %s' % f)


fifo_sum = sum([get_missed(f) for f in fifo])/float(len(fifo))
lru_sum = sum([get_missed(f) for f in lru])/float(len(fifo))

print('FIFO Miss Avg: {}'.format(fifo_sum))
print('LRU Miss Avg: {}'.format(lru_sum))

