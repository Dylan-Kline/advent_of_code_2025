import pandas as pd

with open('input.txt', 'r') as f:
    text = f.read().strip()
    
raw_ranges = text.split(',')
parsed_ranges = [r.split('-') for r in raw_ranges]

def isRepeatingSubstring(s):
    return s in (s+s)[1:-1]

invalid_ids = []
for start, end in parsed_ranges:
    for num in range(int(start), int(end)+1):
        str_num = str(num)
        if isRepeatingSubstring(str_num):
            invalid_ids.append(num)
                
print(sum(invalid_ids))