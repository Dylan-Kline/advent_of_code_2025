import pandas as pd

with open('input.txt', 'r') as f:
    text = f.read().strip()
    
raw_ranges = text.split(',')
parsed_ranges = [r.split('-') for r in raw_ranges]

invalid_ids = []
for start, end in parsed_ranges:
    for num in range(int(start), int(end)+1):
        num = str(num)
        n = len(num)
        left = 0
        for right in range(0, (n//2)):
            size = right - left
            first = num[left:right]
            second = num[right:right+size]
            
            while right < (n//2) and first == second:
                
            
print(sum(invalid_ids))